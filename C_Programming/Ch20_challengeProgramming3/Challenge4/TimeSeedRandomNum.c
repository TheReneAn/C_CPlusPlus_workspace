#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

	srand((int)time(NULL));		// Current time

	for (int i = 0; i < 2; i++) {
		printf("Dice %d: %d\n", i + 1, (rand() % 6) + 1);	// Dice 6
	}

	return 0;
}

/*
Create a program that make 2 dice numbers
*/