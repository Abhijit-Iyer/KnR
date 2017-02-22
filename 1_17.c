#include<stdio.h>
#define MAXSIZE 1000
int getline(char [],int);
void copy(char [],char []);
void main()
{
	int len;
	char line[MAXSIZE],longest[MAXSIZE];
	{
		while((len=getline(line,MAXSIZE)) > 0)
		{
			if(len > 80)
			{
				copy(longest,line);
				printf("\n The line you've entered is longer than 80 characters:%s",longest);
			}
		}
	}
}

int getline(char s[],int lim)
{
	int c,i;
	for(i=0; (i<lim-1) && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if(c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
} 

void copy(char to[],char from[])
{
	int i=0;
	while((to[i]=from[i]) != '\0')
		++i;
}