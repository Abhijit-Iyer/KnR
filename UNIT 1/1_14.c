#include<stdio.h>	
void main()
{
	char ch;
	int arr[127],i,j;
	for(i=0;i<127;i++)
		arr[i] = 0;
	while((ch=getchar())!=EOF)
		++arr[ch];
	for(i=0;i<127;i++)
	{
		printf("%c",i);
		for(j=0;j<arr[i];j++)
			printf("*");
		printf("\n");
	}
}