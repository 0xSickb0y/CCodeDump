#include <stdio.h>
#include <stdlib.h>

void write_file(char* text_to_write) {
	// declare 'f' variable as a FILE pointer
	FILE* f;

	// open 'output.txt' in write mode;
	f = fopen("output.txt", "w");

	// insert the 'Hello, World!' string to the file
	fprintf(f, "%s\n", text_to_write);

	// insert string directly instead of the array
	fprintf(f, "I'm the new string\n");

	//close the file
	fclose(f);
}

int main() {
	// assign a string to 'text_to_write'
	char text_to_write[] = "Hello, World!";

	// display some output
	printf("printing %s to 'output.txt'\n", text_to_write);

	// call write_file() function
	write_file(text_to_write);

}