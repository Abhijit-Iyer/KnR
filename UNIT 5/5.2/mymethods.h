#if !defined(MYMETHODS)

#define LINESIZE 1000	//For string lines
#define BUFSIZE 100 // For expressions and integers


#define swap(data_type, parameter_1, parameter_2) { data_type temp; \
													temp = parameter_1; \
													parameter_1 = parameter_2; \
													parameter_2 = temp; } 
													// swaps parameter 1 and parameter 2 of datatype

int getline(char []);			//Takes a line of string characters from the console and stoes them in char []
int reverseString(char [],char [],int);	//Reverses a string of characters (input_string[], output_string[], strlen(input_string[]))
int removeSpaces(char [],char []);	//Removes trailing spaces from input_string[] and stores them in output_string[]
void copy(char [],char []); //Copies contents from one character buffer to another
int htoi(char *, int);	// Converts a hexadecimal number to an integer (hexadecimal string[], strlen(hexadecimal string[]) - 1)
int squeeze(char [],char [],char []); //Removes similar characters present in buffer1[] and buffer2[] and stores them in buffer_output[] 
int lower(int ch); //Converts upper case alphabets to lower case (the upper case alphabet)
int sort_array(int [],int *); //Sorts a given array int[] whose array size is int *
int binary_search(int [],int *); //Performs binary search on a given array (array, arraysize)
int expand(char [], char[]);	//Expands shorthand notations like a-z, 0-9 present in line[] and stores them in newline[]
int expander(char [], char[], int *, int *);	//Performs the expansion of above declaration
int reverse(char []); //Reverses a string []
int itoa();	//Converts an integer number and stores them digit by digit in a character buffer
int itob(int, char [], int);	//Converts integer 'n' to base b and stores the resukt in buffer s[]
int strrindex(char[],char[]);	// strrindex(line,pattern), which returns the index of the last occurence of pattern found in line 
int comparator(int *, int *, int *, char [], char []);	// compares the line and pattern of the above strrindex
char getch();	//Returns a character from console (or) from a push_back buffer
void ungetch(int);	//Pushes back a read character into a pushback buffer for future use

 #endif