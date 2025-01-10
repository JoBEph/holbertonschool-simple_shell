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
 * @path: full path variable
 * @file_name: the executable file
 * Return: NULL
 */

char *get_file_loc(char *path, char *file_name)
{
	char *path_copy = NULL, *token = NULL;
	struct stat file_path;
	char *path_buffer = NULL;
	size_t path_len, file_len;

	if (!path || !file_name)
		return (NULL);

	path_copy = strdup(path);
	if (!path_copy)
	{
		perror("Error: strdup failed");
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token)
	{
		path_len = strlen(token);
		file_len = strlen(file_name);
		path_buffer = realloc(path_buffer, path_len + file_len + 2);
		if (!path_buffer)
		{
			perror("Error: realloc failed");
			free(path_copy);
			return (NULL);
		}
		_strcpy(path_buffer, token);
		path_buffer[path_len] = '/';
		_strcpy(path_buffer + path_len + 1, file_name);
		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
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
	char *path = _getenv("PATH");
	char *full_path;

	if (slash(file_name) && access(file_name, X_OK) == 0)
		return (strdup(file_name));

	if (!path)
	{
		perror("Path not found");
		return (NULL);
	}
	full_path = get_file_loc(path, file_name);

	if (full_path == NULL)
	{
		write(2, file_name, strlen(file_name));
		write(2, ": command not found\n", 19);
		return (NULL);
	}
	return (full_path);
}
