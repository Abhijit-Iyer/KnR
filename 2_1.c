#include <stdio.h>
#include <limits.h>
#include <float.h>

void main()
{
	int i = 0;
	float j=0.0;
	// PRINTING DATATYPE RANGES WITH THE HELP OF MACROS FROM LIMITS.H

	printf("\n\tMaximum range of character : %d\n",CHAR_MAX);
	printf("\tMinimum range of character : %d\n",CHAR_MIN);

	printf("\tMaximum range of integer : %d\n",INT_MAX);
	printf("\tMinimum range of integer : %d\n",INT_MIN);

	printf("\tMaximum range of long : %d\n",LONG_MAX);
	printf("\tMimimum range of long : %d\n",LONG_MIN);

	printf("\tMaximum range of float : %e\n",FLT_MAX);
	printf("\tMimimum range of float : %e\n",FLT_MIN);

	printf("\tMaximum range of unsigned character : %d\n",UCHAR_MAX);
	printf("\tMaximum range of unsigned integer : %ld\n",UINT_MAX);
	printf("\tMaximum range of unsigned long : %ld\n",ULONG_MAX);

	// PRINTING DATATYPE RANGES BY CALCULATION
	printf("\n Loading...\n");
	while( i>=0)
		i++;
	printf("\n\tMinimum range of integer and long: %d\n",i);

	i=0;
	printf("\n Loading...\n");

	while( i<=0 )
		i--;
	printf("\n\tMaximum range of integer and long: %d\n", i);

	/*while( j<=0.0 )
		j--;
	printf("Maximum range of float : %f\n",j); */
}