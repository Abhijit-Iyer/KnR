#include<stdio.h>
#include<conio.h>
void main()
{
  int fahr,low=0,high=200,step=20;
  float celcius;
  clrscr();
  printf("   F    C\n");
  while(low<=high)
  {
    fahr=low;
    celcius = ( fahr - 32.0 ) * ( 5.0 / 9.0 );
    printf("\n%3d%6.1f",fahr,celcius);
    low=low+step;
  }
  getch();
}