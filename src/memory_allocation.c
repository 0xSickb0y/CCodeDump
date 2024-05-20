#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void integer_allocation() {
    // manually assign 4 bytes to 'number'
    int* first_number = malloc(4);
    // get the byte size of 'int' based on compiler and the target platform
    int* second_number = malloc(sizeof(int));
    // increment the pointer by 1 (4 bytes) and manually assign 'third_number' to the next memory address
    int* third_number = second_number + 1;

    // assign integers to the *_number variables
    *first_number = 10;
    *second_number = 20;
    *third_number = 30;

    // print memory address and value
    printf("allocated memory space %p to value: %d\n", first_number, (*first_number));
    printf("allocated memory space %p to value: %d\n", second_number, (*second_number));
    printf("allocated memory space %p to value: %d\n", third_number, (*third_number));

    // free memory space
    free(first_number);
    free(second_number);
}

void array_allocation() {

	// get the byte size of 'char' based on compiler and the target platform. Assign 6 characters for 'string' + 1 for null terminator
	char* string = malloc(sizeof(char) * 7);

	// assign value to 'string'
	strcpy(string, "string");

	// print memory address and value
	printf("allocated memory space %p to value: %s\n", (void*)string, string);

    // free memory space
    free(string);
}

void matrix_allocation() {
    // Declare matrix dimensions
    int rows = 5;
    int columns = 10;

    // declare a pointer to a pointer to int to represent the matrix
    int **matrix;

    // allocate memory for the rows
    matrix = (int **)malloc(rows * sizeof(int *));

    // allocate memory for each row
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(columns * sizeof(int));
    }

    // print memory address and value
    printf("allocated memory space %p to value:\n\n", (void*)matrix);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // free memory space
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    integer_allocation();
    printf("\n");

    array_allocation();
    printf("\n");

    matrix_allocation();
    printf("\n");

    return 0;
}
