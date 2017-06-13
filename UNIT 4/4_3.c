// REVERSE POLISH CALCUATOR

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

void push(double);
double pop();
int getop(char []);
char getch();
void ungetch(int);

int main()
{
	int type;
	double op2;
	char operand_operator[MAXOP];

	printf("\n Enter the Postfix Expression : ");

	while((type = getop(operand_operator)) != EOF)
	{
		switch(type)
		{
			case NUMBER:	push(atof(operand_operator));
							break;

			case '+'   :	push(pop() + pop());
							break;

			case '-'	:	op2 = pop();  
							push(pop() - op2);
							break;

			case '*'	:	push(pop() * pop());
							break;

			case '/'	:	op2 = pop();
							if( op2 == 0 )
								printf("\n Zero division error. ");
							else
								push(pop() / op2);
							break;

			case '\n'	:	printf("\n Result = %lf \n",pop());
							break;

			case '%'	:	op2 = pop();
							if( op2 == 0 )
								printf("\n Modulo Zero error. ");
							else
								fmod( pop() , op2);
							break;

			default		: 	printf("\n Unknown symbol ' %s 'in the input. o_0",operand_operator);
							break;
		}
	}

	return 0;

}

#define STACK_SIZE 100

int stack_pointer = 0;
double stack[STACK_SIZE];

void push(double f)
{
	if(stack_pointer < STACK_SIZE)
		stack[stack_pointer++] = f;
	else
		printf("\nStack is full\n");
}

double pop()
{
	if( stack_pointer > 0 )
		return 	stack[--stack_pointer];
	else
	{
		printf("\n The stack is empty.");
		return 0.0;
	}
}

int getop(char s[])
{
	int i = 0;
	char c, flag = 0;

	while(( c = getch() ) == ' ' || c == '\t')
		;
	s[i] = c; s[1] = '\0';

	if( s[i] == '-' && isdigit( s[++i] = getch()) )
	{
		flag = 1;						//shows that the number is negative
	}

	if(!isdigit(c) && c != '.' && flag == 0)
		return c;

	while(isdigit(s[++i] = c = getch()))
		;
	if( s[i] == '.')
		while(isdigit(  s[++i] = c = getch() ) )
			;
	s[i] = '\0';

	if( c!= EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFSIZE 100

int check_for_ungetch = 0;
char temporary_buffer[BUFSIZE];

char getch(void)
{
	return (check_for_ungetch > 0) ? temporary_buffer[--check_for_ungetch] : getchar();
}

void ungetch(int c)
{
	temporary_buffer[check_for_ungetch++] = c;
}