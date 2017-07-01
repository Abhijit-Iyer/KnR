#include <stdio.h>
#include "headers.h"

void main()
{
	char string_a[LINESIZE], string_b[LINESIZE];
	int n;

	get_strings_from_user(string_a, string_b);

	get_copy_limit(&n);

	if(!str_n_cmp(string_a, string_b, n))
		display_result(string_a);
	else
		printf("\n The strings do not match upto the prescribed limit. ");

}