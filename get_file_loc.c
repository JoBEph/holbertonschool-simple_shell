#include "main.h"

/**
 * get_file_loc - get the executable path of the file
 * @PATH: full path variable
 * @file_name: the executable file
 * Return: full path to the executable file
*/

char *get_file_loc(char *PATH, char *file_name)
{
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = _strdup(PATH);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(_strlen(token) + _strlen(file_name) + 2);
		if (!path_buffer)
		{
			perror("Error: malloc failed");
			exit(EXIT_FAILURE);
		}
		_strcpy(path_buffer, token);
		_strcat(path_buffer, "/");
		_strcat(path_buffer, file_name);
		_strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");

	}
	free(path_copy);
	if (path_buffer)
		free(path_buffer);
	return (NULL);
}
