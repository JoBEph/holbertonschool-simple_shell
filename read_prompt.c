#include "main.h"

/**
 * prompt - function to command invit
 * Return: nothing (void)
 */

void prompt(void)
{
	char *prompt = "C is not fun $:";
	char *lineptr = getcwd(NULL, 0);

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
	}
	free(lineptr);
}

/**
 * read - read line user
 * Return: line user
 */

char *readline(void)
{
	char *lineptr;
	ssize_t rline;
	size_t n = 0;
	int i;

	rline = getline(&lineptr, &n, stdin);

	if (!lineptr)
	{
		perror("Error allocating memory for buffer");
		return (0);
	}
	if (rline == 1)
	{
		free(lineptr);
		return (NULL);
	}
	else if (rline == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(lineptr);
		exit(0);
	}
	else
	{
		for (i = 0; lineptr[i] == ' ' && lineptr[i + 1] == ' ' ; i++)
			if (!lineptr[i] && lineptr[i + 1] == '\n')
			{
				free(lineptr);
				return (0);
			}
	}
	return (lineptr);
}
