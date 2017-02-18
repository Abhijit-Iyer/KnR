#include<stdio.h>
#define IN 1;
#define OUT 0;
void main()
{
	int state = OUT;
	int nw=0;
	char ch;
	while((ch=getchar())!=EOF)
	{
		if( ch == '\n' || ch == ' ' || ch == '\t' )
			printf("\n");
		else
			printf("%c",ch);
	}
}