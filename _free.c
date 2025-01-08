#include "main.h"

/**
 * free_resources - Frees allocated memory.
 * @buffer: The input buffer to free.
 * @array: The array of tokens to free.
 * @path: The path string to free.
 */
void _free(char *buffer, char **array, char *path)
{
	int i; 

	if (buffer != NULL)
	{
		free(buffer);
	}

	if (array != NULL)
	{
		for (i = 0; array[i] != NULL; i++)
		{
			free(array[i]);
		}
		free(array);
	}

	if (path != NULL)
	{
		free(path);
	}
}
