//Reverse Polish Calculator with ungets()

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'
#define STRING '1'

void expression_handler();
void push(double);
double pop();
int getop(char []);
char getch();
void ungetch(int);
void stack_handler();
void top_of_stack();
void duplicate();
void swap_stack();
void clear_stack();
void scientific_notations(char []);

int main()
{
	
	printf("\n Enter the postfix expression : ");

	expression_handler();

	return 0;

}

void expression_handler()
{
	int type;
	double op2;
	char operand_operator[MAXOP];

	while( (type = getop(operand_operator)) != EOF )
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
							printf("\n Would you like to call the stack handler?(y/n) : " );
							if( getch() == 'y' )
							{
								getchar();
								stack_handler();
							}
							else
								getchar();				// To read '\n' that was entered after 'n'.

							printf("\n\n Enter EOF character to exit (or) enter another postfix expression to continue : ");
							break;

			case '%'	:	op2 = pop();
							if( op2 == 0 )
								printf("\n Modulo Zero error. ");
							else
								fmod( pop() , op2);
							break;

			case STRING	:	scientific_notations(operand_operator);
							break;

			default		: 	printf("\n Unknown symbol ' %s 'in the input. o_0",operand_operator);
							break;
		}
	}
}

void scientific_notations(char s[])
{
	double temp;

	if(strcmp(s,"sin") == 0)
	{
		//printf("\n string = %s");
		push(sin(pop()));
	}

	if(strcmp(s,"exp") == 0)
		push(exp(pop()));

	if(strcmp(s,"pow") == 0)
	{
		temp = pop();

		push(pow(pop(), temp));
	}

	// More mathematical functions can be added in this routine
}

// STACK BASED ROUTINES

void stack_handler()
{
	char ch;

	printf("\n Press: \n");
	printf(" 1 - for top_of_stack();\n 2 - for duplicate();\n 3 - for swap_stack();\n 4 - for clear_stack(); \n\n Choice : ");
	ch = getchar();
	getchar();				// To bypass the '\n' entered after the choice entered. 
	switch(ch)
	{
			case '1'	:	top_of_stack();
							break;		

			case '2'	: 	duplicate();
							break;		

			case '3'	:	swap_stack();
							break;	

			case '4'	:	clear_stack();
							break;

			default		: 	printf("\n No such choice available. ");
							break;
	}
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

void duplicate()
{
	double top_of_stack;

	top_of_stack = pop();
	push(top_of_stack);
	push(top_of_stack);
}

void top_of_stack()
{
	if(stack_pointer > 0)
		printf("\n The element at the top of stack is %c at the index %d. ",stack[stack_pointer-1],stack_pointer);	
	else
		printf("\n Stack is empty."); 	
}

void swap_stack()
{
	double top, top_minus_one;

	top = pop();
	top_minus_one = pop();

	push(top_minus_one);
	push(top);
}

void clear_stack()
{
	while(stack_pointer != 0)
		stack[--stack_pointer] = '\0';
}

// ROUTINES THAT DEAL WITH INPUT EXPRESSION

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

	if(isalpha(s[i]))
		while(isalpha(s[++i] = c = getch()))
			;

	if(isalpha(s[i-1]))
	{
		s[i] = '\0';
		return STRING;
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

void ungets(char s[])
{
	int s_index = 0;

	while(s[s_index] != '\0')
		ungetch(s[s_index]);	
}

char getch(void)
{
	return (check_for_ungetch > 0) ? temporary_buffer[--check_for_ungetch] : getchar();
}

void ungetch(int c)
{
	temporary_buffer[check_for_ungetch++] = c;
}