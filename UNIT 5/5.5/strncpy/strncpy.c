#include <stdio.h>
#include "headers.h"

int str_n_cpy(char *string_a, char *string_b, int n)
{
	while((*string_a++ = *string_b++) != '\0' && --n )
		;

	*string_a = '\0';
}