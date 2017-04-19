#include <stdio.h>

int setbits(unsigned int, int, int, unsigned int);

void main()
{
	int x = 15, p = 4, n = 3, y = 12;

	y = setbits(x,p,n,y);

	printf("y = %d",y);
}

int setbits(unsigned x,int p,int n,unsigned y)
{
	return y |  (x>> (p+1-n)) & ~(~0 << n);
}