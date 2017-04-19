#include <stdio.h>
#include <math.h>

int getHexadecimalNumber(char []);
int htoi(char [], int);

void main()
{
	char hex_number[10];
	int index,integer_equivalent;

	index = getHexadecimalNumber(hex_number);
	integer_equivalent = htoi(hex_number,index);

	printf("\n\n\t HEXADECIMAL NUMBER : %s\n", hex_number );
	printf("\n\n\t INTEGER EQUIVALENT : %d\n", integer_equivalent);
}

int getHexadecimalNumber(char hex_number[])
{
	char ch;
	int index = 0;

	while( ( ch = getchar() )!= '\n')\
		hex_number[index++] = ch;
	hex_number[index] = '\0';

	return --index;
}

int htoi( char hex_number[], int index)
{
	int integer_equivalent = 0, k=0;

	while( hex_number[index] != 'X' && hex_number[index] != 'x')
	{
		if( hex_number[index] >= '0' && hex_number[index] <= '9')
			integer_equivalent = integer_equivalent + ( ( hex_number[index] - '0' ) * (int)pow(16,k));

		else if( hex_number[index] >= 'A' && hex_number[index] <= 'F')
			integer_equivalent = integer_equivalent + ( ( hex_number[index] - 55 ) * (int)pow(16,k));

		else if( hex_number[index] >= 'a' && hex_number[index] <= 'f')
			integer_equivalent = integer_equivalent + ( ( hex_number[index] - 87 ) * (int)pow(16,k));

		else
		{
			printf("INVALID ENTRY\n");
			return 0;	
		}

		--index;
		k++;

	}

	return integer_equivalent;
}