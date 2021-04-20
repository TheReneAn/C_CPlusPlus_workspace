#pragma warning(disable:4996)

#include <stdio.h>

typedef struct book
{
	char name[30];
	char auther[30];
	int page;

} Book;

void ClearLineFromReadbuffer() {
	while (getchar() != '\n');
}

void InputBookInfo(Book *book) {

	printf("Auther: ");
	fgets(book->auther, sizeof(book->auther), stdin);
	printf("Books name: ");
	fgets(book->name, sizeof(book->name), stdin);
	printf("The numbe of page: ");
	scanf_s("%d", &book->page);

	ClearLineFromReadbuffer();
}

void OutputBookInfo(Book* book) {
	printf("Auther: %s", book->auther);
	printf("Books name: %s", book->name);
	printf("THe numbe of page: %d\n", book->page);
}

int main() {
	Book book[3];

	int i;

	// Input
	printf("Enter the information of books\n");
	for (i = 0; i < 3; i++) {
		InputBookInfo(&book[i]);
	}

	printf("\n");

	// Output
	printf("Print the information of books\n");
	for (i = 0; i < 3; i++) {
		printf("Book %d\n", i+1);
		OutputBookInfo(&book[i]);
	}

	return 0;
}