#include<stdio.h>
#include<conio.h>
void main()
{
  int celcius,low=0,high=200,step=20;
  float fahr;
  clrscr();
  while(low<=high)
  {
    celcius = low;
    fahr = ( ( celcius + 32.0 ) *  9.0  )  / 5.0 ;
    printf("\n%d  %6.1f",celcius,fahr);
    low=low+step;
  }
  getch();
}