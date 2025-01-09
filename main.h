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

/* Prototypes de function */

int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcat(char *dest, char *src);
char *get_file_loc(char *PATH, char *file_name);
char *get_file_path(char *file_name);
int slash(const char *str);
int _error(void);
int main(int argc, char **argv);
char *_getenv(const char *name);

#endif
