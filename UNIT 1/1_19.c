#include<stdio.h>
int getline(char []);
int reverseString(char [],char [],int);
void main()
{
	char string[1000], reverse[1000];
	int len;
	if(len=getline(string))
	{
		reverseString(string,reverse,(len-2));
		printf("%s\n",reverse);
	}
	else
		printf("\nNo String Entered.\n");
}

// Takes a line of characters/string as input 

int getline(char line[])
{
	char ch;
	int i=0;
	while((ch=getchar()) != EOF && ch!='\n')
		line[i++] = ch;
	if(ch == '\n')
	{
		line[i++] = ch;
	}
	line[i] = '\0';
	return i;
}

// Reverses the string entered as input

int reverseString(char string[], char reverse[], int len)
{
	int i=0,j=len;
	while(string[i] != '\0')
		reverse[len--] = string[i++];
}
