// #pragma warning(disable:4996)

#include <stdio.h>

int main() {

	int decimal = 0;

	printf("Enter a decimal number: ");
	scanf_s("%d", &decimal);

	// %x: Haxa decimal. 
	// If you want to see the real hexa, put '#'
	printf("Hexa decimal: %x\n", decimal);

	return 0;
}

/*
* A program that receives a decimal integer and outputs it in hexadecimal.
*/