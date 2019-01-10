/* CS261- Assignment 1 - Q.0*/
/* Name: George Lenz
 * Date: 4/17/2018
 * Solution description: finds address of pointer, variable, and variable value
 */
 

#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value of iptr*/
	printf("Values from foo function:\n");
	printf("value: %d\n", *iptr);
		/*Print the address pointed to by iptr*/
		printf("address: %p\n", iptr);
     /*Print the address of iptr itself*/
		printf("pointer address: %p\n\n", &iptr);
     /*Change the value of iptr itself*/
		*iptr = 9;
         
}

int main(){
    
    /*declare an integer x and initialize it randomly to a value in [0,10] */
	int x = rand() % 11;
    /*Print the address of x*/
	printf("X address from main: %p\n\n", &x);
		/*Call fooA() with the address of x*/
	fooA(&x);

		/*Print the value of x*/
	printf("x value after foo: %d\n", x);
    /*Answer the question */
    
    return 0;
   
    
}


