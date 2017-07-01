#include <stdio.h>
#include "headers.h"

int str_end(char *string_a, char *string_b)
{
	match_characters(&string_a, &string_b);

	if((*string_a == '\0') && (*string_b == '\0'))
		return 1;

	return 0;
}