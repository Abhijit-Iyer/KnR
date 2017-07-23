#include <stdio.h>
#include "headers.h"

extern int year;
extern int month;
extern int day;

int display_result(int status)
{
	switch(status)
	{
		case 1 : printf("\n\n\t\t\t\t The day of the year is : %d\n\n",day);
				break;

		case 2 : printf("\n\n\t\t\t\t The date is %d/%d/%d\n\n\n",day, month, year);
				break;

		case 3 : printf("\n\n\t Invalid entry found. Please re-check your entries. \n\n");
				break;

		default : break;
	}

	return 0;
}