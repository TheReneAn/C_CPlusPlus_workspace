#pragma warning(disable:4996)

#include <stdio.h>

int DecimalToBinary(int Decimal, int binarArry[]) {
	int total = 0;

	while (0 < Decimal) {
		binarArry[total] = Decimal % 2;
		Decimal = Decimal / 2;
		total++;
	}

	return total;
}

int main() {

	int Decimal = 0, total = 0;
	int binaryArr[30];

	printf("Enter Decimal number: ");
	scanf("%d", &Decimal);
	
	// Change Decimal to Binary
	total = DecimalToBinary(Decimal, binaryArr);
	
	// Print
	for (int i = total - 1; i >= 0; i--) {
		printf("%d", binaryArr[i]);
	}

	return 0;
}