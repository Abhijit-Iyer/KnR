#include <stdio.h>
#include "headers.h"

void main()
{
	char string_a[LINESIZE], string_b[LINESIZE];

	get_strings_from_user(string_a, string_b);

	str_cat(string_a, string_b);

	display_result(string_a);

}