#include "main.h"

/**
 *_getenv - Search in environement variable specific variable name.
 *@name: Env variable
 *Return: NULL
 *
 */

char *_getenv(char *name)
{
	int index = 0;

	while (environ[index])
	{
		if (strncmp(environ[index], name, strlen(name)) == 0)
			return (environ[index] + (strlen(name) + 1));
		++index;
	}
	return (NULL);
}
