#ifndef HEADERS_H
#define HEADERS_H

int day_of_year(int, int, int);
int month_day(int, int *, int *);
char get_choice_from_user();
int get_year_month_and_day_from_user(int *, int *, int *);
int get_year_and_day_from_user(int *, int *);
int display_result(int);

#define THE_DAY_OF_THE_YEAR 1
#define THE_DATE 2
#define	ERROR 3 

#endif