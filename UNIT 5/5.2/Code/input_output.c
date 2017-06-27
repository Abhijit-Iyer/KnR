#include <stdio.h>
#include "Headers.h"

int get_maxsize(int *maxsize)
{
	printf("\n Enter the array size : ");

    scanf("%d",maxsize);

    return 0;
}

int prompt_user_to_enter_array_elements()
{
	printf("\n Enter the elements of the array, using spaces after each entry : ");

	return 0;
}

int display_array(float buffer[], int maxsize)
{
	int buffer_index;

	printf("\n The array elements you've entered are : ");

	for( buffer_index=0; buffer_index<maxsize; buffer_index++)
        printf("  %.2f",buffer[buffer_index]);

    printf("\n");

    return 0;
}