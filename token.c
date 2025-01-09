#include "main.h"

/**
 * _token - Tokenizes a string and returns an array of tokens.
 * @buffer: The string to tokenize.
 *
 * Return: A dynamically allocated array of strings containing tokens.
 */
char **_token(char *buffer)
{
	char *token;
	char **array = malloc(sizeof(char *) * 1024);
	int i = 0;

	if (array == NULL)
	{
		perror("Memory allocation failed")
			return (NULL);
	}

	token = strtok(buffer, " \n");
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}
	array[i] = NULL;

	return (array);
}

