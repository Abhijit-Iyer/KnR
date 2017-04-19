#include <stdio.h>

int rightrot(unsigned int, int);

void main()
{
	int x = 15, n = 3;	

	x = rightrot(x,n);
	//printf("x = %d",x);
}

int rightrot(unsigned x, int n)
{
	int temp;

	temp = x>>n | x<<(32-n);

	printf("temp = %d\n", temp);
	return 0;
}