#include "main.h"

/**
 * _strlen - function to string
 * @s: character pointer
 * Return: len
*/

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}
