//Reverse Polish Calculator with provision for mathematical functions under math.h

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
void stack_handler();
void top_of_stack();
void duplicate();
void swap_stack();
void clear_stack();
void scientific_notations();

int main()
{
	int type;
	double op2;
	char operand_operator[MAXOP];

	printf("\n Would you like to use scientific notations?(y/n) ");
	type = getchar(); getchar(); // To bypass '\n entered after the choice.'
	if(type == 'y')	
		scientific_notations();

	printf("\n Enter the Postfix Expression : ");

	while( (type = getop(operand_operator)) != EOF)
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
							if( getchar() == 'y' )
							{
								getchar();				// To read '\n' that was entered after 'y'.
								stack_handler();
								break;
							}
							else
							{
								getchar();				// To read '\n' that was entered after 'n'.
								break;
							}

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

void scientific_notations()
{
	char ch;
	char value;

	printf("\n Enter : \n 1. for sin(); \n");
	ch = getchar(); getchar();	//For bypassing '\n'

	printf("\n Enter the value for which you'd like to calculate : ");
	value = getchar();
	switch(ch)
	{
		case '1' : 	push(sin(value));
					break;

		default	 :	printf("\n Wrong Choice. ");
					break;	
	}
}

void stack_handler()
{
	char ch;

	printf("\n Press: \n");
	printf(" _ for top_of_stack();\n ! for duplicate();\n @ for swap_stack();\n # for clear_stack(); :");
	ch = getchar();
	getchar();				// To bypass the '\n' read after the choice entered. 
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