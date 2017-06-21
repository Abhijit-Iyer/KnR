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
	printf("\n The character converted is: %s",s);
	itoa(n,s);
}

int itoa(int n)
{
	int sign,i = 0;

	if((sign = n) < 0 )
	{
		if(n == INT_MIN)
			n++; 
			n = -n;
	}

	if(sign < 0)
		putchar('-');

	if( n/10 )
		itoa(n/10);

	putchar( ( n % 10 ) + '0');
}