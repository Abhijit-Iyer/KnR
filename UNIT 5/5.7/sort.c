#include <stdio.h>
#include "headers.h"

int line_count;

int sort_array(char *p[])
{
	int i,j;
	char *temp;
  	for( i=0 ; i<line_count; i++ )
  	{
    	for( j=i ; j>0 ; j--)
    	{
      		if( **(p+j) < **(p+j-1) )
      		{
	  			temp     = *(p+j);
				*(p+j)   = *(p+j-1);
				*(p+j-1) = temp;
      		}
    	}
  	}	
}
