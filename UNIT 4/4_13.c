// itoa - converts an integer to characters and stores them in a character set s (with function reverse() recursed)

#include <stdio.h>
#include <limits.h>
#include <string.h>

#define BUFSIZE 100

int reverse(int, int);
int itoa();

char s[BUFSIZE];

void main()
{
	int n;
	printf("\n Enter an integer: ");
	scanf("%d",&n);
	itoa(n,s);
	printf("\n The character converted is: %s",s);
}

int itoa(int n, char s[])
{
	int sign,i = 0;

	if((sign = n) < 0 )
	{
		if(n == INT_MIN)
			n++; 
			n = -n;
	}

	do
	{
		s[i] = ( n % 10 ) + '0';

		if(-(n+1) == INT_MIN)
			s[i] = s[i] + 1;
		
		i++;
	}while((n = n / 10 ) > 0);
	if(sign < 0)
		s[i++] = '-';

	s[i] = '\0';
	
	reverse(0,strlen(s)-1);
}

//char i = 0,j = strlen(s) - 1;

int reverse(int i, int j)
{
	char temp;

	if(j<i)
		return 0;

	temp = s[i];
	s[i] = s[j];
	s[j] = temp;

	reverse(++i, --j);
}