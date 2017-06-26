#include <stdio.h>
#include "mymethods.h"


int check_for_ungetch = 0;
char temporary_buffer[BUFSIZE];

//Returns a character from console (or) from a push_back buffer

char getch(void)
{
	return (check_for_ungetch > 0) ? temporary_buffer[--check_for_ungetch] : getchar();
}

//Pushes back a read character into a pushback buffer for future use

void ungetch(int c)
{
	temporary_buffer[check_for_ungetch++] = c;
}