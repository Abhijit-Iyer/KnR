#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>

#define LINESIZE 1000

void get_strings_from_user(char *, char *);
int str_cat(char *, char *);
int getline(char *);
void* replace_newline_character_with_space(char *);
void display_result(char *);

#endif