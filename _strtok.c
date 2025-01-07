#include "main.h"

/**
 * strtok - function to tokenize a string and put into an array
 * @token: store token
 * @delim: delim to separate the string to token
 * Return: array of the string separated
 */

char *strtok(const char *delim)
{
	int num_tokens = 0;
	int i;
	char *token;
	char *lineptr_copy;
	char **argv;

	char *readline_input = readline();
	if (readline_input == NULL)
	{
		return (NULL);
	}
	lineptr_copy = _strdup(readline_input);

	if (lineptr_copy == NULL)
	{
		free(readline_input);
		return (NULL);
	}
	token = strtok(lineptr_copy, delim);
	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	argv = malloc(sizeof(char *) * (num_tokens + 1));
	if (argv == NULL)
	{
		free(lineptr_copy);
		free(readline_input);
		return (NULL);
	}

	token = strtok(readline_input, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(_strlen(token)+ 1);
		if (argv[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(argv[j]);
			}

			free(argv);
			free(lineptr_copy);
			free(readline_input);
			return (NULL);
		}
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(lineptr_copy);
	free(readline_input);
	return (argv);
}
int main(void)
{
	const char *delim = " ";
	char **tokens = strtok(delim);

	if (tokens != NULL)
	{
		for (int i = 0; tokens[i] != NULL; i++)
		{
			printf("Token %d: %s\n", i, tokens[i]);
			free(tokens[i]);
		}
	}
	return (0);
}
