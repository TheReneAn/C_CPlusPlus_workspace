#pragma warning(disable:4996)

#include <stdio.h>

int UserInput() {
	int size = 0; 

	printf("Enter a size of the array: ");
	scanf_s("%d", &size);
	return size;
}

void SnailArray(int size, int(*arr)[50]) {
	int i, count = size;
	int value = 1, row = 0, colum = -1;
	int opt = 1;	// Decide the index whether increasing or decreasing
	
	while (value <= (count * count)) {
		// Row
		for (i = 0; i < size; i++) {
			colum += opt;
			arr[row][colum] = value++;
		}

		size--;

		// Colum
		for (i = 0; i < size; i++) {
			row += opt;
			arr[row][colum] = value++;
		}

		opt = opt * (-1);
	}
}

void PrintTheArray(int size, int arr[][50]) {
	int i, j;
	printf("\n");
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
}

int main() {

	int arr[50][50] = { 0, };
	int size = 0;					// arr [size][size]

	// Declare the array's size
	size = UserInput();

	// Snail_Array
	SnailArray(size, arr);

	// Print
	PrintTheArray(size, arr);

	return 0;
}