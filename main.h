#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>

/* Prototypes de function */

char *get_file_loc(char *PATH, char *file_name);
char *get_file_path(char *file_name);
int slash(const char *str);
int main(int argc, char **argv);
int fork_exe(char **array, char *path);
char **token_input(char *buffer);
void _free(char *buffer, char **array, char *path);
char *read_line(char **rline, size_t *buffer);

#endif
