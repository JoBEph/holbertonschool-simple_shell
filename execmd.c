#include "main.h"

/**
 *execmd - create new process with fork
 *@argv: array of character poiters listing arguments
 *Return: Void
 */

void execmd(char **argv)
{
	pid_t pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(cmd[0], cmd, NULL) == -1)
		{
			perror("We found nothing");
		}
		exit(EXIT_FAILURE);
	}
}
