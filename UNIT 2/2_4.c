#include <stdio.h>

#define LINE_LENGTH 10000

int getLine(char []);
int squeeze(char [],char [],char []);

void main()
{
	char line_1[LINE_LENGTH],line_2[LINE_LENGTH],output[LINE_LENGTH];
	getLine(line_1);
	getLine(line_2);
	printf("%s\n",line_1 );
	printf("%s\n",line_2 );
	squeeze(line_1,line_2,output);
	printf("OUTPUT : %s\n", output);
}

int getLine(char line[])
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

int squeeze(char line_1[], char line_2[], char output[])
{
	int index_1=0,index_2=0,output_index=0;

	while(line_1[index_1] != '\0')
	{
		while(line_2[index_2] != '\0')
		{
			if(line_1[index_1] == line_2[index_2++])
			{
				index_1++;
				index_2 = 0;
				continue;
			}
		}
		index_2 = 0;
		output[output_index++] = line_1[index_1++];
	}
	output[output_index] = '\0';
}