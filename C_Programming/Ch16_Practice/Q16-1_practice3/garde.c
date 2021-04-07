#pragma warning(disable:4996)

#include <stdio.h>

int main() {

	int grade_program[5][5];
	int Total = 0, student_total = 0, subject_total = 0;

	// Enter grades
	for (int i = 0; i < 4; i++) {
		printf("*** Enter student %d's grades ***\n", i + 1);
		for (int j = 0; j < 4; j++) {
			printf("%d) Input: ", i+1);
			scanf("%d", &grade_program[i][j]);
		}
	}

	// Calcuate totals
	for (int i = 0; i < 4; i++) {
		student_total = 0;
		subject_total = 0;
		for (int j = 0; j < 4; j++) {
			student_total += grade_program[i][j];
			subject_total += grade_program[j][i];
		}
		Total += student_total;
		grade_program[i][4] = student_total;
		grade_program[4][i] = subject_total;
	}

	grade_program[4][4] = Total;

	// Print
	printf("***student grades ***\n");
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			printf("%5d", grade_program[i][j]);
		}
		printf("\n");
	}

	return 0;
}