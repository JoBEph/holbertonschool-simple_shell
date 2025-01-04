#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Prototypes de function */

int _strlen(char *s);
void prompt(void);
char *readline(void);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
void execmd(char **argv);
char *strtok(char *token, const char *delim);
char *_strdup(char *str);

#endif
