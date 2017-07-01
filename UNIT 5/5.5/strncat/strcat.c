#include <stdio.h>
#include "headers.h"

int str_cat(char *string_a, char *string_b, int n)
{
	while(*string_a++ != '\0')
		;

	string_a = replace_newline_character_with_space(string_a);

	while(( (*string_a++ = *string_b++) != '\0') && --n )
		;

	return 0;
}