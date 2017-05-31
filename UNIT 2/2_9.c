#include <stdio.h>

int bitcount(unsigned,int);

void main()
{
	unsigned temp = 14,count=0;
	printf("\n No. of 1's = %d",bitcount(temp,count));
}

/*int bitcount(unsigned x,int count)
{
	do
	{
		if(x&1)
			count++;						EXAMPLE VERSION
		x=x>>1;
	}while( x != 0);
	return count;
}*/


int bitcount(unsigned x,int count)
{
	while(x != 0)
	{
		x&=(x-1);
		count++;
	}	
	return count;
}