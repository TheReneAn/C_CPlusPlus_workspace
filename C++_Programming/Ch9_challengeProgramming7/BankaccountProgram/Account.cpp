/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: Account.cpp
*/

#include "BackingCommonDecl.h"
#include "Account.h"

Account::Account(int accNumber, int money, const char* cusname)
	: accID(accNumber), balance(money)
{
	cusName = new char[strlen(cusname) + 1];
	strcpy(cusName, cusname);
}

Account::Account(const Account& copy)
	: accID(copy.accID), balance(copy.balance)
{
	cusName = new char[strlen(copy.cusName) + 1];
	strcpy(cusName, copy.cusName);
}

int Account::GetaccountNumber() const { return accID; }

void Account::Deposit(int money) { balance += money; }
void Account::Withdraw(int money) { balance -= money; }

void Account::ShowCusInfo() const {
	cout << "Account: " << accID << endl;
	cout << "cusName : " << cusName << endl;
	cout << "Balance : " << balance << "\n" << endl;
}

void Account::ShowCusBalance() const {
	cout << "[ " << cusName << "'s balance ] " << balance << endl << endl;
}

Account::~Account() {
	delete[] cusName;
}
