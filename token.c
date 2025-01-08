#include "main.h"

/**
 * token - function tokenise input command
 * @buffer:
 * Return: array
 */

char **token_input(char *buffer)
{
	char *token;
	int i;
	char **array;

	token = strtok(buffer, " \n");

	array = malloc(sizeof(char *) * 1024);
	if (array == NULL)
	{
		perror("Memory allocation failed");
		free(buffer);
		exit(1);
	}

	i = 0;
	while (token)
	{
		array[i] = token;
		token = strtok(NULL, " \n");
		i++;
	}

	array[i] = NULL;
	return (array);
}
