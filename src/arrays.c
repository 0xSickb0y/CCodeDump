#include <stdio.h>

int main () {
	int nums[3];

	nums[0] = 10;
	nums[1] = 9;
	nums[2] = 8;
	nums[3] = 8;
	nums[4] = 7;

	// iterate through the 'nums' array
	for (int i = 0; i < 5; i++) {
		printf("%d", nums[i]);
	}
}