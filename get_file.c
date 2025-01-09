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
 * get_path - get the executable path of the file
 * @file_name: the executable file
 * Return: NULL
 */

char *get_path(char *file_name)
{
	char *path_copy, *token, *temp_path, *full_path = NULL;
	size_t path_len, file_len, total_len;
	char *path = _getenv("PATH");

	if (!file_name || file_name[0] == '\0')
		return (NULL);
	if (strchr(file_name, '/') && access(file_name, X_OK) == 0)
		return (strdup(file_name));
	if (!path)
	{	fprintf(stderr, "%s: PATH environnement variable not set\n", file_name);
		return (NULL);
	}
	file_len = strlen(file_name);
	path_copy = strdup(path);
	if (!path_copy)
	{	perror("strdup");
		return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token)
	{	path_len = strlen(token);
		total_len = path_len + file_len + 2;
		temp_path = malloc(total_len);
		if (!temp_path)
		{	perror("malloc");
			free(path_copy);
			free(full_path);
			return (NULL);
		}
		snprintf(temp_path, total_len, "%s/%s", token, file_name);
		if (access(temp_path, X_OK) == 0)
		{	free(path_copy);
			return (temp_path);
		}
		free(temp_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	fprintf(stderr, "%s: command not found\n", file_name);
	return (NULL);
}
