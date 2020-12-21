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
	unsigned int i, line_number = 0;
	void (*f)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		hand_exit(ARG_EXIT, NULL);

	fp = fopen(file, "r");
	if (fp == NULL)
		hand_exit(OPEN_EXIT, NULL, line_number, buffer);
	buffer = malloc(sizeof(char));
	if (buffer == NULL)
		hand_exit(MALLOC_EXIT, NULL, line_number, buffer);
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
				f = check_op(stack, line_number, (buffer + i));
			if (f) /*need to check if its push so we call check int*/
				f(stack, line_number);
		}
		line_number++;
	}
	fclose(fp)
	return (0);
}
