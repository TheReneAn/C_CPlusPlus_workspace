#include <stdio.h>

int main() {

	int temp = 0, num1 = 0, num2 = 0;

	// User Input
	printf("Please enter two number: ");
	scanf_s("%d %d", &num1, &num2);

	// Switch
	if (num2 < num1) {
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	// Print
	for (int i = num1; i <= num2; i++) {
		printf("%d's table\n", i);
		for (int j = 1; j <= 9; j++) {
			printf("%d X %d = %d\n", i, j, i*j);
		}
		printf("\n");
	}

	return 0;
}