#include "monty.h"

/**
 * get_size - gets file size of .m file
 *
 * @fd: file designator
 * @

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
	int fd, rd;
	char *buffer[1024];

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}
