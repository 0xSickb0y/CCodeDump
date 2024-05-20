#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int first_number = rand(); // take a 'random' number
	int second_number = (rand() % 100); // take the 0-99 remainder of a 'random' number
	srand(time(0)); // srand(time(0)); seeds the random number generator with the elapsed time since the epoch, subsequent calls to rand() will produce pseudo-random numbers based on that seed.
	int third_number = rand();

	printf("This is a demo script for 'randomness' in C.\n");

	printf("\nfirst number: %d\n", first_number);
	printf("\nsecond number (0-99): %d\n", second_number);
	printf("\nthird number (time seed): %d\n", third_number);
}