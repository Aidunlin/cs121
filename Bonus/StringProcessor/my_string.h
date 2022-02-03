#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

void clear_console();

char *my_fgets(char *s, int n, FILE *stream);

int my_fputs(const char *s, FILE *stream);

int my_fgetc(FILE *stream);

int my_fputc(int c, FILE *stream);

char *my_gets(char *s);

int my_puts(const char *s);

int my_getchar(void);

int my_putchar(int c);

char *my_strcpy(char *destination, const char *source);

char *my_strncpy(char *destination, const char *source, int n);

char *my_strcat(char *destination, const char *source);

char *my_strncat(char *destination, const char *source, int n);

int my_strcmp(const char *s1, const char *s2);

int my_strncmp(const char *s1, const char *s2, int n);

int my_strlen(const char *s);

#endif
