#include "main.h"

/**
 *execute_command - execute command.
 *@array: char
 *Return: free
 */

void execute_command(char **array)
{
	char *path = get_file_path(array[0]);
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("Failed to create.");
		_free(NULL, array, path);
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(path, array, environ) == -1)
		{
			perror("Failed to execute");
			_free(NULL, array, path);
			exit(1);
		}
	}
	else
	{
		wait(NULL);
	}
	free(path);
}
/**
 *main - main function
 *@argc: int argc
 *@argv: double pointer char
 *Return: 0
 */
int main(int argc, char **argv)
{
	char *buffer = NULL, *token, **array;
	size_t n = 0;
	ssize_t rline;
	int i;
	(void)argc, (void)argv;
	while (1)
	{	prompt();
		rline = getline(&buffer, &n, stdin);
		if (rline == -1)
		{	free(buffer);
			exit(0);
		}
		array = malloc(sizeof(char *) * 1024);
		if (array == NULL)
		{	perror("Memory allocation failed");
			free(buffer);
			exit(1);
		}
		i = 0;
		token = strtok(buffer, " \n");
		while (token)
		{	array[i++] = token;
			token = strtok(NULL, " \n");
		}
		array[i] = NULL;
		if (strcmp(array[0], "exit") == 0)
		{	free(array);
			free(buffer);
			exit(0);
		}
		if (strcmp(array[0], "env") == 0)
		{	print_env();
			free(array);
			continue;
		}
		execute_command(array);
		free(array);
	}
	free(buffer);
	return (0);
}
