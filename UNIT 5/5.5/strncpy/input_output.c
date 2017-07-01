#include <stdio.h>
#include "headers.h"

void get_strings_from_user(char *string_a, char *string_b)
{
	printf("\n Enter the string to be copied : ");
	getline(string_b);
}

int get_copy_limit(int *n)
{
	printf("\n Enter the limit upto which you'd like to copy : ");
	scanf("%d",n);
}

void display_result(char *string_a)
{
	printf("\n Copied String : %s",string_a);		
}