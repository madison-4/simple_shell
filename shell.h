#ifndef SHELL_H
#define SHELL_H

#include<string.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<signal.h>

int _strlen(char *str);
char *_strcpy(char *src, char *dest);
char *_strcat(char *src, char *dest);
char *_strcmp(char *str1, char *str2);

#endif /* SHELL_H */
