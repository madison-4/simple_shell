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
#include<limits.h>

extern char **environ;

void printenv(void);
char *_strpbrk(char *s, char *accept);
char *_strtok(char *str, const char *delim);
size_t _strlen(char *str);
int _strcmp(char *s1, char *s2);
void interactive(void);
void non_interact(void);
char *read_interact(void);
int _fputchar(int fd, char c);
int _fputstr(int fd, char *str);
int _fputint(int fd, int num);
int _fprintf(int fd, const char *format, char *s1, int n1, char *s2);
int print_array(char *arr[]);
void free_array(char **array);
ssize_t _getline(char *line);

#endif /*MAIN_H*/
