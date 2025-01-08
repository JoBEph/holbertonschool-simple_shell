#include "main.h"

/**
 * main - function to use a simple shell command and execute
 * @argc: void (not use in this function)
 * @argv: void (not use in this function)
 * Return: Success of the execution (0)
 */

int main(int argc, char **argv)
{
	char *buffer = NULL, *path;
	char *line;
	size_t n;
	char **array;
	(void)argc, (void)argv;
	while (1)
	{
		line = read_line(&line, &n);
		if (line == NULL)
			break;

		array = token_input(buffer);
		if (array == NULL)
		{
			free(buffer);
			buffer = NULL;
			continue;
		}
		if (array[0] == NULL)
		{
			_free(buffer, array, NULL);
			buffer = NULL;
			array = NULL;
			continue;
		}
		path = get_file_path(array[0]);
		if (path == NULL)
		{
			perror("Command not found");
			_free(buffer, array, path);
			buffer = NULL;
			array = NULL;
			path = NULL;
			continue;
		}
		if (fork_exe(array, path) == -1)
		{
			_free(buffer, array, path);
			exit(1);
		}
		_free(buffer, array, path);
		buffer = NULL;
		array = NULL;
		path = NULL;
	}
	free(buffer);
	return (0);
}
