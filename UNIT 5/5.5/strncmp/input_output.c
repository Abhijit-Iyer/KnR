#include <stdio.h>
#include "headers.h"

void get_strings_from_user(char *string_a, char *string_b)
{
	printf("\n Enter the first string : ");
	getline(string_a);

	printf("\n Enter the second string : ");
	getline(string_b);
}

int get_copy_limit(int *n)
{
	printf("\n Enter the limit upto which you'd like to compare : ");
	scanf("%d",n);
}

void display_result(char *string_a)
{
	printf("\n The strings are equal upto the prescribed limit. ");	
}