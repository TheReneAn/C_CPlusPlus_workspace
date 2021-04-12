#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

int main() {

	printf("Enter the RAND_MAX (0 ~ %d)\n", RAND_MAX);

	for (int i = 0; i < 5; i++) {
		printf("%d) %d\n", i+1, rand() % 100);	// 0 ~ 99
	}

	return 0;
}

/*
Create a program that make 5 random numberms from 0 to RAND_MAX.
*/