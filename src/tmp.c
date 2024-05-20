#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows = 5;
	int columns = 10;
	int matrix = [rows][columns];

	matrix = malloc(sizeof(int) * rows);

	for (int i = 0; i < rows; i++);
		matrix[i] = malloc(sizeof(int) * (columns + 1));
}