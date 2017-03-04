#include<stdio.h>

#define CODESIZE 1000000

int getInput(FILE *, char []);
int checkComments(char [], char[]);
int removeSingleLineComment(char [], int *,char [], int *);
int removeMultilineComment(char [], int *,char [], int *);
int checkStringLiteral(char [], int *,char [], int *);

void main()
{
	char input[CODESIZE], output[CODESIZE];
	FILE *p;
	getInput(p,input);
	checkComments(input,output);
	printf("%s\n\n", input );
	printf("%s",output);
}

int getInput(FILE *p, char input[])
{
	char ch;
	int input_index = 0;

	p = fopen("input.txt","r");
	while( (ch=fgetc(p)) != EOF )
		input[input_index++] = ch;
	input[input_index] = '\0';
}

int checkComments(char input[],char output[])
{
	int input_index = 0,output_index = 0;
	while( input[input_index] != '\0')
	{
		if( input[input_index] == '"')
			checkStringLiteral(input,&input_index,output,&output_index);

		if( input[input_index] == '/' )
		{
			++input_index;
			if( input[input_index] == '/' )
				removeSingleLineComment(input,&input_index,output,&output_index);
			
			if( input[input_index] == '*' )
				removeMultilineComment(input,&input_index,output,&output_index);
		}

		output[output_index] = input[input_index];
		output_index++; input_index++;
	}

	output[output_index] = '\0';
	return 0;
}


int removeSingleLineComment(char input[], int *input_index, char output[], int *output_index)
{
	while( input[(*input_index)++] != '\n');
	output[(*output_index)++] = input[--(*input_index)];		
	return 0;
}

int removeMultilineComment(char input[], int *input_index, char output[], int *output_index)
{
	while(1)
	{
		++(*input_index);
		if(input[(*input_index)] == '*' && input[++(*input_index)] == '/')
		{
			++(*input_index);
			break;
		}
	}
	return 0;
}

int checkStringLiteral(char input[], int *input_index, char output[], int *output_index)
{
	++(*input_index);
	while( input[(*input_index)] != '"')
	{
		output[(*output_index)] = input[(*input_index)];
		(*output_index)++; (*input_index)++;
	}
	output[(*output_index)] = '"';
	return 0;
}