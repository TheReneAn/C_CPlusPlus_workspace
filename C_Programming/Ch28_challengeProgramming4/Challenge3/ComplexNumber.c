#pragma warning(disable:4996)

#include <stdio.h>

typedef struct complexnumber {

	double real;
	double imaginary;

} ComplexNumber;

void InputNumbers(ComplexNumber* com) {
	scanf_s("%lf %lf", &com->real, &com->imaginary);
}

ComplexNumber SumNumbers(ComplexNumber com[]) {
	ComplexNumber sum;
	// (a + c) + (b + d)i
	sum.real = com[0].real + com[1].real;
	sum.imaginary = com[0].imaginary + com[1].imaginary;
	return sum;
}

ComplexNumber MultipleNumbers(ComplexNumber com[]) {
	ComplexNumber multiple;
	// (ac-bd) + (ad + bc)i
	multiple.real = (com[0].real * com[1].real) - (com[0].imaginary * com[1].imaginary);
	multiple.imaginary = (com[0].real * com[1].imaginary) + (com[0].imaginary * com[1].real);
	return multiple;
}

void OutputNumbers(ComplexNumber sum, ComplexNumber multiples) {
	printf("The result of sum] Real Number: %lf, Imaginary: %lf\n", sum.real, sum.imaginary);
	printf("The result of multiple] Real Number: %lf, Imaginary: %lf\n", multiples.real, multiples.imaginary);
}

int main() {

	ComplexNumber com[2];
	ComplexNumber sum, multiple;

	// Input from a user
	for (int i = 0; i < 2; i++) {
		printf("Enter complex Numbers %d [Real & Imaginary] : ", i + 1);
		InputNumbers(&com[i]);
	}

	// Sum
	sum = SumNumbers(com);

	// Multiple
	multiple = MultipleNumbers(&com);

	// Print Numbers
	OutputNumbers(sum, multiple);

	return 0;
}