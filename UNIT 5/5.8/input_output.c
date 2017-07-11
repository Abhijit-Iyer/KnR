#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

extern char daytab[2][13];

char get_choice_from_user()
{
	char choice;

	printf("\n\n\t 1) Calculate the day of the year from month and day");
	printf("\n\n\t 2) Calculate the month and day from the day of the year");
	printf("\n\n\t Enter your choice : ");

	scanf("%c",&choice);

	return choice;
}

int get_year_month_and_day_from_user(int *year, int *month, int *day)
{
	system("cls");

	printf("\n\n\t Enter the year : ");
	scanf("%d",year);

	printf("\n\n\t Enter the month : ");
	scanf("%d",month);

	printf("\n\n\t Enter the day : ");	
	scanf("%d",day);

	if(*day > 31 || *month > 12)
		return 0;

	if( ((*year) % 10000 == (*year) - 10000 ) || (*year) % 10000 == 0 )
		return 0;

	return 1;
}

int get_year_and_day_from_user(int *year, int *day)
{
	system("cls");

	printf("\n\n\t Enter the year : ");
	scanf("%d",year);

	printf("\n\n\t Enter the day : ");	
	scanf("%d",day);

	if(*day>366)
		return 0;

	if( ((*year) % 10000 == (*year) - 10000 ) || (*year) % 10000 == 0 )
		return 0;
}