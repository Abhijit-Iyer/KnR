#include<stdio.h>
void main()
{
	char ch;
	int blankspace = 0;
	while((ch=getchar())!=EOF)
	{
		if(ch==' ')
		{
			printf("%c",' ');
			while((ch=getchar())==' ');
			printf("%c",ch);
		}
		else
			printf("%c",ch);
	}
}