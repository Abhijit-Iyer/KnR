# K&R EXERCISE 5.2

----							
## OBJECTIVE

>Creating a function getfloat(float *), that would read a floating point number(a series of 
number characters) from the console and store them in a specific memory address. 

----
## FILES PRESENT

* main.c
* input_output.c
* get_float.c
* Utilities.c
* headers.h

----
## main.c

### void main()

    Parameters Received : 
        None

    Return Value :
        0 upon successful completion

    Return Type :
        void

    Role :
        Makes function calls to four main functions, and generates the flow of the entire program.

----

## input_output.c

### get_maxsize()

    Parameters Received : 
        int *maxsize

    Return Value :
        0 upon successful completion
    
    Return Type :
        integer 

    Role :
        Displays a message that prompts the user to enter the max-size of the array, and takes the value of max-size from the user and stores it in the address of variable maxsize.

### prompt-user-to-enter-array-elements()

    Parameters Received : 
        None

    Return Value :
        0 upon successful completion

    Return Type :
        integer

    Role :
        Displays a message that prompts the user to enter the elements to be entered into the array as float.

### display-array()

    Parameters Received : 
       None

    Return Value :
        0 upon successful completion

    Return Type:
        integer

    Role :
        Displays the elements present in the array.
