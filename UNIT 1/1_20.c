#include<stdio.h>
int getline(char []);
int checkTab(char [],char []);
int replaceTabWithSpace(char[],char [], int, int);
void main()
{
	char line[1000],newline[1000];
	if(getline(line))
	{
		checkTab(line,newline);
		printf("%s",newline);
	}
}

int getline(char line[])
{
	char ch;
	int index=0;
	while((ch=getchar()) != EOF && ch!='\n')
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';
	return index;
}

int checkTab(char line[],char newline[])
{
	int index=0,index2=0;
	while(line[index] != '\0')
	{
		if(line[index] == '\t')
		{
			index2 = replaceTabWithSpace(line,newline,index,index2);
			index++;
		}
		newline[index2] = line[index];
		index++;
		index2++;
	}
}

int replaceTabWithSpace(char line[],char newline[],int index,int index2)
{
	int tabsize = 4,spaces;
	spaces = tabsize-(index%tabsize);
	while( spaces>0 )
	{
		newline[index2++] = '*';	//NOTE: '*' refers to a space here.
		spaces--;
	}
	return index2;
}	