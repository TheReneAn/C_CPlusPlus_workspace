#pragma warning(disable:4996)

#include <stdio.h>

int main() {
	char voca[100];
	int arrlen = 0;

	printf("Enter a word: ");
	scanf("%s", voca);

	// Check the array length
	while (voca[arrlen] != '\0') {
		arrlen++;
	}

	printf("The length of the array is %d\n", arrlen);

	return 0;
}

/*
Get an English word from the user and save it in the char type array.
And then reverse the word.
*/