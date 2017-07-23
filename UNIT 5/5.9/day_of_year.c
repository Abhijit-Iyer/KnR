#include <stdio.h>
#include "headers.h"

extern char daytab[2][13];

int day_of_year(int year, int month, int day)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for(i=1; i<month; i++)
		day = day + *(*(daytab+leap)+i);

	return day;
}
