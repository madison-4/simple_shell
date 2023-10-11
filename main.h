#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* int EXIT_STATUS = 0; */
extern char **environ;

char *_getenv(char *name);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **splitInput(char *string);
int checkinbuilt(char **string);
char *fullpath(char *command_Idx);
int executeFile(char **command);

#endif /*MAIN_H*/


