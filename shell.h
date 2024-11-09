#ifndef SHELL_H
#define SHELL_H

#include<fcntl.h>
#include<string.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<signal.h>

extern char **environ;

int _strlen(char *str);
char *_strcpy(char *src, char *dest);
char *_strcat(char *src, char *dest);
int _strcmp(char *str1, char *str2);
char *_strchr(char *str, char c);
unsigned int _strspn(char *str, char *accept);
char *_strpbrk(char *str, char *acc);
char *_strtok(char *str, char *delim);
void interactive_mode(int argc, char **av, char **ev);
void non_interactive(int ac, char **av, char **ev);
int prompt(void);
int _fprintf(int fd, char *str);
char *_getenv(char *name);
char *_strdup(char *st);
char **retcomm(char *);
int numprint(int arg);
int numprint(int arg);
int _putchar(char c);

typedef struct stat tree;

#endif /* SHELL_H */
