#include <stdio.h>

int main() {

	int wallet = 3500;
	int cream = 500, chip = 700, soda = 400;

	printf("You have $ %d\n", wallet);

	// Check
	for (int i = 1; i <= wallet / cream; i++) {
		for (int j = 1; j <= wallet / chip; j++) {
			for (int k = 1; k <= wallet / soda; k++) {

				if ((cream * i) + (chip * j) + (soda * k) == wallet) {
					printf("Cream: %d, Chip: %d, Soda: %d\n", i, j, k);
				}
			}
		}
	}

	printf("How would you like to purchase it?\n");

	return 0;
}