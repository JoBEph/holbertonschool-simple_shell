#include "main.h"

/**
 * tokenize_input - Tokenizes the input string into an array of arguments.
 * @buffer: The input string to tokenize.
 *
 * Return: A dynamically allocated array of tokens (strings), or NULL if allocation fails.
 */
char **tokenize_input(char *buffer)
{
    char *token;
    int i = 0;
    char **array;

    array = malloc(sizeof(char *) * 1024);
    if (array == NULL)
    {
        perror("Memory allocation failed");
        return NULL;
    }

    token = strtok(buffer, " \n");
    while (token != NULL)
    {
        array[i] = token;
        i++;
        token = strtok(NULL, " \n");
    }

    array[i] = NULL;

    return (array);
}

