#include "main.h"

/**
 * fork_exe - function to process child and parent
 * @args: array of strings that contains the command and flags
 * @path: path env
 * Return: Success of the process (1)
 */

int fork_exe(char **array, char *path)
{
	int status;
	pid_t child_pid;

	child_pid = fork();

	if (child_pid == -1)
	{
		perror("Failed to create.");
		free(array);
		free(path);
		exit(41);
	}
	if (child_pid == 0)
	{
		if (execve(path, array, NULL) == -1)
		{
			perror("Failed to execute.");
			free(path);
			free(array);
			exit(97);
		}
	}
	else
	{
		wait(&status);
	}
	free(path);
	free(array);

	return (0);
}
