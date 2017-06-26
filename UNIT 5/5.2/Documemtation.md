#K&R EXERCISE 5.2

----							
##OBJECTIVE

>To create a function getfloat(float *), that would read a floating point number(a series of characters) from the console and store them in a specific memory address. 
In the framework given in the book(The C Programming Language), any non integer character present after a sign is treated as zero. 
We had to manipulate that and the manipulation is done.

----
##METHODS PRESENT

* main();

>>Takes the no. of elements to be read in all from the console, calls the method getfloat();as many times and finally, displays the elements read.
			
* getint(float *);
			
>>The function getfloat(float *) reads a character/series of characters from the console, converts them into a floating point number(if valid) and stores them in the memory address passed by the caller.

----
##METHOD DESCRIPTIONS
###main()         

	Parameters passed :
		None

	Returns :
		0 upon successful completion 

	Role :
		Takes the no. of elements to be read in all from the console, calls the method getfloat();
		as many times and finally, displays the elements read.

----
###getfloat(float *address)

	Parameters passed : 
			int *address (the address where the integers is to be stored)

	Returns :
			Upon successful completion, the last character read.
		Else
			Returns 0 with an error message.

	Role :

		Read a floating point number from the console, along with it's sign, and stores it int the address passed.
