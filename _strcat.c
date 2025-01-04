#include "main.h"

/**
 * _strcat - function that concatenates two strings
 * @dest: pointer
 * @src: pointer
 * Return: Always 0 (Success)
*/

char *_strcat(char *dest, char *src)
{
	while (*dest)
	{
		dest++;
	}
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}
