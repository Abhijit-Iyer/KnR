#include<stdio.h>
int getline(char []);
int removeSpaces(char [],char []);
void main()
{
	char line[1000],destination[1000];
	int i,j;
	if(getline(line))
	{
		removeSpaces(line,destination);
		printf("\n%s",destination);
	}
}

// Takes a line of characters as input 

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

// Removes trailing spaces
int removeSpaces(char line[],char destination[])
{
	int i=0,j=0;
	while((destination[j]=line[i])!='\0')
	{
		if(line[i] == ' ')
		{
			destination[j++] = line[i];
			while(line[i] == ' ')
			{
				i++;
			}
		}
		else
		{
			i++;
			j++;
		}
	}
	return 0;
}