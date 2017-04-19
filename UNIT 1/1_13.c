#include<stdio.h>
void main()
{
	char ch;
	int count=0,arr[50],i=0,j,word=0,max;
	for(i=0;i<50;i++)
		arr[i++] = 0;
	i=0;
	while((ch=getchar())!=EOF)
	{
		if( ch != '\n' && ch!= '\t' && ch!= ' ')
			count++;
    	while((ch=getchar())!=' ')
    	{
    		if( ch == '\n' || ch == '\t' )
    			break;
    		else	
    			count++;
    	}
    	arr[i++] = count;    			
    	count = 0;	
	}
	count = i;

	// Horizontal Printing

	/*for( i=0; i<count; i++)
	{
		printf(" %d | ",i+1);
		for(j=arr[i];j>0;j--)
			printf("*");
		printf("\n");
	}

	printf("\n\n\n\n"); */

	// Vertical Printing
	max = arr[0];
	for(i=1;i<count;i++)
	{
		if( arr[i] > max )
			max = arr[i];
	}
	for(i=max;i>0;i--)
	{
		for(j=0;j<count;j++)
		{
			if(arr[j]>=i)
				printf(" %c ",254);
			else
				printf("   ");
		}
		printf("\n");
	}
}