#include "main.h"

/**
 * get_file_path - Finds the full path of the executable corresponding to the command.
 * @command: The command (without path).
 *
 * Return: The full path of the executable or NULL if not found.
 */
char *get_file_path(const char *command)
{
    char *path_env = getenv("PATH");
    char *path_copy = strdup(path_env);
    char *dir = strtok(path_copy, ":");
    char *full_path;
    
    while (dir != NULL)
    {
        full_path = malloc(strlen(dir) + strlen(command) + 2);
        if (full_path == NULL)
        {
            perror("Memory allocation failed");
            free(path_copy);
            return NULL;
        }

        strcpy(full_path, dir);
        strcat(full_path, "/");
        strcat(full_path, command);

        if (access(full_path, X_OK) == 0)
        {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        dir = strtok(NULL, ":");
    }

    free(path_copy);
    return (NULL);
}

