#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

const int NAME_LEN = 30;

typedef struct {
	int accountNumber;
	char name[NAME_LEN];
	int balance;
} Customer;

void ShowMenu();
void MakeAccount();
void DepositMoney();
void WithdrawMoney();
void ShowAllCusInfo();
void ShowCusBalance(int cusLocation);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

Customer cus[100];	// Customer array
int cusNumber = 0;	// Customer number

int main() {

	int menuNum = 0;

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
			cout << "\n*** Enter a wrong number ***\n";
			cout << "Please enter again.\n\n";
		}
	}

	return 0;
}

void ShowMenu() {
	cout << "----- Menu -----\n";
	printf("1. Creat a new account\n");
	printf("2. Deposit\n");
	printf("3. Withdraw\n");
	printf("4. Show all acounts\n");
	printf("5. Exit\n\n");
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
		for (i = 0; i <= cusNumber; i++) {
			if (newAccount == cus[i].accountNumber) {
				cout << "\n!!! We already have the account in our bank !!!\n" << endl;
				cout << "Please enter another account numbers.\n" << endl;
				check = 0;
				break;
			}
			else {
				check = 1;
			}
		}

	} while (check == 0);

	// Customer Name
	cout << "Name: ";
	cin >> temp_Name;
	// Customer Balance
	cout << "Balance: ";
	cin >> newBalance;
	cout << endl;

	cus[cusNumber].accountNumber = newAccount;
	strncpy(cus[cusNumber].name, temp_Name, sizeof(cus[cusNumber].name) - 1);
	cus[cusNumber].balance = newBalance;

	cout << "¡Ú¡Ú¡Ú Compelete make an account ¡Ú¡Ú¡Ú" << endl;
	ShowCusBalance(cusNumber);

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
			for (i = 0; i <= cusNumber; i++) {
				if (findAccount == cus[i].accountNumber) {
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
			cout << "[ " << cus[cusLocation].name << "'s balance ] " << cus[cusLocation].balance << endl;
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

		cus[cusLocation].balance += depositAmount;

		cout << "\n¡Ú¡Ú¡Ú Compelete deposit ¡Ú¡Ú¡Ú" << endl;
		ShowCusBalance(cusLocation);
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
			for (i = 0; i <= cusNumber; i++) {
				if (findAccount == cus[i].accountNumber) {
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
			cout << "[ " << cus[cusLocation].name << "'s balance ] " << cus[cusLocation].balance << endl;
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

		cus[cusLocation].balance -= WithdrawAmount;

		cout << "\n¡Ú¡Ú¡Ú Compelete deposit ¡Ú¡Ú¡Ú" << endl;
		ShowCusBalance(cusLocation);
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
			cout << "Account: " << cus[i].accountNumber << endl;
			cout << "Name : " << cus[i].name << endl;
			cout << "Balance : " << cus[i].balance << "\n\n" << endl;
		}
	}
}

void ShowCusBalance(int cusLocation) {
	cout << "[ " << cus[cusLocation].name << "'s balance ] " << cus[cusLocation].balance << endl << endl;
}