#ifndef HEADERS_H
#define HEADERS_H

#define MAXSIZE 1000
#define MAXLINES 100

char *linepointers[MAXLINES];
extern int line_count;

int getInput(char []);
int getline(char []);
int sort_array(char **);
int display_output(char **);

#endif