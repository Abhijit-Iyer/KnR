// itob - converts an integer to characters to a specific base 'b' and stores them in a character set s

#include <stdio.h>
#include <string.h>

int itob(int, char [], int);
int reverse(char []);

void main()
{
	int n,b;
	char s[20];

	printf("\n Enter an integer: " );
	scanf("%d",&n);
	printf("\n Enter the base you'd like to convert it to: ");
	scanf("%d",&b);
	itob(n,s,b);
	printf("\n The character stream of the converted integer is: %s",s);
}

int itob(int n, char s[], int b)
{
	int i = 0, rem;

	do
	{
		rem = n % b;
		if(rem >= 10)
			s[i++] = rem + 55;
		else
			s[i++] = rem + '0';
	}while( (n = n/b) > 0 );

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