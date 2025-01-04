#include "main.h"

/**
 * _strdup - pointer to a newly allocated space in memory
 * @str: pointer
 * Return: x
*/

char *_strdup(char *str)
{
	char *x;
	int y = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[y] != '\0')
	{
		y++;
	}

	x = malloc((y + 1) * sizeof(char));

	if (x == NULL)
	{
		return (NULL);
	}
	for (y = 0; str[y] != '\0'; y++)
	{
		x[y] = str[y];
	}
	x[y] = '\0';

	return (x);
}
