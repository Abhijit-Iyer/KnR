#include <stdio.h>

int lower();

void main()
{
	char ch;

	printf("\n Enter an upper-case alphabet: ");
	ch = getchar();
	ch = lower(ch);
	printf("\n Lower = %c\n",ch );
}

int lower(int ch)	
{
	( ch >= 'A' && ch <= 'Z' )? ( ch = ch + 'a' - 'A' ) : ( ch );
	return ch;
}