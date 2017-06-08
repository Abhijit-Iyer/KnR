// strrindex(line,pattern), which returns the index of the last occurence of pattern found in line 

#include <stdio.h>
#include <string.h>

#define LINESIZE 10000

int getline(char [], int);
int strrindex(char[],char[]);
int getPattern(char []);
int checkPatternLength(char [], char[]);

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

	while((ch=getchar()) != EOF && ch!='\n' && limit != 0)
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
	gets(pattern);
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
	int i,j,k;
	
	for( i = strlen(line) - 2; i > -1; i--)
	{
		for( j = i , k = strlen(pattern) - 1 ; line[j] == pattern[k] && k != 0; k-- , j-- )
			;
		if( k == 0 )
			return j;	
	}

	return -1;
}