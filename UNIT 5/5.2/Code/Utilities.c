#include <stdio.h>
#include <ctype.h>
#include "headers.h"


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

int skip_spaces(char *c)
{
	while(isspace(*c = getch()))
        ;     

    return 0;
}

int check_for_invalid_character(char *c)
{
	if(!isdigit(*c) && *c != '-' && *c != '+' && *c != EOF) 
    {
        printf("\n Invalid character.");                
    }
      return 0;
}

int check_for_sign(char *c,char *sign)
{
	*sign = (*c == '-')? -1 : 1;         

    if( *c == '-' || *c == '+')               
        *c = getch();

    return 0;
}

int get_characteristic(char *c, float *address)
{
    while(isdigit(*c = getch()))     
        *address = ((*address) * 10) + (*c - '0');

    return 0;
}

int get_mantissa(char *c, float *address, int *power)
{
	while(isdigit(*c = getch()))
        {
            *address = ((*address) * 10) + (*c - '0');       
            *power = *power * 10;
        }
    return 0;
}