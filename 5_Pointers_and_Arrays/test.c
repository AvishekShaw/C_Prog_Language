# include <stdio.h>

void main(){
	int x, *ptr;
	x = 10;
	ptr = &x;
	printf("The value of x is %d \n", *ptr);
	printf("Pointer points to the address of x at %d \n",ptr);
	printf("However, if I increment the pointer, it gives %d \n", ++ptr);
	printf("The value of the new pointer variable is %d \n", ptr);
	printf("The value at which the new pointer points to is: %f \n", *ptr);
	printf("I can use the dereferencing command *ptr to access the value stored at x \n");
	printf("An expresssion *ptr+=5 should increase the value stored in the variable x \n");
	printf("The value after increasing x is : %d \n", *ptr+=5);
}