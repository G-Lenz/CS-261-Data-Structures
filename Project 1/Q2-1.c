/* CS261- Assignment 1 - Q.2*/
/* Name: George Lenz
 * Date: 4/17/2018
 * Solution description: Generates 3 random numbers and changes the value of the first 2
 */
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /* Increment a */
	*a = *a + 1;
    
    /* Decrement  b */
    *b=*b - 1;
    /* Assign a+b to c */
	c = *a + *b;
    /* Return c */
	return c;
}

int main(){
    /* Declare three integers x,y and z and initialize them randomly to values in [0,10] */
	int x = rand() % 10;
	int y = rand() % 10;
	int z = rand() % 10;
    /* Print the values of x, y and z */
	printf("X: %d\nY: %d\nZ: %d\n", x, y, z);

	/* Call foo() appropriately, passing x,y,z as parameters */
	int returned = foo(&x, &y, z);
    
    /* Print the values of x, y and z */
	printf("X: %d\nY: %d\nZ: %d\n", x, y, z);
    
    /* Print the value returned by foo */
	printf("Returned by foo: %d\n", returned);
 
    
    return 0;
}
    
    

