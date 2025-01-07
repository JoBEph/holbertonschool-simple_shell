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
	char *lineptr;
	pid_t child_pid;

	(void)argc, (void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "C is not fun $ ", 15);

		rline = getline(&lineptr, &n, stdin);

		if (rline == -1)
		{
			exit(0);
		}

		token = strtok(buffer, " \n");

		array = malloc(sizeof(char*) * 1024);
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
			exit(41);
		}

		if (child_pid == 0)
		{
			if (execve(path, array, NULL) == -1)
			{
				perror("Failed to execute");
				exit(97);
			}
		}
		else
		{
			wait(&status);
		}
	}
	free(path);
	free(buffer);
	return (0);
}

