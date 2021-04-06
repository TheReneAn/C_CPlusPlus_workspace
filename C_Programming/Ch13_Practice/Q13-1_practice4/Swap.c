#include <stdio.h>

int main() {

	int arr[6] = { 1, 2, 3, 4, 5, 6};
	int* ptrFront = arr;
	int* ptrEnd = &arr[5];
	int temp;

	for (int i = 0; i < 3; i++) {
		temp = *ptrEnd;
		*ptrEnd = *ptrFront;
		*ptrFront = temp;

		ptrEnd--;
		ptrFront++;
	}	

	for (int i = 0; i < 6; i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}