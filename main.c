#include "monty.h"

/**
 * main - Inturprets a monty bytecode file
 *
 * @argc: Number of arguments
 * @argv: List of arguments
 *
 * Return: 0 on success
 */

int status = STACK;

int main(int argc, char *argv[])
{
	size_t buff_size = 0;
	char *buffer = NULL;
	stack_t *stack = NULL;
	FILE *fp = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		status = ARG_EXIT;
		hand_exit(buffer, &stack, 0, fp);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&buffer, &buff_size, fp) > 0)
	{
		main_help(buffer, &stack, line_number, fp);
		line_number++;
	}
	if (buffer)
		free(buffer);
	if (stack)
		free_stack(stack);
	if (fp)
		fclose(fp);
	return (0);
}

void main_help(char *buffer, stack_t **stack,
unsigned int line_number, FILE *fp)
{
	unsigned int i = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	while (buffer[i])
	{
		if (buffer[i] == ' ')
		{
			while (buffer[i] == ' ')
				i++;
			continue;
		}
		else if (buffer[i] == '#' || buffer[i] == '\n')
		{break; }
		else
		{
			f = check_op((buffer + i));
		}
		if (f)
		{
			if (f == push)
			{
				if (check_int((buffer + i), stack) == -1)
					hand_exit(buffer, stack,
line_number, fp);
			}
			else
				f(stack, line_number);
			if (status < 16)
			{
				hand_exit(buffer, stack, line_number, fp);
			}
			break;
		}
		else
		{
		status = OP_EXIT;
		hand_exit(buffer, stack, line_number, fp);
		break;
		}
	}
}
