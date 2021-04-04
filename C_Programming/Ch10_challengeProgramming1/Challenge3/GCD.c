// Greatest common divisor (GCD)

#include <stdio.h>

// Euclidean Algorithm
int GCD(int X, int Y) {

	int R;

	while (1) {
		R = X % Y;

		if (R == 0) {
			return Y;
		}
		else {
			X = Y;
			Y = R;
		}
	}
}

int main() {

	int temp, num1, num2, X, Y;

	// User Input
	printf("Please enter two number: ");
	scanf_s("%d %d", &num1, &num2);

	// Switch
	if (num2 < num1) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	X = num1, Y = num2;

	// GCD
	printf("GCD is %d\n", GCD(X, Y));

	return 0;
}
