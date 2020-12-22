#include "monty.h"

/**
 * main - Inturprets a monty bytecode file
 *
 * @argc: Number of arguments
 * @argv: List of arguments
 *
 * Return: 0 on success
 */

int main(int argc, char *argv[])
{
	size_t buff_size;
	char *buffer = NULL;
	stack_t **stack = NULL;
	FILE *fp;
	unsigned int i = 0, line_number = 1;
	void (*f)(stack_t **stack, unsigned int line_number);
	status = STACK;

	if (argc != 2)
	{
		status = ARG_EXIT;
		hand_exit()
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		status = OPEN_EXIT;
	buffer = malloc(sizeof(char));
	if (buffer == NULL)
			status = MALLOC_EXIT;
	if (!stack)
		stack = malloc(sizeof(stack_t *));
	*stack = NULL;
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
			if (f) /*need to check if its push so we call check int*/
			{
				if (f == push)
					check_int(buffer, stack);
				else
					f(stack, line_number);
				if (status < 16)
				{
					hand_exit(buffer, line_number, fp);
				}
				break;
			}
			else
			{
				/*error invalid op code*/
				break;
			}
		}
		line_number++;
		i = 0;
	}
	free(buffer);
	fclose(fp);
	return (0);
}
