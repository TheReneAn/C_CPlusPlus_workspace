/*
* Banking System Ver 0.3
* Name: Rene An
* Content: Add control class
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

const int CUS_NUM = 100;
const int NAME_LEN = 30;

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

/*
* Class name: Customer
* Class type: Entity Class
*/

class Customer {
private:
	int accountNumber;
	char* name;
	int balance;
public:
	// Constructor
	Customer(int accNumber, int moneny, char* cusname);
	// Copy Constructor
	Customer(const Customer& copy);

	int GetaccountNumber() const;

	void Deposit(int money);
	void Withdraw(int money);

	// Print Info
	void ShowCusInfo() const;
	void ShowCusBalance() const;

	// Destructor
	~Customer();
};

Customer::Customer(int accNumber, int moneny, char* cusname)
	: accountNumber(accNumber), balance(moneny)
{
	name = new char[strlen(cusname) + 1];
	strcpy(name, cusname);
}

Customer::Customer(const Customer& copy)
	: accountNumber(copy.accountNumber), balance(copy.balance)
{
	name = new char[strlen(copy.name) + 1];
	strcpy(name, copy.name);
}

int Customer::GetaccountNumber() const { return accountNumber; }

void Customer::Deposit(int money) { balance += money; }
void Customer::Withdraw(int money) { balance -= money; }

void Customer::ShowCusInfo() const {
	cout << "Account: " << accountNumber << endl;
	cout << "Name : " << name << endl;
	cout << "Balance : " << balance << "\n" << endl;
}

void Customer::ShowCusBalance() const {
	cout << "[ " << name << "'s balance ] " << balance << endl << endl;
}

Customer::~Customer() {
	delete[] name;
}

/*
* Class name: AccountHandler
* Class type: Control Class
*/

class AccountHandler {
private:
	Customer* cus[CUS_NUM];
	int cusNumber = 0;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllCusInfo() const;
	~AccountHandler();
};

AccountHandler::AccountHandler() : cusNumber(0) 
{	
	for (int i = 0; i < CUS_NUM; i++) {
		cus[i] = nullptr;
	}
}

void AccountHandler::ShowMenu() const {
	cout << "----- Menu -----\n";
	cout << "1. Creat a new account\n";
	cout << "2. Deposit\n";
	cout << "3. Withdraw\n";
	cout << "4. Show all acounts\n";
	cout << "5. Exit\n\n";
}

void AccountHandler::MakeAccount() {
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

void AccountHandler::DepositMoney() {
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

void AccountHandler::WithdrawMoney() {
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

void AccountHandler::ShowAllCusInfo() const {
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

AccountHandler::~AccountHandler() {
	for (int i = 0; i < cusNumber; i++) {
		delete cus[i];
	}
}

int main() {

	AccountHandler handler;
	int menuNum = 0;	

	cout << "¡Ø¡Ø¡Ø Banking System Ver 0.5 ¡Ø¡Ø¡Ø\n" << endl;

	while (1) {
		// Show menu & choose the menu number
		handler.ShowMenu();
		printf("Selection: ");
		cin >> menuNum;
		cout << endl;

		switch (menuNum)
		{
		case MAKE:
			handler.MakeAccount();
			break;
		case DEPOSIT:
			handler.DepositMoney();
			break;
		case WITHDRAW:
			handler.WithdrawMoney();
			break;
		case INQUIRE:
			handler.ShowAllCusInfo();
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