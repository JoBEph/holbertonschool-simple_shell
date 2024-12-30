#include "main.h"

/**
 * _error - function to output an error message
 *
 * Return: an exit failure
*/

int _error(void)
{
	perror("./hsh - not found");
	return (EXIT_FAILURE);
}
