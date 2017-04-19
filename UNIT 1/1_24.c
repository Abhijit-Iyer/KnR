#include<stdio.h>

#define CODESIZE 1000000

int populateInputBufferFromFile(FILE *, char []);
int checkForRudimentarySyntaxErrors(char []);
int ignoreStringLiterals(char [], int **, int **);
int checkBraces(char [], int*, int*);
int checkBrackets(char [], int*, int*);
int checkDoubleQuotes(char [], int*, int*);
int checkSingleQuotes(char [], int*, int*);
int checkComments(char [], int*);
int removeSingleLineComments(char [], int **);
int removeMultilineComments(char [], int **);
int printFinalStatus(int, int, int);

void main()
{
	char input[CODESIZE];
	FILE *p;

	populateInputBufferFromFile(p,input);
	
	checkForRudimentarySyntaxErrors(input);
}

int populateInputBufferFromFile(FILE *p, char input[])
{
	char ch;
	int input_index = 0;

	p = fopen("input_1_24.c","r");
	while( (ch=fgetc(p)) != EOF )
		input[input_index++] = ch;
	input[input_index] = '\0';
}

int checkForRudimentarySyntaxErrors(char input[])
{
	int input_index = 0, bracecount = 0, bracketcount = 0,
	 doublequotes = 0, singlequote = 0;

	while(input[input_index] != '\0')
	{
		checkBraces(input,&input_index,&bracecount);	

		checkBrackets(input,&input_index,&bracketcount);

		checkDoubleQuotes(input,&input_index,&doublequotes);	

		checkSingleQuotes(input,&input_index,&singlequote);

		checkComments(input,&input_index);

		input_index++;

	}

	printFinalStatus(bracecount,bracketcount,singlequote);

	return 0;

}

int printFinalStatus(int bracecount, int bracketcount, int singlequote)
{
	if(bracecount != 0)
		printf("Please handle the curly braces properly.\n");

	if(bracketcount != 0)
		printf("Please handle the brackets properly.\n");

	if(singlequote != 0)
		printf("Please handle single quotes peoperly. \n"); 

	if(bracecount == 0 && bracketcount == 0 && singlequote == 0)
		printf("Good Job! No Rudimentary Syntax Errors! Keep the good work up! \n");

	return 0;
}

int ignoreStringLiterals(char input[], int **input_index,int **doublequotes)
{
	++(**input_index);
	while( input[(**input_index)++] != '"' && input[(**input_index)] != EOF);
	(**doublequotes)--;
	return 0;
}

int removeSingleLineComments(char input[], int **input_index)
{
	while( input[(**input_index)++] != '\n');
	--(**input_index);		
	return 0;
}

int removeMultilineComments(char input[], int **input_index)
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

int checkBraces(char input[], int *input_index, int *bracecount)
{
	if(input[(*input_index)] == '{')
		(*bracecount)++;

	if(input[(*input_index)] == '}')
		(*bracecount)--;
}

int checkBrackets(char input[], int *input_index, int *bracketcount)
{
	if(input[(*input_index)] == '(')
		(*bracketcount)++;

	if(input[(*input_index)] == ')')
		(*bracketcount)--;
}

int checkDoubleQuotes(char input[], int *input_index, int *doublequotes)
{
	if( input[(*input_index)] == '"')
	{
		(*doublequotes)++;
		ignoreStringLiterals(input,&input_index,&doublequotes);
		(*input_index)--;
	}
}

int checkSingleQuotes(char input[], int *input_index, int *singlequote)
{
	if( input[(*input_index)] == '\'')
		{
			(*singlequote)++;
			if( input[(*input_index) = (*input_index) + 2] == '\'' 
				|| input[(*input_index) = (*input_index) + 1] == '\'')
			{
				(*singlequote)--;
			}
		}
}

int checkComments(char input[], int *input_index)
{
	if( input[(*input_index)] == '/' )
	{
		++(*input_index);
		if( input[(*input_index)] == '/' )
			removeSingleLineComments(input,&input_index);
		
		if( input[(*input_index)] == '*' )
			removeMultilineComments(input,&input_index);
	}
}