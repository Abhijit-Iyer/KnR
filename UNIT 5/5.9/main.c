#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int year, month, day;

void main()
{	
	char choice;

	choice = get_choice_from_user();

	switch(choice)
	{
		case '1' : if(get_year_month_and_day_from_user(&year, &month, &day))
					{
						day = day_of_year(year, month, day);	
						display_result(THE_DAY_OF_THE_YEAR);
					}	
					else
					{
						display_result(ERROR);
					}				
					break;

		case '2' : if(get_year_and_day_from_user(&year, &day))
					{
						month_day(year, &day, &month);
						display_result(THE_DATE);
					}
					else
					{
						display_result(ERROR);
					}
					break;

		default  : display_result(ERROR);
	}	
}
