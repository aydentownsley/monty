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
	int idx = 0;
	size_t itr = 0;
	char *oc;
	void (*op_f) (stack_t **stack, unsigned int line_number);
	instruction_t oca[] = {
		{"stack", NULL},
		{"queue", NULL},
		{"push", push},
		{"pop", pop},
		{"swap", swap},
		{"rotl", rot_l},
		{"rotr", rot_r},
		{"pint", p_int},
		{"pall", p_all},
		{"pchr", p_char},
		{"pstr", p_str},
		{"add", add},
		{"sub", sub},
		{"mul", mul},
		{"div", div},
		{"mod", mod},
		{"nop", NULL},
		{NULL, NULL}
	};

	while (buffer[itr] != ' ' || buffer[itr] != '\n')
		itr++;
	oc = malloc((sizeof(char) * itr) + 1);
	if (oc == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
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
	}

	printf("L%u: unknown instruction %s", line_num, oc);
	free(oc);
	exit(EXIT_FAILURE);

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
