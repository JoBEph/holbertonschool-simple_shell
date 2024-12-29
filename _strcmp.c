#include "main.h"

/**
 * _strcmp - compares 2 strings.
 * @s1: 1 int
 * @s2: 2 int
 * Return: Always 0 (Success)
 */

int _strcmp(char *s1, char *s2)
{

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (s1 - s2);
}
