#include<stdio.h>
#include<conio.h>
void converter(int,int,int);
void main()
{
  int low=0,high=200,step=20;
  converter(high,low,step);
  getch();
}
void converter(int high,int low,int step)
{
    float celcius;
    int fahr;
    printf("   F    C\n");
    while(low<=high)
    {
      fahr=low;
      celcius = ( fahr - 32.0 ) * ( 5.0 / 9.0 );
      printf("\n%3d%6.1f",fahr,celcius);
      low=low+step;
    }
}