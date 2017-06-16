//Reverse Polish Calculator with getline() instead of getch() and ungetch().

#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define LINESIZE 10000
#define MAXOP 100
#define NUMBER '0'
#define STRING '1'

int getline();
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

	getline();
//	return 0;

	expression_handler();

	return 0;

}

void expression_handler()
{
	int type;
	double op2;
	char operand_operator[MAXOP], exit_value = 0;

	while( exit_value != EOF && (type = getop(operand_operator)) != EOF )
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
								getchar();
								stack_handler();
							}
							else
								getchar();				// To read '\n' that was entered after 'n'.

							printf("\n\n Enter EOF character to exit.");
							exit_value = getchar();
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
							printf("\n Would you like to call the stack handler?(y/n) : " );
							if( getch() == 'y' )
							{
								getchar();
								stack_handler();
							}
							else
								getchar();				// To read '\n' that was entered after 'n'.

							printf("\n\n Enter EOF character to exit.");
							exit_value = getchar();
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

char line[LINESIZE];

int getline()
{
	char ch;
	int index=0, limit = LINESIZE;

	while((ch=getchar()) != EOF && ch!='\n' && limit-- != 0)
		line[index++] = ch;
	if(ch == '\n')
	{
		line[index++] = ch;
	}
	line[index] = '\0';

	return index;
}

int getop(char s[])
{
	int i = 0;
	static int index = 0;
	char c, flag = 0;

	while(( c = line[index] ) == ' ' || c == '\t')
		index++;

	s[i] = c; s[1] = '\0';

	if( s[i] == '-' && isdigit( s[++i] = line[++index]) )
	{
		flag = 1;						//shows that the number is negative
	}

	if(isalpha(s[i]))
		while(isalpha(s[++i] = c = line[++index]))
			;

	if(isalpha(s[i-1]))
	{
		s[i] = '\0';
		return STRING;
	}

	if(!isdigit(c) && c != '.' && flag == 0)
	{
		++index;		/* Here, anything except numbers or alphabets get returned.
								In this process, the index of the line buffer never
								gets incremented in other steps. Hence, we're explicitly
								doing it here	*/
		return c;
	}

	while(isdigit(s[++i] = c = line[++index]))
		;

	if( s[i] == '.')
		while(isdigit(  s[++i] = c = line[++index] ) )
			;	

	s[i] = '\0';

	return NUMBER;
}

/*int check_for_pushback = 0;
char pushed_back_character;

void ungets(char s[])
{
	int s_index = 0;

	while(s[s_index] != '\0')
		ungetch(s[s_index]);	
}

char getch(void)
{
	if (check_for_pushback > 0) 
	{
		--check_for_pushback;
		 return pushed_back_character;
	}
	else
		getchar();
}

void ungetch(int c)
{
	if(c == EOF)
		return;	
		
	pushed_back_character = c;
	++check_for_pushback;
}*/