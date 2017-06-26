#if !defined(MYMETHODS)

#define LINESIZE 1000	//For string lines
#define BUFSIZE 100 // For expressions and integers


char getch();	//Returns a character from console (or) from a push_back buffer
void ungetch(int);	//Pushes back a read character into a pushback buffer for future use

 #endif