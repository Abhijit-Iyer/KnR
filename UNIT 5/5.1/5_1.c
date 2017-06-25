#include <stdio.h>
#include <ctype.h>
#include "mymethods.h"

int getint(int *);

void main()
{
	int buffer[BUFSIZE], maxsize, buffer_index;

	printf("\n Enter the array size : ");

	scanf("%d",&maxsize);

	printf("\n Enter the elements of the array : ");	

	for(buffer_index = 0; 
		buffer_index < maxsize && getint(&(buffer[buffer_index])) != EOF; 
		buffer_index++)
		;

	printf("\n The array elements you've entered are :");

	for( buffer_index=0; buffer_index<maxsize; buffer_index++)
		printf("  %d",buffer[buffer_index]);
}

/*  The folloeing method getint(int *) method receives the address of a memory object as a parameter. 
	The main task of this method is	to consume input from the console and convert it into an integer, 
	and then store it in the memory address that was passed as parameter.*/

int getint(int *address)
{
	char c, sign;

	while(isspace(c = getch()))
		;								/* Skips white spaces present before the number. */

	/* In the following section, if the character present in the input is neither a number nor a sign,
		 an error message is shown. */	

	if(!isdigit(c) && c != '-' && c != '+' && c != EOF)	
	{
		printf("\n Invalid character.");				
		return 0;
	}

	sign = (c == '-')? -1 : 1;				// Takes note ofthe sign entered before a number.

	if( c == '-' || c == '+')				
		c = getch();

	*address = 0;

	if(isdigit(c))					// Pushes the nunmber read along with the sign into the input.
		ungetch(c);

	//Reads the integer from the console and stores it in the passed address of the memory.

	while(isdigit(c = getch()))		
		*address = ((*address) * 10) + (c - '0');

	*address = *address * sign;

	if( c != EOF)		/* Pushes the next character read back into the input.*/
		ungetch(c); 

	return c;
}