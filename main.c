#include "monty.h"

/**
 * get_size - gets file size of .m file
 *
 * @fd: file designator
 *
 * Return: size of file
 */

size_t get_size(int fd)
{
	int total = 0;

	fseek(fp, 0, SEEK_END);
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

void open_and_read(char *buffer, char *file)
{
	size_t file_size;
	int fd, rd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	file_size = get_size(fd);
	buffer = malloc(sizeof(char) * file_size);
	if (buffer == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	rd = read(fd, buffer, file_size);
	if (rd == -1)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
}
/**
 * main -
 *
 * @argc:
 * @argv:
 *
 * Return:
 */

int main(int argc, char *argv[])
{
	char *buffer;
	long unsigned int i = 0;

	line_num = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	open_and_read(buffer, argv[1]);

	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			while (buffer != '\n')
				i++;
			i++;
		}
		else if (buffer[i] == '\n')
		{
			line_num++;
			i++;
		}
		else if (buffer[i] == ' ')
		{
			while (buffer[i] == ' ')
				i++;
		}
		else
			
	}
}
