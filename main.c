#include "monty.h"

/**
 * get_size - gets file size of .m file
 *
 * @fd: file designator
 *
 * Return: size of file
 */

size_t get_size(FILE *fd)
{
	int total = 0;

	fseek(fd, 0, SEEK_END);
	total = ftell(fd) + 1;
	rewind(fd);
	return (total);
}

/**
 * open_and_read - open and reads .m file
 *
 * @buffer: buff
 * @file: filename
 *
 * Return: void
 */

void open_and_read(char *file)
{
	size_t file_size, rp;
	FILE *fp;

	fp = fopen(file, "r");
	if (fp == NULL)
		hand_exit(OPEN_EXIT, NULL);
	file_size = get_size(fp);
	buffer = malloc(sizeof(char) * file_size);
	if (buffer == NULL)
		hand_exit(MALLOC_EXIT, NULL);
	rp = fread(buffer, file_size, sizeof(char), fp);
	if (rp == 0)
		hand_exit(OPEN_EXIT, NULL);
}

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
	char *buffer = NULL;
	stack_t **stack = NULL;

	line_num = 0;

	if (argc != 2)
		hand_exit(ARG_EXIT, NULL);

	open_and_read(argv[1]);

	while (buffer[file_pos])
	{
		if (buffer[file_pos] == '#')
		{
			while (buffer[file_pos] != '\n')
				file_pos++;
			file_pos++;
		}
		else if (buffer[file_pos] == '\n')
		{
			line_num++;
			file_pos++;
		}
		else if (buffer[file_pos] == ' ')
		{
			while (buffer[file_pos] == ' ')
				file_pos++;
		}
		else
			check_op(stack);
	}
	return (0);
}
