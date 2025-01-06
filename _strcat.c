#include "main.h"

/**
 * _strcat - function that concatenate two strings
 * @dest: pointer first string
 * @src: pointervsecond string
 * Return: the new string (Success)
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
