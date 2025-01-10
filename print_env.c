#include "main.h"

/**
 * print_env - Loops through all environment variables and prints them
 * Return: nothing (void)
 */


void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		printf("%s\n", *env);
		env++;
	}
}
