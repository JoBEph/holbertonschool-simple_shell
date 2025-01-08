#include "main.h"

/**
 * main - function to use a simple shell command and execute
 * @argc: void (not use in this function)
 * @argv: void (not use in this function)
 *
 * Return: Success of the execution (0)
*/

int main(int argc, char **argv)
{
	char *buffer = NULL, *token, *path;
	size_t n = 0;
	ssize_t rline;
	int i, status;
	char **array;
	pid_t child_pid;

	(void)argc, (void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "C is not fun $ ", 15);
			fflush(stdout);
		}

		rline = getline(&buffer, &n, stdin);

		if (rline == -1)
		{
			free(buffer);
			exit(0);
		}

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
		path = get_file_path(array[0]);

		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Failed to create.");
			free(array);
			free(path);
			free(buffer);
			exit(41);
		}
		if (child_pid == 0)
		{
			if (execve(path, array, NULL) == -1)
			{
				perror("Failed to execute");
				free(path);
				free(array);
				free(buffer);
				exit(97);
			}
		}
		else
		{
			wait(&status);
		}
		free(path);
		free(array);
	}
	free(buffer);
	return (0);
}
