#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int line_count = 0;

void main()
{
	char input_buffer[MAXSIZE];

	system("cls");

	getInput(input_buffer);

	printf("\n\n BEFORE SORT : \n\n");

	display_output(linepointers);	

	sort_array(linepointers);

	printf("\n\n AFTER SORT : \n\n");

	display_output(linepointers);	
}