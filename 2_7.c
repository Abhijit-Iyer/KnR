#include <stdio.h>

int invert(unsigned int, int, int);

void main()
{
	int x = 15, p = 4, n = 3;

	x = invert(x,p,n);
	printf("x = %d",x);
}

int invert(unsigned x,int p,int n)
{
	return -(~((x>> (p+1-n)) & ~(~0 << n)));
}
