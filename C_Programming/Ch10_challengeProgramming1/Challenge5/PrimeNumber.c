// Prime Number

#include <stdio.h>
#define SIZE 51

int main() {
	
	/*
	********************* General method *********************
	int i, j, count = SIZE;

	for (i = 2; i <= SIZE; i++) {
		for (j = 2; j <= i; j++) {

			if (i % j == 0) {
				break;
			}
		}

		if (i == j) {
			printf("%d\t", i);
		}
	}
	*/

	/*************** Sieve of Eratosthenes method ***************/

	int i;

	// Size of Sieve
	int Sieve_Number[SIZE];

	for (i = 0; i < SIZE; i++) {
		Sieve_Number[i] = i;
	}

	for (i = 2; i * 2 < SIZE; i++) {
		// if the number is alredy deleted, just continue
		if (Sieve_Number[i] == 0) {
			continue;
		}

		// Delete Multiplier value
		for (int k = i, j = i; k * j < SIZE; j++) {
			Sieve_Number[k * j] = 0;
		}
	}

	// Print
	Sieve_Number[1] = 0;		// 1 is not a prime number
	for (i = 0; i < SIZE; i++) {
		if (Sieve_Number[i] != 0) {
			printf("%4d", Sieve_Number[i]);
		}
	}	

	return 0;
}

/*
Let's write a program that outputs 10 prime numbers.

For your information, if the integer num is only divided into 1 and num, this is a small number.
Therefore, three is a minority. But four is not a minority. This is because they are divided into 1, 2, and 4.
*/