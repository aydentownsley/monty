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
		hand_exit(OPEN_EXIT, NULL);
	file_size = get_size(fd);
	buffer = malloc(sizeof(char) * file_size);
	if (buffer == NULL)
		hand_exit(MALLOC_EXIT, NULL);
	rd = read(fd, buffer, file_size);
	if (rd == -1)
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
	char *buffer;
	long unsigned int i = 0;

	line_num = 0;

	if (argc != 2)
		hand_exit(ARG_EXIT, NULL);

	open_and_read(buffer, argv[1]);

	while (buffer[file_pos])
	{
		if (buffer[file_pos] == '#')
		{
			while (buffer != '\n')
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
			check_op();
	}
	return (0);
}
