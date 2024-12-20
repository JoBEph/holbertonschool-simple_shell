#include "main.h"

int main(int ac, char **av)
{
	char *prompt = "C is not fun $ ";
	char *lineptr;
	size_t n = 0;
	ssize_t read = 0;

	(void)ac; (void)av;

	while (1)
	{
		printf("%s", prompt);
		read = getline(&lineptr, &n, stdin);
		{
			if (read == -1)
			{
					return (-1);
			}
			printf("%s\n", lineptr);

			free(lineptr);
		}

		return (0);
	}
}
