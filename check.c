#include "monty.h"

/**
 * check_op - checks for opcode
 *
 * @buffer: Location in line to check for opcode
 *
 * Return: length of opcode, on fail return 1
 * ''needed to advance buffer correctly
 */

void (*check_op(char *buffer))
(stack_t **stack, unsigned int line_number)
{
	int itr = 0, idx = 0;
	char *oc;
	void (*op_f) (stack_t **stack, unsigned int line_number);
	instruction_t oca[] = {
		{"stack", stackf}, {"queue", queue}, {"push", push},
		{"pop", pop}, {"swap", swap}, {"rotl", rot_l},
		{"rotr", rot_r}, {"pint", p_int}, {"pall", p_all},
		{"pchr", p_char}, {"pstr", p_str}, {"add", add},
		{"sub", sub}, {"mul", mul}, {"div", divi}, {"mod", mod},
		{"nop", nop}, {NULL, NULL}
	};

	while (buffer[itr] != ' ' && buffer[itr] != '\n')
	{
		itr++;
	}
	oc = malloc((sizeof(char) * itr) + 1);
	if (oc == NULL)
		status = MALLOC_EXIT;
	oc = strncpy(oc, buffer, itr);
	while (oca[idx].opcode)
	{
		if (!strcmp(oca[idx].opcode, oc))
		{
			op_f = oca[idx].f;
			break;
		}
		idx++;
	}
	if (oca[idx].f == NULL)
		op_f = NULL;
	free(oc);
	return op_f;
}

/**
 * check_int - checks for a number represended by a string after a " "
 *
 * @line_number: the current line number
 * @buffer: string of text on current line
 *
 * Return: int containted in string
 */

int check_int(char *buffer, stack_t **stack)
{
	unsigned int itr = 0, se = 0; /*se == end of string */
	char *number;
	int num = 0;

	while (!(buffer[itr] >= '0' && buffer[itr] <= '9') &&
buffer[itr] != '-' && buffer[itr] != '\n')
			itr++;
	if(buffer[itr] == '0')
	{
		if (status == STACK)
			add_begin(stack, num);
		else if (status == QUEUE)
			add_end(stack, num);
		return(0);
	}
	else
	{
		while ((buffer[itr + se] >= '0' && buffer[itr + se] <= '9')
|| buffer[itr + se] == '-')
		      se++;
		number = malloc((sizeof(char) * se) + 1);
		if (number == NULL)
		{
			status = MALLOC_EXIT;
			return (-1);
		}
		strncpy(number, (buffer + itr), se + 2);
		num = atoi(number);
		if (num == 0)
			return (-1);
		free(number);
		if (status == STACK)
		{
			add_begin(stack, num);
		}
		else if (status == QUEUE)
			add_end(stack, num);
		return(0);
	}
	status = OP_EXIT;
	return (-1);
}

/**
 * hand_exit - takes a exit macro and string then prints message and exits
 *
 * @ex: exit macro to decide message
 * @str: string that caused the error
 * @line_number:
 *
 * Return: none
 */

void hand_exit(char *buffer, unsigned int line_number, FILE *fp)
{
	char *str = NULL;

	/*Any error message must be printed on stderr*/
	switch (status) {
	case MALLOC_EXIT:
		printf("Error: malloc failed\n");
	case OP_EXIT:
		printf("L%u: unknown instruction %s", line_number, str);
	case OPEN_EXIT:
		printf("Error: Can't open file %s\n", str);
	case ARG_EXIT:
		printf("USAGE: monty file\n");
	case PUSH_INT_EXIT:
		printf("L%u: usage: push integer\n", line_number);
	case PINT_EXIT:
		printf("L%u: can't pint, stack empty\n", line_number);
	case POP_EXIT:
		printf("L%u: can't pop an empty stack\n", line_number);
	case SWAP_EXIT:
		printf("L%u: can't swap, stack too short\n", line_number);
	case ADD_EXIT:
		printf("L%u: can't add, stack too short\n", line_number);
	case SUB_EXIT:
		printf("L%u: can't sub, stack too short\n", line_number);
	case MUL_EXIT:
		printf("L%u: can't mul, stack too short\n", line_number);
	case DIV_EXIT:
		printf("L%u: can't div, stack too short\n", line_number);
	case DIV_0_EXIT:
		printf("L%u: division by zero\n", line_number);
	case MOD_EXIT:
       		printf("L%u: can't mod, stack too short\n", line_number);
	case IN_PCHAR_EXIT:
		printf("L%u: can't pchar, value out of range\n", line_number);
	case PCHAR_EXIT:
		printf("L%u: can't pchar, stack empty\n", line_number);
	}
	free(fp);
	free(buffer);
 	exit(EXIT_FAILURE);
}
