#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>

#define MAX_PPL_LEN 30

typedef struct person {
	char name[30];
	char phoneNum[50];
} Person;

void ClearLineFromReadbuffer() {
	while (getchar() != '\n');
}

int PrintMenu() {
	int itemNum = 0;

	printf("**** MENU *****\n");
	printf("1. Insert\n");
	printf("2. Delete\n");
	printf("3. Search\n");
	printf("4. Print All\n");
	printf("5. Exit\n");

	printf("Choose the item: ");
	scanf_s("%d", &itemNum);

	while ((itemNum < 1) || (5 < itemNum)) {
		printf("\n***You enter wrong number! Please enter again.***\n\n");

		printf("**** MENU *****\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Print All\n");
		printf("5. Exit\n");

		printf("Choose the item: ");
		scanf_s("%d", &itemNum);
	}

	return itemNum;
}

void INSERT(Person Info[], int *pplnum) {
	printf("\n[INSERT]\n");
	ClearLineFromReadbuffer();

	printf("Input Name: ");
	fgets(Info[]->name, sizeof(Info->name), stdin);
	printf("Input Tel Number: ");
	fgets(Info->phoneNum, sizeof(Info->phoneNum), stdin);

	pplnum++;
}

void PRINTALL(Person **Info, int pplnum) {
	printf("\n[Printf All Data]\n");
	for (int i = 0; i < pplnum; i++) {
		fputs(*Info[i]->name, stdout);
		printf("Name: %s, Tel: %s\n", *Info[i]->name, *Info[i]->phoneNum);
	}
}

void EXIT() {
	printf("Exit this program.\n");
	exit(0);
}

int main() {

	int MenuNum = 0, pplnum = 0;
	Person Info[MAX_PPL_LEN];

	while (1) {
		// Print and Choos Number
		MenuNum = PrintMenu();

		switch (MenuNum)
		{
		case 1:
			INSERT(Info, &pplnum);
			printf("Data Inserted!\n\n");
			break;
		case 2:
			//DELETE();
			break;
		case 3:
			//SEARCH();
			break;
		case 4:
			PRINTALL(Info, pplnum);
			break;
		case 5:
			EXIT();
			break;
		}
	}

	// Destroy dinamic
	for (int i = 0; i < MAX_PPL_LEN; i++) {
		Info[i];
	}

	return 0;
}