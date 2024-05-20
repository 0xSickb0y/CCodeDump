#include <stdio.h>

// '*' dereference operator tells the calc() function to receive an memory address
// of a integer, instead of creating a new integer

void calc(int* c) {
	printf("\n< CALC FUNCTION >\n");
	// 'c' variable in this scope is the same on from main()

	// tells the program to enter the 'value' of that memory address to perform the operation
	// otherwise, c++ would do: 0x00000000 +1 (0x00000001)
	(*c)++;
	printf("address > %d\n", c);
	printf("value > %d\n", (*c));
}


int main() {
	// '&' char reserved for getting the address of the variable in memory
	printf("< MAIN FUNCTION >\n");
	int c = 10;
	printf("address > %d\n", &c);
	printf("value > %d\n", c);

	// pass the address of the 'c' variable to the calc function
	// instead of creating a new one inside the function scope
	calc(&c);
}