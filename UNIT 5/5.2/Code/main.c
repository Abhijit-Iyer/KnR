#include <stdio.h>
#include "headers.h"

void main()
{
	float buffer[BUFSIZE];
	int maxsize;

	get_maxsize(&maxsize);
 	prompt_user_to_enter_array_elements();
	process_input_and_convert_to_float(buffer ,maxsize);
	display_array(buffer,maxsize);
}