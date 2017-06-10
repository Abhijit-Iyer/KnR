#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define LINESIZE 50

int getline(char []);
double atof(char []);
int removeTrailingSpaces(char []);
double getCharacteristic(char [], double, int *);
double getMantissa(char [], double, int *);

void main()
{
	char line[LINESIZE];
	double number;

	getline(line);

	number = atof(line);

	printf("\n The number you've entered (converted to double) is : %lf\n",number);
}

int getline(char line[])
{
	printf("\n Enter a floating point number: ");
	fgets(line, LINESIZE, stdin);

	return 0;
}

double atof(char line[])
{
	int index = 0, sign, exponent;
	double value;

	index = removeTrailingSpaces(line);

	if(line[index] == '-')
	{
		sign = -1;
		index++;
	}
	else
		sign = 1;

	value = getCharacteristic(line, value, &index);

	if(line[index] == '.')
		index++;

	value = getMantissa(line, value, &index);

	if(line[index] == 'e' || line[index] == 'E')
		index++;

	if(line[index] == '-')
		value = value / pow(10,(line[++index] - '0'));
	else
		value = value * pow(10,(line[index] - '0')); 

	return value * sign;
}

int removeTrailingSpaces(char line[])
{
	int index = 0;
	while(line[index] == ' ')
		index++;

	return index;
}

double getCharacteristic(char line[], double value, int *index)
{
	for(value = 0.0; isdigit(line[(*index)]); (*index)++)
		value = (value * 10.0) + (line[(*index)] - '0');

	return value;
}

double getMantissa(char line[], double value, int *index)
{
	double power;

	for(power = 1.0; isdigit(line[(*index)]); (*index)++)
	{
		value = ( value * 10.0 ) + (line[(*index)] - '0');
		power = power * 10.0;
	}

	value = value / power;

	return value;
}