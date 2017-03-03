#include<stdio.h>

#define MAXLINE 1000
#define LINESIZE 50

int getline(char []);
int breakLine(char [], int);

void main()
{
	char line[MAXLINE];	
	if(getline(line))
	{
		printf("%s\n",line );
	}
}

int getline(char line[])
{
	char ch;
	int index=0,backup;
	while((ch=getchar()) != EOF && ch!='\n')
	{
		line[index++] = ch;
		if(( index%(LINESIZE-1) ) == 0)
		{	
		 	backup = index;
			breakLine(line,index);
			index = backup;
		}
		//index++;
		printf("\n index = %d",index);
	}
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int breakLine(char line[],int index)
{
	if(line[index] == ' ')
	{
		line[index] = '\n';
	}
	else
	{
		while( line[index] != ' ' && index>0 )
			index--;
		line[index] = '\n';
	}
}