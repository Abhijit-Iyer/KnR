#include <stdio.h>
#include <limits.h>
#include <string.h>

int reverse(char []);
int itoa(int, char[], int);

void main()
{
	int n, min_width;
	char s[20];
	printf("\n Enter an integer: ");
	scanf("%d",&n);
	printf("\n Enter the minimum width: ");
	scanf("%d",&min_width);
	itoa(n,s,min_width);
	printf("\n The character converted is: %s",s);
}

int itoa(int n, char s[], int min_width)
{
	int sign,i = 0;

	//((sign = n) < 0)? (n = -n) : (n = n);
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

	while((min_width--) != 0)
		s[i++] = '*';				// '*' used as a substitur for ' '

	s[i] = '\0';
	reverse(s);
}

int reverse(char s[])
{
	char i,j;
	char temp;
	for(i=0,j=strlen(s)-1; i<j;i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}