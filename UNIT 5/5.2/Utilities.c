#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include "mymethods.h"

//Takes a line of string characters from the console

int reverseString(char string[], char reverse[], int len)
{
	int i=0,j=len;
	while(string[i] != '\0')
		reverse[len--] = string[i++];
}

//Reverses a string of characters

int getline(char line[])
{
	char ch;
	int i=0;
	while((ch=getchar()) != EOF && ch!='\n')
		line[i++] = ch;
	if(ch == '\n')
	{
		line[i++] = ch;
	}
	line[i] = '\0';
	return i;
}

// Removes trailing spaces

int removeSpaces(char line[],char destination[])
{
	int i=0,j=0;
	while((destination[j]=line[i])!='\0')
	{
		if(line[i] == ' ')
		{
			destination[j++] = line[i];
			while(line[i] == ' ')
			{
				i++;
			}
		}
		else
		{
			i++;
			j++;
		}
	}
	return 0;
}

//Copies contents from one character buffer to another

void copy(char to[],char from[])
{
	int i=0;
	while((to[i]=from[i]) != '\0')
		++i;
}

// Converts a hexadecimal number to an integer

int htoi( char *hex_number, int index)
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

//Removes similar characters present in buffer1[] and buffer2[] and stores them in buffer_output[] 

int squeeze(char line_1[], char line_2[], char output[])
{
	int index_1=0,index_2=0,output_index=0;

	while(line_1[index_1] != '\0')
	{
		while(line_2[index_2] != '\0')
		{
			if(line_1[index_1] == line_2[index_2++])
			{
				index_1++;
				index_2 = 0;
				continue;
			}
		}
		index_2 = 0;
		output[output_index++] = line_1[index_1++];
	}
	output[output_index] = '\0';
}

//Converts upper case alphabets to lower case

int lower(int ch)	
{
	( ch >= 'A' && ch <= 'Z' )? ( ch = ch + 'a' - 'A' ) : ( ch );
	return ch;
}

//Sorts a given array int[] whose array size is int *

int sort_array(int p[], int *n)
{
	int i,temp,j;
  	for( i=0 ; i<(*n) ; i++ )
  	{
    	for( j=i ; j>0 ; j--)
    	{
      		if( *(p+j) < *(p+j-1) )
      		{
	  			temp=*(p+j);
				*(p+j)=*(p+j-1);
				*(p+j-1)=temp;
      		}
    	}
  	}	
  	printf("\n SORTED ARRAY: ");
  	for( i=0 ; i<*n;i++)
  		printf("%d  ",p[i]);
}

//Performs binary search on a given array (array, arraysize)

int binary_search(int arr[], int *arraysize)
{
	int i,item,low,high,mid, counter = 0;
  	printf("\n\n Enter the number to be searched: ");
  	scanf("%d",&item);
  	low = 0;
  	high = *arraysize-1;
  	while((arr[mid = (low + high)/2] != item ) && low<=high)
  	{
  		if( item < arr[mid])
  			high = mid - 1;
  		else
  			low = mid + 1;
  	}
  	if(high<low || arr[mid] != item)
  		return 0;
  	else
  		return mid;
}

//Expands shorthand notations like a-z, 0-9

int expand(char line[], char newline[])
{
	int line_index = 0, newline_index = 0;
	while(line[line_index] != '\0')
	{
		switch(line[line_index])
		{
			case '-' : if(line[line_index - 1] >= 'a' && line[line_index + 1] <= 'z') 
							expander(line, newline, &line_index, &newline_index);
						else if(line[line_index - 1] >= '0' && line[line_index + 1] <= '9')
							expander(line, newline, &line_index, &newline_index);
						else
							;
			default  : newline[newline_index] = line[line_index];
									break;
		}
		line_index++; newline_index++;
	}
	return 0;
}

//Performs the expansion of above method

int expander(char line[], char newline[], int *line_index, int *newline_index)
{
	char ch;
	{	
		for(ch = (line[(*line_index) - 1]) + 1 ; ch <= line[(*line_index) + 1] ; ch++)
			{	
				newline[(*newline_index)] = ch;
				(*newline_index)++;
			}
	}
	(*line_index) = (*line_index) + 2;
}

//Converts an integer number and stores them digit by digit in a character buffer

int itoa(int n, char s[])
{
	int sign,i = 0;

	//((sign = n) < 0)? (n = -n) : (n = n);
	if((sign = n) < 0 )
	{
		if(n == INT_MIN)
			n++; 
			n = -n;
	}

	do
	{
		s[i] = ( n % 10 ) + '0';
		if(-(n+1) == INT_MIN)
			s[i] = s[i] + 1;
		i++;
	}while((n = n / 10 ) > 0);
	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s);
}

//Reverses a string []

int reverse(char s[])
{
	char i,j;
	char temp;
	for(i=0,j=strlen(s)-1; i<j;i++,j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

//Converts integer 'n' to base b and stores the resukt in buffer s[]

int itob(int n, char s[], int b)
{
	int i = 0, rem;

	do
	{
		rem = n % b;
		if(rem >= 10)
			s[i++] = rem + 55;
		else
			s[i++] = rem + '0';
	}while( (n = n/b) > 0 );

	reverse(s);
}

// strrindex(line,pattern), which returns the index of the last occurence of pattern found in line 

int strrindex(char line[], char pattern[])
{
	int line_index, temporary_line_index, pattern_index;
	
	for( line_index = strlen(line) - 2;line_index > -1; line_index--)
	{
		pattern_index = comparator(&line_index, &temporary_line_index, &pattern_index, line, pattern);
		
		if( pattern_index == 0 )
			return temporary_line_index;	
	}

	return -1;
}

// compares the line and pattern of the above strrindex

int comparator(int *line_index, int *temporary_line_index, int *pattern_index, char line[], char pattern[])
{
	for( (*temporary_line_index) = (*line_index) , (*pattern_index) = strlen(pattern) - 2 ; 
		line[(*temporary_line_index)] == pattern[(*pattern_index)] && (*pattern_index) != 0; 
		(*pattern_index)-- , (*temporary_line_index)-- )
		;

	return (*pattern_index);
}

int check_for_ungetch = 0;
char temporary_buffer[BUFSIZE];

//Returns a character from console (or) from a push_back buffer

char getch(void)
{
	return (check_for_ungetch > 0) ? temporary_buffer[--check_for_ungetch] : getchar();
}

//Pushes back a read character into a pushback buffer for future use

void ungetch(int c)
{
	temporary_buffer[check_for_ungetch++] = c;
}