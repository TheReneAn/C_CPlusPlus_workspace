#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void UserInput(int userNumbers[]) {
	printf("Enter three number: ");
	scanf_s("%d %d %d", &userNumbers[0], &userNumbers[1], &userNumbers[2]);
}

void ComInput(int computerNumbers[]) {

	// Random Number
	srand((int)time(NULL));		// Current time

	// Avoid duplication numbers
	for (int i = 0; i < 3; i++) {

		computerNumbers[i] = rand() % 10;	// 0 ~ 9

		for (int j = 0; j < i;)
		{
			if (computerNumbers[j] != computerNumbers[i])
			{
				j++;
			}
			else
			{
				j = 0;
				computerNumbers[i] = rand() % 10;
			}
		}
	}
}

void CheckTheballs(int userNumbers[], int computerNumbers[]) {
	int challenge = 0;
	int strike = 0, ball = 0;

	while (strike != 3) {
		strike = 0, ball = 0;
		UserInput(userNumbers);

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if ((userNumbers[i] == computerNumbers[j]) && (i == j)) {
					strike++;
				}
				else if ((userNumbers[i] == computerNumbers[j]) && (i != j)) {
					ball++;
				}
			}
		}

		challenge++;
		printf("%dth Challenge Result: %d strike, %d ball!!\n", challenge, strike, ball);
	}
}

int main() {

	int userNumbers[3] = { 0, }, computerNumbers[3] = { 0, };

	printf("Start Game!\n");

	// Random three Numbers
	ComInput(computerNumbers);

	// Challenge
	CheckTheballs(userNumbers, computerNumbers);

	printf("Game Over!\n");

	return 0;
}