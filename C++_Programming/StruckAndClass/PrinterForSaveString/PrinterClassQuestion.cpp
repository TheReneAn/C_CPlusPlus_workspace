#define _CRT_SECURE_NO_WARNINGS		// For strcpy

#include <iostream>
#include <cstring>
using namespace std;

class Printer
{
private:
	char stringSentence[30];

public:
	void SetString(const char* sentence);
	void ShowString();
};

void Printer::SetString(const char* sentence)
{
	strcpy(stringSentence, sentence);
}

void Printer::ShowString()
{
	cout << stringSentence << endl;
}

int main(void)
{
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();

	pnt.SetString("I love C++");
	pnt.ShowString();

	return 0;
}