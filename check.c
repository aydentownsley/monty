#include "monty.h"

/**
 * check_op - checks for opcode
 *
 * @buffer: Location in line to check for opcode
 *
 * Return: length of opcode, on fail return 1
 * ''needed to advance buffer correctly
 */

void check_op(void)
{
	int itr = file_pos, idx = 0;
	char *oc;
	void (*op_f) (stack_t **stack, unsigned int line_number);
	instruction_t oca[] = {
		{"stack", NULL}, {"queue", NULL}, {"push", push},
		{"pop", pop}, {"swap", swap}, {"rotl", rot_l},
		{"rotr", rot_r}, {"pint", p_int}, {"pall", p_all},
		{"pchr", p_char}, {"pstr", p_str}, {"add", add},
		{"sub", sub}, {"mul", mul}, {"div", div}, {"mod", mod},
		{"nop", NULL},	{NULL, NULL}
	};

	while (buffer[itr] != ' ' || buffer[itr] != '\n')
		itr++;
	oc = malloc((sizeof(char) * itr) + 1);
	if (oc == NULL)
		hand_exit(MALLOC_EXIT, NULL);
	oc = strncpy(oc, buffer, itr);
	while (oca[idx].opcode)
	{
		if (strcmp(oca[idx].opcode, oc))
			if (buffer[itr + 1] == ' ' || buffer[itr + 1] == '\n')
				op_f = oca[idx].f;
		idx++;
	}
	if (op_f)
	{
		free(oc);
		op_f(*head, line_num);
		file_pos += itr;
		return;
	}
	else if (buffer[itr + 1] == ' ' || buffer[itr + 1] == '\n')
	{
		null_comp(oc));
		return;
	}
	hand_exit(OP_EXIT, oc);
}

/**
 * null_comp - checks the null function pointers
 *
 * @oc: opcode
 *
 * Return: size of opcode, 1 on fail
 */

void null_comp(char *oc)
{
		if (strcmp(oc, "nop"))
		{
			free(oc);
			file_pos += (strlen(oc));
		}
		else if (strcmp(oc, "stack"))
		{
			stack_queue = STACK;
			free(oc);
			file_pos += (strlen(oc));
		}
		else if (strcmp(oc, "queue"))
		{
			stack_queue = QUEUE;
			free(oc);
			file_pos += (strlen(oc));
		}
		else
			free(oc);
		return
}


/**
 * check_int -
 *
 * @
 *
 * Return:
 */


/**
 * hand_exit - takes a exit macro and string then prints message and exits
 *
 * @ex: exit macro to decide message
 * @str: string that caused the error
 *
 * Return: none
 */

void hand_exit(int ex, char *str)
{
	switch (ex) {
	case MALLOC_EXIT:
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case OP_EXIT:
		printf("L%u: unknown instruction %s", line_num, str);
		free(str);
		exit(EXIT_STATUS);
	case OPEN_EXIT:
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	case ARG_EXIT:
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case PUSH_INT_EXIT:
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	case PINT_EXIT:
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	case POP_EIXT:
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	case SWAP_EXIT:
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case ADD_EXIT:
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case SUB_EXIT:
		printf("L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case MULL_EXIT:
		printf("L%u: can't mul, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case DIV_EXIT:
		printf("L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case DIV_0_EXIT:
		printf("L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	case MOD_DEXIT:
       		printf("L%u: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	case IN_PCHAR_EXIT:
		printf("L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	case PCHAR_EXIT:
		printf("L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
}
