/*
* Banking System Ver 0.3
* Name: Rene An
* Content: Add copy construcors
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 30;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllCusInfo();

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Customer {
private:
	int accountNumber;
	char* name;
	int balance;
public:
	// Constructor
	Customer(int accNumber, int moneny, char* cusname)
		: accountNumber(accNumber), balance(moneny)
	{
		name = new char[strlen(cusname) + 1];
		strcpy(name, cusname);
	}
	// Copy Constructor
	Customer(const Customer& copy) 
		: accountNumber(copy.accountNumber), balance(copy.balance)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}

	int GetaccountNumber() { return accountNumber; }

	void Deposit(int money) { balance += money; }
	void Withdraw(int money) { balance -= money; }

	void ShowCusInfo() {
		cout << "Account: " << accountNumber << endl;
		cout << "Name : " << name << endl;
		cout << "Balance : " << balance << "\n" << endl;
	}
	
	void ShowCusBalance() {
		cout << "[ " << name << "'s balance ] " << balance << endl << endl;
	}

	// Destructor
	~Customer() {
		delete[] name;
	}
};

Customer* cus[100];
int cusNumber = 0;

int main() {

	int menuNum = 0;

	cout << "¡Ø¡Ø¡Ø Banking System Ver 0.3 ¡Ø¡Ø¡Ø\n" << endl;

	while (1) {
		// Show menu & choose the menu number
		ShowMenu();
		printf("Selection: ");
		cin >> menuNum;
		cout << endl;

		switch (menuNum)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllCusInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "*** Enter a wrong number ***\n";
			cout << "Please enter again.\n\n";
		}
	}

	return 0;
}

void ShowMenu() {
	cout << "----- Menu -----\n";
	cout << "1. Creat a new account\n";
	cout << "2. Deposit\n";
	cout << "3. Withdraw\n";
	cout << "4. Show all acounts\n";
	cout << "5. Exit\n\n";
}

void MakeAccount() {
	int i = 0, check = 0;

	int newAccount = 0;
	char temp_Name[NAME_LEN];
	int newBalance = 0;

	// Account Number
	do {
		cout << "[Opening an account]" << endl;
		cout << "Account Number: ";
		cin >> newAccount;

		// Validate the account 
		if (1 <= cusNumber) {
			for (i = 0; i < cusNumber; i++) {
				if (newAccount == cus[i]->GetaccountNumber()) {
					cout << "\n!!! We already have the account in our bank !!!\n" << endl;
					cout << "Please enter another account numbers.\n" << endl;
					check = 0;
					break;
				}
				else {
					check = 1;
				}
			}
		}
		else {
			check = 1;
		}

	} while (check == 0);

	// Customer Name
	cout << "Name: ";
	cin >> temp_Name;
	// Customer Balance
	cout << "Balance: ";
	cin >> newBalance;
	cout << endl;

	// New Customer
	cus[cusNumber] = new Customer(newAccount, newBalance, temp_Name);
	cus[cusNumber]->ShowCusBalance();
	cout << "¡Ú¡Ú¡Ú Compelete make an account ¡Ú¡Ú¡Ú\n" << endl;

	// Increcing customer number
	cusNumber++;
}

void DepositMoney() {
	int i = 0, check = 0;

	int findAccount = 0;
	int cusLocation = 0;
	int depositAmount = 0;

	if (cusNumber == 0) {
		cout << "Our bank has no customers now.\n" << endl;
	}
	else {
		// Account Number
		do {
			cout << "[Deposit Money]" << endl;
			cout << "Account Number: ";
			cin >> findAccount;

			// Check customers
			for (i = 0; i < cusNumber; i++) {
				if (findAccount == cus[i]->GetaccountNumber()) {
					cusLocation = i;
					check = 1;
					break;
				}
				else {
					check = 0;
				}
			}

			if (check == 0) {
				cout << "\n!!! There is not the account in our bank  !!!\n" << endl;
				cout << "Please enter another account numbers.\n" << endl;
			}

		} while (check == 0);


		// Deposit amount
		while (1) {
			cus[cusLocation]->ShowCusBalance();
			cout << "Deposit amount: ";
			cin >> depositAmount;

			// Validate the amount 
			if (depositAmount <= 0) {
				cout << "\n!!! You can not deposit less than 0 !!!\n" << endl;
				cout << "Please enter agian.\n" << endl;
			}
			else {
				break;
			}
		}

		// Deposit the amount
		cus[cusLocation]->Deposit(depositAmount);

		cout << "\n¡Ú¡Ú¡Ú Compelete deposit ¡Ú¡Ú¡Ú" << endl;
		cus[cusLocation]->ShowCusBalance();
	}
}

void WithdrawMoney() {
	int i = 0, check = 0;

	int findAccount = 0;
	int cusLocation = 0;
	int WithdrawAmount = 0;

	if (cusNumber == 0) {
		cout << "Our bank has no customers now.\n" << endl;
	}
	else {
		// Account Number
		do {
			cout << "[Withdraw Money]" << endl;
			cout << "Account Number: ";
			cin >> findAccount;

			// Check customers
			for (i = 0; i < cusNumber; i++) {
				if (findAccount == cus[i]->GetaccountNumber()) {
					cusLocation = i;
					check = 1;
					break;
				}
				else {
					check = 0;
				}
			}

			if (check == 0) {
				cout << "\n!!! There is not the account in our bank  !!!\n" << endl;
				cout << "Please enter another account numbers.\n" << endl;
			}

		} while (check == 0);


		// Withdraw amount
		while (1) {
			cus[cusLocation]->ShowCusBalance();
			cout << "Withdraw amount: ";
			cin >> WithdrawAmount;

			// Validate the amount 
			if (WithdrawAmount <= 0) {
				cout << "\n!!! You can not deposit less than 0 !!!\n" << endl;
				cout << "Please enter agian.\n" << endl;
			}
			else {
				break;
			}
		}

		// Withdraw the amount
		cus[cusLocation]->Withdraw(WithdrawAmount);

		cout << "\n¡Ú¡Ú¡Ú Compelete deposit ¡Ú¡Ú¡Ú" << endl;
		cus[cusLocation]->ShowCusBalance();
	}
}

void ShowAllCusInfo() {
	if (cusNumber == 0) {
		cout << "Our bank has no customers now.\n" << endl;
	}
	else {
		cout << "----- Customer lists -----" << endl;
		for (int i = 0; i < cusNumber; i++) {
			cout << i + 1 << ")" << endl;
			cus[i]->ShowCusInfo();
		}
	}
}