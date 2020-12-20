#include "monty.h"

/**
 * check_op -
 *
 * @buffer:
 *
 * Return: length of opcode
 * ''needed to advance buffer correctly
 */

int check_op(char *buffer)
{
	int itr = 0, idx = 0;
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
		return (itr);
	}
	else if (buffer[itr + 1] == ' ' || buffer[itr + 1] == '\n')
	{
		return ((int) null_comp(oc));
	}
	hand_exit(OP_EXIT, oc);
}

/**
 * null_comp - checks the null function pointers
 *
 * @oc: opcode
 *
 * Return: size of opcode
 */

size_t null_comp(char *oc)
{
		if (strcmp(oc, "nop"))
		{
			free(oc);
			return (strlen(oc));
		}
		else if (strcmp(oc, "stack"))
		{
			stack_queue = STACK;
			free(oc);
			return (strlen(oc));
		}
		else if (strcmp(oc, "queue"))
		{
			stack_queue = QUEUE;
			free(oc);
			return (strlen(oc));
		}
		else
		{
			free(oc);
			return (1);
		}
}


/**
 * check_int -
 *
 * @
 *
 * Return:
 */

/**
 * hand_exit -
 *
 * @
 *
 * Return:
 */

void hand_exit(int ex, char *str)
{
	switch (ex) {
	case 0:
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	case 1:
		printf("L%u: unknown instruction %s", line_num, str);
		free(str);
		exit(EXIT_STATUS);
	case 2:
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	case 3:
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	case 4:
		printf("L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	case 5:
		printf("L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	case 6:
		printf("L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	case 7:
		printf("L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case 8:
		printf("L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case 9:
		printf("L%u: can't sub, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case 10:
		printf("L%u: can't div, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	case 11:
		printf("L%u: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	case 12:
       		printf("L%u: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	case 13:
		printf("L%u: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	case 14:
		printf("L%u: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	case 15:
		printf("\n", line_num);
		exit(EXIT_FAILURE);
}
