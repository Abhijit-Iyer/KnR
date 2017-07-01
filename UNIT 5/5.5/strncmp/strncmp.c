#include <stdio.h>
#include "headers.h"

int str_n_cmp(char *string_a, char *string_b, int n)
{
	for( ; (*string_a == *string_b) && --n ; string_a++, string_b++)
	{
		if(*string_a == '\0')
			return 0;		

		return *string_a - *string_b;
	}
}