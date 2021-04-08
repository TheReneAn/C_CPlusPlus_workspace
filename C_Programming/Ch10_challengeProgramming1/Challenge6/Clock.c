#include <stdio.h>

int main() {

	int hour, minute, second;

	printf("Please enter the second: ");
	scanf_s("%d", &second);

	hour = second / 3600;
	minute = (second % 3600) / 60;
	second = second % 60;

	printf("Hour: %d, Minute: %d, second: %d\n", hour, minute, second);

	return 0;
}

/*
Let's get seconds from a user.

And write a program that prints it out in the form of [hour, minute, second].
*/