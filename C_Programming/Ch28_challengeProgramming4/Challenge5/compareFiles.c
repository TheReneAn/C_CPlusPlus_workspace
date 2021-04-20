#pragma warning(disable:4996)

#include <stdio.h>

// Command prompt
// C:\> wordcnt text.txt
int main(int argc, char* argv[]) {

	char fp1_char, fp2_char;

	// If the number of factors passed to the 'main' function is 
	// less than three (execution file path, two files name)
	if (argc < 3) {
		printf("Enter the path where the program is located and two .txt files\n");
		printf("The path where the program is located : %s\n", argv[0]);
		return -1;
	}

	// Open the file
	FILE* fp1 = fopen(argv[1], "rt");
	FILE* fp2 = fopen(argv[2], "rt");

	if ((fp1 == NULL) || (fp2 == NULL)) {
		puts("Failed to open the file!");
		return -1;
	}

	// Check the file
	while (1) {
		fp1_char = fgetc(fp1);
		fp2_char = fgetc(fp2);

		if (fp1_char != fp2_char) {
			printf("The files are different.\n");
			break;
		}
		// End of the file
		else if ((feof(fp1) != 0) && (feof(fp2) != 0)) {
			printf("The files are totally same.\n");
			break;
		}
	}

	// Close the file
	fclose(fp1);
	fclose(fp2);

	return 0;
}