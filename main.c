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
	unsigned int i = 0, line_number = 1;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		status = ARG_EXIT;
		hand_exit(buffer, &stack, 0, fp);
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		status = OPEN_EXIT;
		hand_exit(buffer, &stack, line_number, fp);
	}
/*	buffer = malloc(sizeof(char)); getline mallocs for us */
	if (buffer == NULL)
	{
		hand_exit(buffer, &stack, line_number, fp);
		status = MALLOC_EXIT;
	}
	while (0 < getline(&buffer, &buff_size, fp))
	{
		while (buffer[i])
		{
			if (buffer[i] == ' ')
			{
				while (buffer[i] == ' ')
					i++;
			}
			else if (buffer[i] == '#' || buffer[i] == '\n')
				break;
			else
			{
				f = check_op((buffer + i));
			}
			if (f)
			{
				if (f == push)
					check_int(buffer, &stack);
				else
					f(&stack, line_number);
				if (status < 16)
					hand_exit(buffer, &stack,
line_number, fp);
				break;
			}
			else
			{
				status = OP_EXIT;
				hand_exit(buffer, &stack, line_number, fp);
				break;
			}
		}
		line_number++;
		i = 0;
	}
	free(buffer);
	free_stack(stack);
	fclose(fp);
	return (0);
}
