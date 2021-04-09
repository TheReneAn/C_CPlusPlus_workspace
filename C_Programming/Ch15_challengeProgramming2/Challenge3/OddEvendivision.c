#pragma warning(disable:4996)

#include <stdio.h>

void Odd(int arr[], int divArr[], int arrLen) {

	int OddNumber = 0;

	for (int i = 0; i < arrLen; i++) {
		if (arr[i] % 2 == 1) {
			divArr[OddNumber++] = arr[i];
		}
	}
}

void Even(int arr[], int divArr[], int arrLen) {

	int EvenNumber = arrLen - 1;

	for (int i = 0; i < arrLen; i++) {
		if (arr[i] % 2 == 0) {
			divArr[EvenNumber--] = arr[i];
		}
	}
}

int main() {

	int arr[10], divArr[10];

	// User Input
	printf("*** Enter 10 numbers ***\n");
	for (int i = 0; i < 10; i++) {
		printf("Input: ");
		scanf("%d", &arr[i]);
	}

	// Odd
	Odd(arr, divArr, sizeof(arr) / sizeof(int));

	// Even
	Even(arr, divArr,sizeof(arr) / sizeof(int));

	// print
	printf("Printf array: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", divArr[i]);
	}

	return 0;
}

/*
There is an array of ten lengths.
If the number entered is odd, it fills from the front of the column, and if it is even, it fills from the back.

Example :
Input: 1 1 4 4 4 4 3 3 2 2
Output: 1 1 3 3 2 2 4 4 4 4 
*/