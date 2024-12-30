#include "main.h"

/**
 * strtok - function to tokenize a string and put into an array
 * token - store token
 * delim - delim to separate the string to token
 * Return: array of the string separated
 */

char *strtok(char *token, const char *delim)
{
	int num_tokens = 0;
	int i;
	const char *delim = "\n";
	char *lineptr_copy = NULL;

	_strcpy(lineptr_copy, readline);

	token = strtok(readline, delim);

	while (token != NULL)
	{
		num_tokens++;
		token = strtok(NULL, delim);
	}
	num_tokens++;

	argv = malloc(sizeof(char *) * num_tokens);

	token = strtok(lineptr_copy, delim);

	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char *) *_strlen(token));
		_strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;

	free(argv);
	free(argv[i]);

	return (lineptr_copy);
}
