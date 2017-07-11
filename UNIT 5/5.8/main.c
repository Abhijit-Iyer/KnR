#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

char daytab[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

void main()
{
	char choice;
	int year, month, day;

	system("cls");

	choice = get_choice_from_user();

	switch(choice)
	{
		case '1' : if(get_year_month_and_day_from_user(&year, &month, &day))
					{
						day = day_of_year(year, month, day);
						printf("\n\n\t\t\t\t The day of the year is : %d\n\n",day);
					}	
					else
					{
						printf("\n\n\t Invalid entry found. Please re-check your entries. \n\n");
					}				
					break;

		case '2' : if(get_year_and_day_from_user(&year, &day))
					{
						month_day(year, &day, &month);
						printf("\n\n\t\t\t\t The date is %d/%d/%d\n\n\n",day, month, year);
					}
					else
					{
						printf("\n\n\t Invalid entry found. Please re-check your entries. \n\n");
					}
					break;

		default  : printf("\n Invalid Choice");
	}	
}
