#include <stdio.h>
#include <ctype.h>
#include "Headers.h" 

int process_input_and_convert_to_float(float buffer[], int maxsize)
{
	int buffer_index ;

	for(buffer_index = 0; 
        buffer_index < maxsize && getfloat(&(buffer[buffer_index])) != EOF; 
        buffer_index++)
        ;  

    return 0;
}

int getfloat(float *address)
{
    char c, sign;
    int power = 1;
    *address = 0;

    skip_spaces(&c);

    check_for_invalid_character(&c);

    check_for_sign(&c, &sign);

    if(isdigit(c))              
        ungetch(c);

    get_characteristic(&c,address);

    if(c == '.')
    {
  		get_mantissa(&c, address, &power);
        *address = *address / power;
    }

    *address = *address * sign;

    if( c != EOF)      
        ungetch(c); 

    return c;
}