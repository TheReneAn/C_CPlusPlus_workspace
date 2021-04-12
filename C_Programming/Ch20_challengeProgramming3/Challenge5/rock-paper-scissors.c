#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int UserInput() {
	int userNumber = 0;

	printf("Rock: 1, Paper: 2, Scissors: 3\n");
	printf("Enter a number: ");
	scanf_s("%d", &userNumber);

	return userNumber;
}

int main() {

	int userNumber = 0, computerNumber = 0;
	int win = 0, tie = 0;

	// Random Number
	srand((int)time(NULL));		// Current time

	while (1) {
		const char* words[3] = {"Rock","Paper","Scissors"};

		// Choose the Number
		userNumber = UserInput();
		computerNumber = (rand() % 3) + 1;

		// Game
		if (userNumber == computerNumber) {
			tie++;
			printf("Play chose %s, Computer chose %s, Play a draw!!\n", words[userNumber - 1], words[computerNumber - 1]);
		}
		else if (((userNumber == 1) && (computerNumber == 3)) || ((userNumber == 2) && (computerNumber == 1)) || ((userNumber == 3) && (computerNumber == 2))) {
			win++;
			printf("Play chose %s, Computer chose %s, Player win!!\n", words[userNumber - 1], words[computerNumber - 1]);
		}
		else {
			printf("Play chose %s, Computer chose %s, Player lose!!\n", words[userNumber - 1], words[computerNumber - 1]);
			break;
		}
	}

	// The Game result
	printf("\nWin: %d, Tie: %d\n", win, tie);

	return 0;
}

