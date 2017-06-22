// swap(t,x,y) swaps is a macro that swaps two elements x and y, which are of the datatype t

#include <stdio.h>

#define swap(data_type, parameter_1, parameter_2) { data_type temp; \
													temp = parameter_1; \
													parameter_1 = parameter_2; \
													parameter_2 = temp; } 

void main()
{
	int  x = 5, y = 7;

	printf("\n Values before swapping : %d %d",x,y);

	swap(int,x,y);

	printf("\n Values after swapping : %d %d",x,y);
}