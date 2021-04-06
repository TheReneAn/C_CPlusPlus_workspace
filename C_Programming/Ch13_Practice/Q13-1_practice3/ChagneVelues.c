#include <stdio.h>

int main() {

	int arr[5] = { 1, 2, 3, 4, 5 };
	int* ptr = &arr[4];		// &(*(arr + 4))
	int total = 0;

	// No Change the value in the ptr
	for (int i = 0; i < 5; i++) {
		total += *(ptr--);
	}

	printf("Result: %d\n", total);

	return 0;
}