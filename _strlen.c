#include "main.h"

/**
 * _strlen - function for the lenght of the string
 * @s: character pointer of the lenght
 * Return: lenght (Success)
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
