#if !defined(HEADERS)

#define LINESIZE 1000	//For string lines
#define BUFSIZE 100 // For expressions and integers


char getch();	//Returns a character from console (or) from a push_back buffer
void ungetch(int);	//Pushes back a read character into a pushback buffer for future use

int get_maxsize(int *);
int prompt_user_to_enter_array_elements();
int process_input_and_convert_to_float(float [], int);
int getfloat(float *);
int skip_spaces(char *);
int check_for_invalid_character(char *);
int check_for_sign(char *, char *);
int get_characteristic(char *, float *);
int get_mantissa(char *, float *, int *);
int display_array(float [], int);

 #endif