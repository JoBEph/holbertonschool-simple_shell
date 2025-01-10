#include "main.h"

/**
 * _strcpy - function that copies the string pointed
 * @dest: pointer of the string copy
 * @src: pointer of the first string
 * Return: the string copied (Success)
 */

char *_strcpy(char *dest, char *src)
{
	int x = 0;

	while (src[x] != '\0')
	{
		dest[x] = src[x];
		x++;
	}	
	dest[x] = '\0';
	return (dest);
}

