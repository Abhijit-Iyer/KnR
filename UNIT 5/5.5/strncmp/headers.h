#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>

#define LINESIZE 1000

void get_strings_from_user(char *, char *);
int str_n_cmp(char *, char *, int);
int getline(char *);
int get_copy_limit(int *);
void display_result(char *);

#endif