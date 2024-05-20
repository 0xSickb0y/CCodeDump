#include <stdio.h>

void matrix_numbers() {
	// declare the matrix with 10x10
    int matrix[10][10];
    int i, j;

    // fill the matrix with 0-200 integers
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            matrix[i][j] = i * 10 + j;
        }
    }

    // print the matrix
    printf("1° matrix:\n\n");
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 10; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void matrix_pointers() {
    // declare the matrix with 10x10
    int matrix[10][10];
    int i, j;

    // assign a pointer to 'matrix'
    int (*copy)[10] = matrix;

    // assign integers (37 and 38) to the first two positions of the matrix
    matrix[0][0] = 37;
    copy[0][1] = 38;

    printf("\n2° matrix:\n\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%4d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {

	matrix_numbers();
	matrix_pointers();
}
