#include <stdio.h>
#include "headers.h"

extern char daytab[2][13];

int month_day(int year, int *yearday, int *pmonth)
{
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

	for(i=1; *yearday>daytab[leap][i]; i++)
	{
		*yearday = *yearday - daytab[leap][i];
	}
	*pmonth = i;
}
