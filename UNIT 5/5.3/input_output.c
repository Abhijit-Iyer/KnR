#include <stdio.h>
#include "headers.h"

void get_strings_from_user(char *string_a, char *string_b)
{
	printf("\n Enter the first string : ");
	getline(string_a);

	printf("\n Enter the string to be concatinated : ");
	getline(string_b);
}

void display_result(char *string_a)
{
	while(*string_a != '\0')
		putchar(*string_a++);		
}