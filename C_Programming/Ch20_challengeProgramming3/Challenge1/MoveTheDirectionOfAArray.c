#include <stdio.h>

void Array_Print(int (*arr)[4]) {
	int i = 0, j = 0;

	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			printf("%3d", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void MoveTheDirection(int arr[][4]) {
	int i = 0, j = 0;
	int temp[4][4] = { 0, };

	// Save to temp array
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			temp[j][3 - i] = arr[i][j];

		}
	}

	// Move to original array
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			arr[i][j] = temp[i][j];
		}
	}

	Array_Print(arr);
}

int main() {

	int arr[4][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16}
	};

	// Print the original array
	Array_Print(arr);
	
	// Rotate the array
	for (int i = 0; i < 3; i++) {
		printf("     ¡å     \n\n");;
		MoveTheDirection(arr);
	}		

	return 0;
}

/*
Declare a int-type two-dimensional array with a length of 4 x 4.
Then write a program that moves the array elements 90 degrees to the right and prints.
*/