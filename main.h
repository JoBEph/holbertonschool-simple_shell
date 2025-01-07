#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char *get_file_path(const char *command);
void execute_command(char **array);
void free_resources(char *buffer, char **array, char *path);
int fork_and_execute(char **array, char *path);
char **tokenize_input(char *buffer);

#endif

