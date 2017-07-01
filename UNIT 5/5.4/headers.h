#ifndef HEADERS_H
#define HEADERS_H

#include <stdio.h>

#define LINESIZE 1000

void get_strings_from_user(char *, char *);
int str_end(char *, char *);
int getline(char *);
void display_result();
void match_characters(char **, char **);

#endif