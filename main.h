#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/* Prototypes functions commands */

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);

/* Prototypes functions execution */

char *get_path(char *file_name);
int slash(const char *str);
int _error(void);
int main(int argc, char **argv);
char *_getenv(const char *name);
void _free(char *buffer, char **array, char *path);
void execute_command(char **array);
void print_env(void);
void prompt(void);

#endif
