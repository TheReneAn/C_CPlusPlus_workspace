#pragma warning(disable:4996)

#include <stdio.h>

void Palindrome(char Word[], int wordLen) {

	int check = 0;

	for (int i = 0; i < wordLen / 2; i++) {
		if (Word[i] != Word[(wordLen - i) - 1]) {
			check = 1;
		}
	}

	if (check == 0) {
		printf("The word is a palindrome.\n");
	}
	else {
		printf("The word is not a palindrome.\n");
	}	
}

int main() {

	char Word[30];
	int wordlen = 0;

	// User Input
	printf("Enter a word: ");
	scanf("%s", Word);

	while (Word[wordlen] != '\0') {
		wordlen++;
	}

	// Check the Word
	Palindrome(Word, wordlen);

	return 0;
}