#include <stdio.h>

int Recursive(int n) {
	if (n == 0) {
		return 1;
	}
	else {
		// 2 * 2^(n-1) * 2^(n-2) * ... * 2^0
		return 2 * Recursive(n - 1);
	}
}

int main() {

	int n;

	printf("Please enter the number: ");
	scanf_s("%d", &n);
	
	printf("2^n: %d\n", Recursive(n));

	return 0;
}

/*
Let's make a recursive function that obtains n of 2©ú
*/