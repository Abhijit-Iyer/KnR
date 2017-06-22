// itoa - converts an integer to characters and stores them in a character set s (recursive method)

#include <stdio.h>
#include <limits.h>
#include <string.h>

int reverse(char []);
int itoa();

#define BUFFERSIZE 20

char s[BUFFERSIZE];

void main()
{
	int n;
	printf("\n Enter an integer: ");
	scanf("%d",&n);
	itoa(n);
	printf("\n The character converted is: %s",s);
}

int i = 0;

int itoa(int n)
{
	int sign;

	if((sign = n) < 0 )
	{
		if(n == INT_MIN)
			n++; 
			n = -n;
	}

	if(sign < 0)
		s[i++] = '-';

	if( n/10 )
		itoa(n/10);

	s[i++] = ( n % 10 ) + '0';
}