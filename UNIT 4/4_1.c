// strrindex(line,pattern), which returns the index of the last occurence of pattern found in line 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINESIZE 10000

int getline(char [], int);
int strrindex(char[],char[]);
int getPattern(char []);
int checkPatternLength(char [], char[]);
int comparator(int *, int *, int *, char [], char []);

void main()
{
	char line[LINESIZE], pattern[LINESIZE];
	int index = 0;

	getline(line,LINESIZE);

	getPattern(pattern);

	if(checkPatternLength(pattern,line))
		return;

	if((index = strrindex(line,pattern)) >= 0)
		printf("\n\n Found at index %d",index);
	else
		printf("No pattern match found\n");
}

int getline(char line[], int limit)
{
	char ch;
	int index=0;

	while((ch=getchar()) != EOF && ch!='\n' && limit-- != 0)
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int getPattern(char pattern[])
{
	printf("\n Enter the pattern for matching: ");
	fgets(pattern,LINESIZE,stdin);
}

int checkPatternLength(char pattern[], char line[])
{
	if(strlen(pattern) > strlen(line))
	{
		printf("\n The pattern cannot be larger than the line.");
		return 1;
	}
	return 0;
}

int strrindex(char line[], char pattern[])
{
	int line_index, temporary_line_index, pattern_index;
	
	for( line_index = strlen(line) - 2;line_index > -1; line_index--)
	{
		pattern_index = comparator(&line_index, &temporary_line_index, &pattern_index, line, pattern);
		
		if( pattern_index == 0 )
			return temporary_line_index;	
	}

	return -1;
}

int comparator(int *line_index, int *temporary_line_index, int *pattern_index, char line[], char pattern[])
{
	for( (*temporary_line_index) = (*line_index) , (*pattern_index) = strlen(pattern) - 2 ; 
		line[(*temporary_line_index)] == pattern[(*pattern_index)] && (*pattern_index) != 0; 
		(*pattern_index)-- , (*temporary_line_index)-- )
		;

	return (*pattern_index);
}