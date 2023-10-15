#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <dirent.h>

extern char **environ;

char *_getenv(char *name);
ssize_t _getline(char **lineptr, size_t *n, int fd);
char **splitInput(char *string);
int checkinbuilt(char **string, char *inputString);
char *fullpath(char *command_Idx);
int executeFile(char **command);
void printenv(void);
char *_strpbrk(char *s, char *accept);
char *_strtok(char *str, const char *delim);
int _strlen(char *str);
int _strcmp(char *s1, char *s2);
void interactive(void);
void non_interact(void);

#endif /*MAIN_H*/
