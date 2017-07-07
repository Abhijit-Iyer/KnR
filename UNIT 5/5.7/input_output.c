#include <stdio.h>
#include "headers.h"

int line_count;

FILE *p = NULL;

int getInput(char input[])
{
	p = fopen("input.txt","r");

	while(getline(input));

	return 0;
} 

static int input_index = 0;

int getline(char input[])
{
	char ch;

	linepointers[line_count++] = &input[input_index];

	while((ch=fgetc(p)) != '\n' )
	{
		if(ch == EOF)
		{
			input[input_index++] = '\n';
			input[input_index++] = '\0';
			return 0;	
		}
		input[input_index++] = ch;
	}

	input[input_index++] = '\n';
	input[input_index++] = '\0';

	return input_index;
}


int display_output(char **linepointers)
{
	int i;

	for(i=0; i<line_count; i++)
		printf(" %s",linepointers[i]);
}