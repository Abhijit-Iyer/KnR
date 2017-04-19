#include<stdio.h>

#define LINELIMIT 1000

int getLine(char []);

void main()
{
	char line[LINELIMIT];
	getLine(line);
	printf("%s\n",line );
}

int getLine(char line[])
{
	char ch;
	int i=0;
	while( ( ch = getchar() ) != EOF)
	{
		if( i>LINELIMIT-1 )
			break;
		if( ch == '\n')
			break;
		line[i] = ch;
		i++;
	}
	return 0;
}