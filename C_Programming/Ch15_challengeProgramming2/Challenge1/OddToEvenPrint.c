#pragma warning(disable:4996)

#include <stdio.h>

void OddPrint(int arr[], int arrLen) {

	printf("Odd print: ");

	for (int i = 0; i < arrLen; i++) {
		if (arr[i] % 2 == 1) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

void EvenPrint(int arr[], int arrLen) {

	printf("Even print: ");

	for (int i = 0; i < arrLen; i++) {
		if (arr[i] % 2 == 0) {
			printf("%d ", arr[i]);
		}
	}
	printf("\n");
}

int main() {

	int arr[10];

	// User Input
	printf("*** Enter 10 numbers ***\n");
	for (int i = 0; i < 10; i++) {
		printf("Input: ");
		scanf("%d", &arr[i]);
	}
	
	// Odd Print
	OddPrint(arr, sizeof(arr) / sizeof(int));

	// Even Print
	EvenPrint(arr, sizeof(arr) / sizeof(int));

	return 0;
}