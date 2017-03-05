#include<stdio.h>

#define CODESIZE 1000000

int getInput(FILE *, char []);
int checkAndRemoveComments(char [], char[]);
int checkForString(char [], int *,char [], int *);
int checkForComments(char [], int *,char [], int *);
int removeSingleLineComments(char [], int **,char [], int **);
int removeMultilineComments(char [], int **,char [], int **);
int ignoreStringLiterals(char [], int **,char [], int **);

void main()
{
	char input[CODESIZE], output[CODESIZE];
	FILE *p;
	getInput(p,input);
	checkAndRemoveComments(input,output);
	printf("%s\n\n", input );
	printf("%s",output);
}

int getInput(FILE *p, char input[])
{
	char ch;
	int input_index = 0;

	p = fopen("input_1_23.c","r");
	while( (ch=fgetc(p)) != EOF )
		input[input_index++] = ch;
	input[input_index] = '\0';
}

int checkAndRemoveComments(char input[],char output[])
{
	int input_index = 0,output_index = 0;

	while( input[input_index] != '\0')
	{
		checkForString(input,&input_index,output,&output_index);

		checkForComments(input,&input_index,output,&output_index);

		output[output_index] = input[input_index];
		output_index++; input_index++;
	}

	output[output_index] = '\0';
	return 0;
}

int removeSingleLineComments(char input[], int **input_index, char output[], int **output_index)
{
	while( input[(**input_index)++] != '\n');
	output[(**output_index)++] = input[--(**input_index)];		
	return 0;
}

int removeMultilineComments(char input[], int **input_index, char output[], int **output_index)
{
	while(1)
	{
		++(**input_index);
		if(input[(**input_index)] == '*' && input[++(**input_index)] == '/')
		{
			++(**input_index);
			break;
		}
	}
	return 0;
}

int ignoreStringLiterals(char input[], int **input_index, char output[], int **output_index)
{
	++(**input_index);
	while( input[(**input_index)] != '"')
	{
		output[(**output_index)] = input[(**input_index)];
		(**output_index)++; (**input_index)++;
	}
	output[(**output_index)] = '"';
	return 0;
}

int checkForString(char input[], int *input_index, char output[], int *output_index)
{	
	if( input[(*input_index)] == '"')
		ignoreStringLiterals(input,&input_index,output,&output_index);
}

int checkForComments(char input[], int *input_index, char output[], int *output_index)
{
	if( input[(*input_index)] == '/' )
		{
			++(*input_index);
			if( input[(*input_index)] == '/' )
				removeSingleLineComments(input,&input_index,output,&output_index);
			
			if( input[(*input_index)] == '*' )
				removeMultilineComments(input,&input_index,output,&output_index);
		}
}