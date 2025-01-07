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
    char *buffer = NULL, *path;
    size_t n = 0;
    ssize_t rline;
    char **array;

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
            exit(0);
        }
        array = tokenize_input(buffer);

        if (array == NULL)
        {
            free(buffer);
            continue;
        }

        path = get_file_path(array[0]);

        if (path == NULL)
        {
            perror("Command not found");
            free_resources(buffer, array, path);
            continue;
        }
        if (fork_and_execute(array, path) == -1)
        {
            free_resources(buffer, array, path);
            exit(1);
        }

        free_resources(buffer, array, path);
    }

    free(buffer);
    return (0);
}
