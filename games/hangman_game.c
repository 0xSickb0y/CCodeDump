#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

char secret_word[] = "\x66\x6c\x6f\x70\x70\x61"; // not very hard isn't it?
char alphabet_array[26];
int tries = 0;

void banner() {
    printf("Welcome to hangman_game.c! Can you guess what the secret word is?\n");
    printf("max errors: 7\n\n");
    printf("⠈⢿⣿⣿⣿⣿⣿⣿⠄⠀⠀⠀⠀⠀⢀⣀⣀⣀⠀⣀⣀⣴⣼⣿⣿⣿⣿⣿⣿⡏\n");
    printf("⠀⠘⣷⢿⣿⣿⣿⣿⣤⣤⣶⣶⣶⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡗\n");
    printf(" ⠀⢸⠟⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠇\n");
    printf(" ⠀⠈⡷⢲⣿⣿⣯⣿⣿⣿⣿⠛⢻⣿⣿⣿⣿⣿⣿⣿⣿⠉⢻⣿⣿⣿⣿⣿⡁\n");
    printf("  ⠀⠈⢋⣾⡿⢿⣿⣿⣿⡇⠈⣿⣿⣿⣿⣿⣿⣿⣿⡀⣾⣿⣿⣿⣿⣿⣿:\n");
    printf("  ⠀⠀⠀⣠⣾⣿⠧⠟⠛⠉⢙⠁⢶⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠀⠂⡉⣿⣿⣿⣿⡄\n");
    printf("  ⠀⠀⠀⣿⢻⣧⣶⣄⢀⠀⠀⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⠇⢤⣀⣴⣽⣿⣿⣿⣿⣿⣆\n");
    printf("  ⠀⠀⢠⣿⠸⣿⣿⣿⣷⣦⣄⠀⠀⢻⣿⣿⣿⣿⣿⣿⣿⠙⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦⡀\n");
    printf("  ⠀⠀⣾⣿⡀⠹⠿⢿⣿⣿⣿⡆⠀⠘⣿⣿⣿⣿⣿⣿⣿⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣦\n");
    printf("  ⠀⢰⣿⣿⣿⡀⠀⠘⠻⣿⡿⠃⠀⠀⠙⢿⣿⣿⣿⣿⠇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("  ⠀⣼⣿⣿⣿⣿⣦⣄⠀⠀⠀⢲⣤⡀⠀⠀⢿⣿⣿⡿⢂⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("  ⠀⣿⣿⣿⣿⣿⣿⣿⣷⡄⠀⠛⢿⣷⣄⠀⠀⠈⣁⣤⣾⣿⣿⣿⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("  ⠀⣿⣿⣿⣿⣿⣿⣿⣿⣷⠀⠰⠿⣿⣿⣷⣄⠀⣸⣿⣿⣿⣿⡟⣹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("  ⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠐⠛⢛⢋⡿⠃⢿⣭⣿⡿⠉⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("  ⠀⣿⣿⣯⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⣼⣿⣵⣶⣶⣿⣿⣷⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
}


void input_guess() {
    char guess;
    printf(">>> ");
    scanf(" %c", &guess);
    guess = tolower(guess);
    alphabet_array[tries] = guess;
}

int already_tried(char letra) {
    int found = false;
    for (int j = 0; j < tries; j++) {
        if (alphabet_array[j] == letra) {
            found = true;
            break;
        }
    }
    return found;
}

void print_hangman() {
    for (int i = 0; i < strlen(secret_word); i++) {
        if (already_tried(secret_word[i])) {
            printf("%c ", secret_word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n\n");
}

int hanged() {
	int error_count = 0;
	for (int i = 0; i < tries; i++) {
		bool exists = false;
		for (int l = 0; l < strlen(secret_word); l++) {
			if (alphabet_array[i] == secret_word[l]) {
				exists = true;
				break;
			}
		}
		if (!exists) error_count++;
	}
	return error_count >= 7;
}

int win() {
	for (int i = 0; i < strlen(secret_word); i++) {
		if (!already_tried(secret_word[i])) {
			return false;
		}
	}
	return true;
}

int main() {
    banner();
    do {
        print_hangman();
        input_guess();
        tries++;
    } while (!win() && !hanged());

    if (win()) {
		printf("You won :)\n");
		printf("the secret word is %s!\n", secret_word);
    } else {
		printf("you lost :(\n");
    }
}
