#include <stdio.h>
#include <stdlib.h>

int main() {
	int first_num = 2;
	int second_num = -2;
	float third_num = -2.5;

	printf("This is a demo script for 'absolute converting' in C.\n");
	printf("base numbers are %d, %d and %.1f\n", first_num, second_num, third_num);

	int abs_first = abs(second_num);
	int abs_second = abs(first_num * second_num);
	int abs_third = abs(third_num);

	printf("\nabs(%d) is %d\n", second_num, abs_first);
	printf("\nabs(%d * %d) is %d\n", first_num, second_num, abs_second);
	printf("\nabs(%.1f) is %d\n", third_num, abs_third);
}