#include<stdio.h>
int main(int argc, char const *argv[])
{
	char ch;
	while((ch=getchar())!=EOF)
	{
		if(ch=='\t')
			printf("\\t");
		else if(ch==' ')
			printf("\\b");
	    else if(ch=='\\')
			printf("\\");
		else
			printf("%c",ch);
	}
	return 0;
}