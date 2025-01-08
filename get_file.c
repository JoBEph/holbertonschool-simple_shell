#include "main.h"

/**
 * slash - check if the file starts with slash
 * @str: the filename to be checked
 * Return: 1 if yes or 0 if no
*/

int slash(const char *str)
{
	if (str != NULL && str[0] == '/')
		return (1);
	return (0);
}

/**
 * get_file_loc - get the executable path of the file
 * @PATH: full path variable
 * @file_name: the executable file
 * Return: full path to the executable file
*/

char *get_file_loc(char *path, char *file_name)
{
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = _strdup(path);
	if (path_copy == NULL)
	{
		perror("Error: strdup failed");
		return (NULL);
	}

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
			free(path_copy);
			return (NULL);
		}
		_strcpy(path_buffer, token);
		_strcat(path_buffer, "/");
		_strcat(path_buffer, file_name);

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

/**
 * get_file_path - get the full path of the file
 * @file_name: Argument name
 * Return: the fulle path argument to the file
*/

char *get_file_path(char *file_name)
{
	char *path = getenv("PATH");
	char *full_path;

	if (slash(file_name) && access(file_name, X_OK) == 0)
		return (_strdup(file_name));

	if (!path)
	{
		perror("Path not found");
		return (NULL);
	}
	full_path = get_file_loc(path, file_name);

	if (full_path == NULL)
	{
		write(2, file_name, _strlen(file_name));
		write(2, ": command not found\n", 19);
		return (NULL);
	}
	return (full_path);
}
