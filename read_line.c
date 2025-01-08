#include "main.h"

/**
 * read_line - function to read and input command
 * @rline: line command to read
 * @buffer: array of the string
 * Return: the line command success
 */

char *read_line(char **rline, size_t *buffer)
{

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "C is not fun $ ", 15);
		fflush(stdout);
	}

	if (getline(rline, buffer, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(*rline);
			exit(EXIT_SUCCESS);
		}
		else
		{
			free(*rline);
			perror("Error line from stdin");
			exit(EXIT_FAILURE);
		}
	}
	return (*rline);
}
