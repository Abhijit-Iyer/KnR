#include <stdio.h>
#include "headers.h"

int getline(char line[])
{
	char ch;
	int i=0;
	while((ch=getchar()) != EOF && ch!='\n')
		line[i++] = ch;
	if(ch == '\n')
	{
		line[i++] = ch;
	}
	line[i] = '\0';
	return i;
}

void* replace_newline_character_with_space(char *string_a)
{
	if(*(string_a = string_a-2) == '\n')
	{
		*string_a++ = ' ';
	}
	return string_a;
}