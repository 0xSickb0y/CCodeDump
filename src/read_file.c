#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void read_file(char* random_word) {
	// declare 'f' variable as a FILE pointer
	FILE* f;

	// open 'wordlist.txt' in read mode
	f = fopen("wordlist.txt", "r");

	int word_count;

	// read first line of the wordlist (No. lines)
	fscanf(f, "%d", &word_count);

	//take current time and use it as seed for randomness
	srand(time(0));

	// gets the remainder of the (rand() / word_count) and assign it to random_num
	int random_num = rand() % word_count;

	// iterate trough lines to get to 'random_num' location
	for (int i = 0; i <= random_num; i++) {
		// assign the value to 'random_word'
		fscanf(f, "%s", random_word);
	}
	// close the file
	fclose(f);
}

int main() {
	// declare random_word char array
	char random_word[15];

	//call the read_file() function
	read_file(random_word);

	// print random_word to the terminal
	printf("%s\n", random_word);
}