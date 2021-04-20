#pragma warning(disable:4996)

#include <stdio.h>

// Command prompt
// C:\> wordcnt text.txt
int main(int argc, char * argv[]) {

	char word[30];
	int wordA = 0, wordP = 0;

	// If the number of factors passed to the 'main' function is 
	// less than two (execution file path, file name)
	if (argc < 2) {
		printf("Enter the path where the program is located and 'text.txt'\n");
		printf("The path where the program is located : %s\n", argv[0]);
		return -1;
	}

	// Open the file
	FILE * fp = fopen(argv[1], "rt");

	if (fp == NULL) {
		puts("Failed to open the file!");
		return -1;
	}

	// Check the file
	while (1) {
		/* Separate strings with spaces using the function 'fscanf_s'.
		The fscanf() function is used to read set of characters from file. 
		It reads a word from the file and returns EOF at the end of file. */
		if (fscanf_s(fp, "%s", word, sizeof(word)) == EOF) break;
		else if (word[0] == 'A' || word[0] == 'a') wordA++;
		else if (word[0] == 'P' || word[0] == 'p') wordP++;
	}

	// Print the result
	printf("Number of words starting with A : %d\n", wordA);
	printf("Number of words starting with P : %d\n", wordP);

	// End of the file
	if (feof(fp) != 0)
		puts("Complete!");
	else
		puts("Error!");

	// Close the file
	fclose(fp);

	return 0;
}