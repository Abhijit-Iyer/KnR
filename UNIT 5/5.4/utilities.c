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

void match_characters(char **string_a, char **string_b)
{
	char *string_b_base = *string_b;

	while(**string_a != '\0')
		{
			if(**string_a == **string_b)
				(*string_b)++;
			else
				*string_b = string_b_base;

			(*string_a)++;
		}
}