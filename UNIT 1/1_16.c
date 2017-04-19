#include<stdio.h>
#define MAXSIZE 1000
int getline(char [],int);
void copy(char [],char []);
void main()
{
	int len,max,i=0,a[100];
	char line[MAXSIZE],longest[MAXSIZE];
	max =0;
	{
		while((len=getline(line,MAXSIZE)) > 0)
		{
			a[i++] = len;
			if(len > max)
			{
				max = len;
				copy(longest,line);
			}
		}
		if(max>0)
		{
			while(i-->0)
				printf("\n Length of line %d : %d",i+1,a[i]);
			printf("\n Longest : %s",longest);
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