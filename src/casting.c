#include <stdio.h>

int main() {
	int base = 100;
	int first_num = 2;
	float second_num = 2.5;

	printf("This is a demo script for 'casting' in C.\n");
	printf("base number is %d\n", base);

	int int_casting = base / (int)second_num;
	double float_casting = base / (float)first_num;

	printf("\n%d divided by (float)%d == %.1f\n", base, first_num, float_casting);
	printf("\n%d divided by (int)%.1f == %d\n", base, second_num, int_casting);

}