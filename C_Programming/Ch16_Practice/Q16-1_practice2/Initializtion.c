#include <stdio.h>

int main() {

	int arr_A[2][4] = {
		{1, 2, 3, 4},
		{5, 6, 7, 8}
	};

	int arr_B[4][2];
	
	// Initializtion
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			arr_B[i][j] = arr_A[j][i];
		}
	}

	// Print
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%3d ", arr_B[i][j]);
		}
		printf("\n");
	}

	return 0;
}