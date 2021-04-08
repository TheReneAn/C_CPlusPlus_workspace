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

/*
* Today is Friday. Now I have 5,000 won in my pocket. 
* If you rent a DVD, you have 3,500 won left.
* I will stop by the supermarket and buy cream bread (500 won), shrimp crackers (700 won), and coke (400 won).
* If you want to buy one or more of these three items without leaving any change, 
* How should I proceed with the purchase?
*/