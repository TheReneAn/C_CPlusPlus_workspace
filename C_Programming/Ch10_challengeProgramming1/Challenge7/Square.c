#include <stdio.h>

int main() {

	int K, count = 0;

	printf("Please enter the K number: ");
	scanf_s("%d", &K);	

	while (1) {

		if (K <= 1)	{
			break;
		}

		K = K / 2;
		count++;
	}

	printf("The value of 'n': %d\n", count);

	return 0;
}

/*
Enter the number k from the program user.

Then, write a program that calculates and outputs the maximum value of n in which the formula is formed.

2©ú ¡Â K
*/