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

/*
* Let's write a program that receives two integers from the program user and outputs a multiplication table.
* 
* For example, if a program user enters 3 and 5, 3 and 4 and 5 shall be printed, and if 2 and 3 are entered, 2 and 3 and 4 shall be printed.
* 
* However, there is one condition.
* Users should be free from the input order when entering two numbers.
* That is, whether inputting 3 and 5 or 5 and 3 the program should output the same results.
*/