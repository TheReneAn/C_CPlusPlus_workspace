#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
	char* title;	// Name of book
	char* isbn;		// the International Standard Book Number (ISBN)
	int price;
public:
	Book(const char* _title, const char* _isbn, int _price)
		: price(_price)
	{
		title = new char[strlen(_title) + 1];
		isbn = new char[strlen(_isbn) + 1];
		strcpy(title, _title);
		strcpy(isbn, _isbn);
	}

	// Copy Constructor
	Book(const Book& ref) : price(ref.price)
	{
		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);
	}

	// Assigment operater
	Book& operator= (const Book& ref) {
		delete[] title;
		delete[] isbn;

		title = new char[strlen(ref.title) + 1];
		isbn = new char[strlen(ref.isbn) + 1];
		strcpy(title, ref.title);
		strcpy(isbn, ref.isbn);

		price = ref.price;

		return *this;
	}

	void ShowBookInfo() const {
		cout << "Title: " << title << endl;
		cout << "ISBN: " << isbn << endl;
		cout << "Price: " << price << endl;
	}

	~Book() {
		delete[] title;
		delete[] isbn;
	}
};

class EBook : public Book {
private:
	char* DRMKey;	// Security Key
public:
	EBook(const char* _title, const char* _isbn, int _price, const char* _DRMKey)
		: Book(_title, _isbn, _price)
	{
		DRMKey = new char[strlen(_DRMKey) + 1];
		strcpy(DRMKey, _DRMKey);
	}

	// Copy Constructor
	EBook(const EBook& ref): Book(ref)
	{
		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);
	}

	// Assigment operater
	EBook& operator= (const EBook& ref) 
	{
		Book::operator=(ref);

		delete[] DRMKey;

		DRMKey = new char[strlen(ref.DRMKey) + 1];
		strcpy(DRMKey, ref.DRMKey);

		return *this;
	}

	void ShowEBookInfo() const {
		ShowBookInfo();
		cout << "DRMKey: " << DRMKey << endl;
	}

	~EBook() {
		delete[] DRMKey;
	}
};

int main() {
	Book book1("Book1", "555-12345-890-0", 20000);
	book1.ShowBookInfo();

	// Copy Constructor
	cout << endl << "[ Copy Constructor ]" << endl;
	Book book2 = book1;
	book2.ShowBookInfo();

	Book book3("Book3", "555-12345-890-0", 30000);
	// Assigment Operater
	cout << endl << "[ Assigment Operater ]" << endl;
	book2 = book3;
	book2.ShowBookInfo();
	book3.ShowBookInfo();

	cout << endl;
	cout << endl;

	EBook ebook1("ebook1", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook1.ShowEBookInfo();

	// Copy Constructor
	cout << endl << "[ Copy Constructor ]" << endl;
	EBook ebook2 = ebook1;
	ebook2.ShowEBookInfo();

	EBook ebook3("ebook3", "555-12345-890-3", 10000, "Hdx71qw3dcb");
	// Assigment Operater
	cout << endl << "[ Assigment Operater ]" << endl;
	ebook2 = ebook3;
	ebook2.ShowEBookInfo();

	return 0;
}