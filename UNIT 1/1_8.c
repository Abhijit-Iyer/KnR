#include <stdio.h>
int main(int argc, char const *argv[])
{
	int newline,blank,tab;
	char ch;
	while((ch=getchar())!=EOF)
	{
		if(ch=='\n')
			newline++;
		if(ch==' ')
			blank++;
		if(ch=='\t')
			tab++;
	}	
	printf("\n Newline = %d, Blankspace = %d, Tab = %d",newline,blank,tab);
	return 0;
}