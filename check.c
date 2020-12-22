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

void hand_exit(char *buffer, stack_t **stack,
unsigned int line_number, FILE *fp)
{
	char *str = NULL;

	str = find_str(buffer);
	/*Any error message must be printed on stderr*/
	if (status == MALLOC_EXIT)
		printf("Error: malloc failed\n");
	else if (status == OP_EXIT)
		printf("L%u: unknown instruction %s\n", line_number, str);
	else if (status == OPEN_EXIT)
		printf("Error: Can't open file %s\n", str);
	else if (status == ARG_EXIT)
		printf("USAGE: monty file\n");
	else if (status ==  PUSH_INT_EXIT)
		printf("L%u: usage: push integer\n", line_number);
	else if (status == PINT_EXIT)
		printf("L%u: can't pint, stack empty\n", line_number);
	else if (status == POP_EXIT)
		printf("L%u: can't pop an empty stack\n", line_number);
	else if (status == SWAP_EXIT)
		printf("L%u: can't swap, stack too short\n", line_number);
	else if (status == ADD_EXIT)
		printf("L%u: can't add, stack too short\n", line_number);
	else if (status == SUB_EXIT)
		printf("L%u: can't sub, stack too short\n", line_number);
	else if (status == MUL_EXIT)
		printf("L%u: can't mul, stack too short\n", line_number);
	else if (status == DIV_EXIT)
		printf("L%u: can't div, stack too short\n", line_number);
	else if (status == DIV_0_EXIT)
		printf("L%u: division by zero\n", line_number);
	else if (status == MOD_EXIT)
       		printf("L%u: can't mod, stack too short\n", line_number);
	else if (status == IN_PCHAR_EXIT)
		printf("L%u: can't pchar, value out of range\n", line_number);
	else if (status == PCHAR_EXIT)
		printf("L%u: can't pchar, stack empty\n", line_number);
	fclose(fp);
	free_stack(*stack);
	free(str);
	free(buffer);
 	exit(EXIT_FAILURE);
}


char *find_str(char *buffer)
{
	int i = 0, j = 0;
	char *str;

	while (buffer[i] == ' ')
	{
		i++;
	}
	while (buffer[i + j] != ' ' && buffer[i + j] != '\n')
		j++;
	str = malloc(sizeof(char) * ((j) + 1));
	if (str == NULL)
		status = MALLOC_EXIT;
	str = strncpy(str, buffer, (j));
	return (str);

}
