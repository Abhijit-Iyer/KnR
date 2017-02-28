#include<stdio.h>

#define TABSTOP 4;

int getline(char []);
int checkForSpaces(char [], char[]);
int replaceSpacesWithTab(char [], int, int);
int spaceCounter(char [], int*, int);

void main()
{
	char line[1000], newline[1000];
	if(getline(line))
	{
		checkForSpaces(line,newline);
		printf("\n%s",newline);
		//printf("%s\n",line);
	}
}

int getline(char line[])
{
	char ch;
	int index=0;
	while((ch=getchar()) != EOF && ch!='\n')
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int checkForSpaces(char line[], char newline[])
{
	int index = 0, newindex = 0, spacecount = 0;
	while(line[index] != '\0')
	{
		if(line[index] == ' ')
		{
			spacecount = spaceCounter(line,&index,spacecount);
			newindex = replaceSpacesWithTab(newline,newindex,spacecount);
		}
		spacecount = 0;
		newline[newindex] = line[index];
		index++;
		newindex++;		 
	}
}

int spaceCounter(char line[],int *index, int spacecount)
{
	while(line[(*index)] == ' ')
	{
		(*index)++;
		spacecount++;
	}
	return spacecount;
}

int replaceSpacesWithTab(char newline[], int newindex,int spacecount)
{
	int numberOfTabs = 0,numberOfSpaces = 0;
	numberOfTabs = spacecount/TABSTOP;
	numberOfSpaces =  spacecount % TABSTOP;
	while( numberOfTabs>0 )
	{
		newline[newindex++] = '*';   //NOTE : '*' represents a TAB
		numberOfTabs--;
	}
	while( numberOfSpaces>0 )
	{
		newline[newindex++] = '#';	 //NOTE : '#' represents a SPACE
		numberOfSpaces--;
	}
	return newindex;
}