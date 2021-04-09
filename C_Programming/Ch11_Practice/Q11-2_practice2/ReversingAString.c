#pragma warning(disable:4996)

#include <stdio.h>

int main() {
	
	char voca[100], reverVoca[100];
	int arrlen = 0;

	printf("Enter a word: ");
	scanf("%s", voca);

	// Check the array length
	while (voca[arrlen] != '\0') {
		arrlen++;
	}

	// 1. Reversing at a new array
	for (int i = 0; i < arrlen; i++) {
		reverVoca[i] = voca[(arrlen - i) -1];
	}
	reverVoca[arrlen] = '\0';

	printf("After reversing the voca: %s \n", reverVoca);

	// 2. Reversing
	for (int i = 0; i < arrlen / 2; i++) {
		int temp = voca[i];
		voca[i] = voca[(arrlen - i) - 1];
		voca[(arrlen - i) - 1] = temp;
	}

	printf("After reversing the voca: %s \n", voca);

	return 0;
}

/*
Make a program that gets a length of an English word.

Get a word from a user.
For example, if a user enters the "Array" word, it should be showed '5'
*/