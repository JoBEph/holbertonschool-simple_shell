#include "main.h"

/**
 * fork_and_execute - Creates a child process and executes the command.
 * @array: Array of arguments to pass to execve.
 * @path: Path to the executable.
 * 
 * Return: 0 if successful, -1 on failure.
 */
int fork_and_execute(char **array, char *path)
{
    pid_t child_pid;
    int status;

    child_pid = fork();
    if (child_pid == -1)
    {
        perror("Failed to create child process");
        return (-1);
    }

    if (child_pid == 0)
    {
        if (execve(path, array, NULL) == -1)
        {
            perror("Failed to execute command");
            return (-1);
        }
    }
    else
    {
        wait(&status);
    }

    return (0);
}
