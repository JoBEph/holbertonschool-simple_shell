#include "main.h"

/**
 * prompt - function to put the prompt simple shell
 * Return: nothing (void)
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{	
		write(STDOUT_FILENO, "C is not fun $ ", 15);
		fflush(stdout);
	}
}
