#include <stdio.h>

int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = arr;

	// No Change the value in the ptr
	for (int i = 0; i < 5; i++) {
		* (ptr + i) += 2;
	}

	for (int i = 0; i < 5; i++) {
		printf("Result: %d\n", arr[i]);
	}

	return 0;
}