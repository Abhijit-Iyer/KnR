#include <stdio.h>

#define LINESIZE 10000

int getline(char []);
int expand(char [], char[]);
int expander(char [], char[], int *, int *);

void main()
{
	char line[LINESIZE], newline[LINESIZE];

	getline(line);
	expand(line,newline);

	printf("%s\n",newline );
}

int getline(char line[])
{
	char ch;
	int index=0;
	while((ch=getchar()) != EOF)
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int expand(char line[], char newline[])
{
	int line_index = 0, newline_index = 0;
	while(line[line_index] != '\0')
	{
		switch(line[line_index])
		{
			case '-' : if(line[line_index - 1] >= 'a' && line[line_index + 1] <= 'z') 
							expander(line, newline, &line_index, &newline_index);
						else if(line[line_index - 1] >= '0' && line[line_index + 1] <= '9')
							expander(line, newline, &line_index, &newline_index);
						else
							;
			default  : newline[newline_index] = line[line_index];
									break;
		}
		line_index++; newline_index++;
	}
	return 0;
}

int expander(char line[], char newline[], int *line_index, int *newline_index)
{
	char ch;
	{	
		for(ch = (line[(*line_index) - 1]) + 1 ; ch <= line[(*line_index) + 1] ; ch++)
			{	
				newline[(*newline_index)] = ch;
				(*newline_index)++;
			}
	}
	(*line_index) = (*line_index) + 2;
}