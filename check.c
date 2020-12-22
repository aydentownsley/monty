#include "monty.h"

/**
 * check_op - checks for opcode
 *
 * @buffer: Location in line to check for opcode
 *
 * Return: length of opcode, on fail return 1
 * ''needed to advance buffer correctly
 */

void (*check_op(char *buffer))(stack_t **stack, unsigned int line_number)
{
	int itr = 0, idx = 0;
	char *oc;
	void (*op_f)(stack_t **stack, unsigned int line_number);
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
	oc[itr] = '\0';
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
	return (op_f);
}

/**
 * check_int - checks for a number represended by a string after a " "
 *
 * @stack: head of stack/queue
 * @buffer: string of text on current line
 *
 * Return: int containted in string
 */

int check_int(char *buffer, stack_t **stack)
{
	unsigned int i = 0, se = 0; /*se == end of string */
	char *number;
	int num = 0;

	while (!(isdigit(buffer[i])) && buffer[i] != '-' && buffer[i] != '\n')
		i;
	if (buffer[i] == '0')
	{
		if (status == STACK)
			add_begin(stack, num);
		else if (status == QUEUE)
			add_end(stack, num);
		return (0);
	}
	else
	{
		while (isdigit(buffer[i + se]) || buffer[i + se] == '-')
			se++;
		number = malloc((sizeof(char) * se) + 2);
		if (number == NULL)
		{
			status = MALLOC_EXIT;
			return (-1);
		}
		strncpy(number, (buffer + i), se + 1);
		number[se + 1] = '\0';
		num = atoi(number);
		if (num == 0)
		{
			status = PUSH_INT_EXIT;
			return (-1);
		}
		free(number);
		if (status == STACK)
		{
			add_begin(stack, num);
		}
		else if (status == QUEUE)
			add_end(stack, num);
		return (0);
	}
	status = OP_EXIT;
	return (-1);
}

/**
 * hand_exit - takes a exit macro and string then prints message and exits
 *
 * @buffer: buffer holding commands
 * @stack: head of stack/queue
 * @line_number: line of monty file
 * @fp: file pointer
 *
 * Return: none
 */

void hand_exit(char *buffer, stack_t **stack, unsigned int line_number,
FILE *fp)
{
	char *str;

	if (buffer)
		str = find_str(buffer);
	if (status == MALLOC_EXIT)
		fprintf(stderr, "Error: malloc failed\n");
	else if (status == OP_EXIT)
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, str);
	else if (status == OPEN_EXIT)
		fprintf(stderr, "Error: Can't open file %s\n", str);
	else if (status == ARG_EXIT)
		fprintf(stderr, "USAGE: monty file\n");
	else if (status ==  PUSH_INT_EXIT)
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
	else if (status == PINT_EXIT)
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
	else if (status == POP_EXIT)
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
	else if (status == SWAP_EXIT)
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
	else if (status == ADD_EXIT)
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
	else if (status == SUB_EXIT)
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
	else if (status == MUL_EXIT)
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
	else if (status == DIV_EXIT)
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	else if (status == DIV_0_EXIT)
		fprintf(stderr, "L%u: division by zero\n", line_number);
	else if (status == MOD_EXIT)
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
	else if (status == IN_PCHAR_EXIT)
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
	else if (status == PCHAR_EXIT)
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
	if (fp)
		fclose(fp);
	if (stack)
		free_stack(*stack);
	if (str)
		free(str);
	if (buffer)
		free(buffer);
	exit(EXIT_FAILURE);
}

/**
 * find_str - find string in buffer
 *
 * @buffer: buffer holding commands
 *
 * Return: return string
 */

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
