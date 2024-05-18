#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	srand(time(0));
	int secret_number = rand() % 100;

	int guess;
	int level;
	int max_tries;
	int error_count = 0;
	bool good_guess = false;
	double score = 1000;

	printf("Hello, User!\n");
	printf("Can you guess the secret number? [0-99]\n");

	while (true) {
	    printf("Difficulty level: [Easy (1) Medium (2) Hard (3) Insane (4)]\n>>> ");
	    scanf("%d", &level);

	    switch (level) {
	        case 1:
	            max_tries = 20;
	            break;
	        case 2:
	            max_tries = 10;
	            break;
	        case 3:
	            max_tries = 5;
	            break;
	        case 4:
	            max_tries = 1;
	            break;
	        default:
	            printf("\nInvalid option!\n");
	            continue;
	    }
	    break;
	}

	for (int i = 1; i <= max_tries; i++) {

		printf("\n(Attempt %d)\n>>> ", error_count + 1);
		scanf("%d", &guess);

		if (guess < 0 || guess > 99) {
			printf("Invalid guess, try again!\n");
			continue;
		}
		if (guess > secret_number) {
			printf("Oops, answer too high.\n");
		}

		else if (guess < secret_number) {
				printf("Oops, answer too low.\n");
			}

		else {
			good_guess = true;
			break;
		}

		error_count++;
	}

	if (good_guess){
		printf("\nYou won the game!!!\n");
		printf("The right answer was %d\n", secret_number);
	}

	else {
		printf("\nYou lost the game!!!\n");
		printf("The right answer was %d\n", secret_number);
	}

	double lost_points = abs(guess - secret_number) / (float)2;
	score = score - lost_points;

	printf("\nerrors: %d\n", error_count);
	printf("\nscore: %.1f\n", score);

}

