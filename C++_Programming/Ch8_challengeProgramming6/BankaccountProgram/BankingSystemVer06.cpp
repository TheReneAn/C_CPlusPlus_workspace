/*
* Banking System Ver 0.6
* cusName: Rene An
* Content: Inheritance
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

const int MAX_CUS_NUM = 100;
const int NAME_LEN = 30;

// Menu
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Account type
enum { NORMAL = 1, CREDIT = 2 };

// Credit level
enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

/*
* Class Name: Account
* Class type: Entity Class
*/

class Account {
private:
	int accID;
	char* cusName;
	int balance;
public:
	// Constructor
	Account(int accNumber, int money, const char* cusname);
	// Copy Constructor
	Account(const Account& copy);

	int GetaccountNumber() const;

	virtual void Deposit(int money);
	void Withdraw(int money);

	// Print Info
	virtual void ShowCusInfo() const;
	void ShowCusBalance() const;

	// Destructor
	virtual ~Account() {
		delete[] cusName;
	}
};

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

/*
* Class Name: NormalAccount
* Class type: Entity Class
*/

class NormalAccount : public Account {
private:
	int interRate;
public:
	NormalAccount(int accNumber, int money, const char* cusname, int rate)
		: Account(accNumber, money, cusname), interRate(rate)
	{ }

	virtual void Deposit(int money) {
		Account::Deposit(money);						// Basic money
		Account::Deposit(money * (interRate / 100.0));	// InterRate
	}

	virtual void ShowCusInfo() const {
		cout << "Acount Type: Normal Account" << endl;
		Account::ShowCusInfo();
	}
};

/*
* Class Name: HighCreditAccount
* Class type: Entity Class
*/

class HighCreditAccount : public NormalAccount {
private:
	int creditLevel;
public:
	HighCreditAccount(int accNumber, int money, const char* cusname, int rate, int level)
		: NormalAccount(accNumber, money, cusname, rate), creditLevel(level)
	{ }

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);						// Basic + inter Rate
		Account::Deposit(money * (creditLevel / 100.0));	// Special Rate
	}

	virtual void ShowCusInfo() const {
		cout << "Acount Type: Credit Account" << endl;
		Account::ShowCusInfo();
	}
};

/*
* Class Name: AccountHandler
* Class type: Control Class
*/

class AccountHandler {
private:
	Account* cus[MAX_CUS_NUM];
	int cusNumber = 0;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositMoney();
	void WithdrawMoney();
	void ShowAllCusInfo() const;
	~AccountHandler();

protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
};

AccountHandler::AccountHandler() : cusNumber(0)
{
	for (int i = 0; i < MAX_CUS_NUM; i++) {
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
	int selection = 0;
	cout << "[Opening an account]" << endl;
	cout << "1. Normal Account 2. High Credit Account" << endl;
	cout << "Selection: ";
	cin >> selection;
	cout << endl;
	
	if (selection == NORMAL) {
		MakeNormalAccount();
	} 
	else if (selection == CREDIT) {
		MakeCreditAccount();
	}
}

void AccountHandler::MakeNormalAccount() {
	int i = 0, check = 0;

	int newAccount = 0;
	char temp_Name[NAME_LEN];
	int newBalance = 0;
	int interRate = 0;

	// Account Number
	do {
		cout << "[Opening an normal account]" << endl;
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

	// Account cusName
	cout << "Name: ";
	cin >> temp_Name;
	// Account Balance
	cout << "Balance: ";
	cin >> newBalance;
	// InterRate
	cout << "Interest: ";
	cin >> interRate;
	cout << endl;

	// New Account
	cus[cusNumber] = new NormalAccount(newAccount, newBalance, temp_Name, interRate);
	cus[cusNumber]->ShowCusBalance();
	cout << "¡Ú¡Ú¡Ú Compelete make an nomal account ¡Ú¡Ú¡Ú\n" << endl;

	// Increcing Account number
	cusNumber++;
}

void AccountHandler::MakeCreditAccount() {
	int i = 0, check = 0;

	int newAccount = 0;
	char temp_Name[NAME_LEN];
	int newBalance = 0;
	int interRate = 0;
	int creditLevel = 0;

	// Account Number
	do {
		cout << "[Opening an credit account]" << endl;
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

	// Account cusName
	cout << "Name: ";
	cin >> temp_Name;
	// Account Balance
	cout << "Balance: ";
	cin >> newBalance;
	// Interest
	cout << "Interest: ";
	cin >> interRate;
	// Credit Level
	cout << "Credit Level(1toA, 2toB, 3toC): ";
	cin >> creditLevel;
	cout << endl;

	// New Account
	switch (creditLevel)
	{
	case 1:
		cus[cusNumber] = new HighCreditAccount(newAccount, newBalance, temp_Name, interRate, LEVEL_A);
		break;
	case 2:
		cus[cusNumber] = new HighCreditAccount(newAccount, newBalance, temp_Name, interRate, LEVEL_B);
		break;
	case 3:
		cus[cusNumber] = new HighCreditAccount(newAccount, newBalance, temp_Name, interRate, LEVEL_C);
		break;
	}
	
	cus[cusNumber]->ShowCusBalance();
	cout << "¡Ú¡Ú¡Ú Compelete make an credit account ¡Ú¡Ú¡Ú\n" << endl;

	// Increcing Account number
	cusNumber++;
}

void AccountHandler::DepositMoney() {
	int i = 0, check = 0;

	int findAccount = 0;
	int cusLocation = 0;
	int depositAmount = 0;

	if (cusNumber == 0) {
		cout << "Our bank has no Accounts now.\n" << endl;
	}
	else {
		// Account Number
		do {
			cout << "[Deposit Money]" << endl;
			cout << "Account Number: ";
			cin >> findAccount;

			// Check Accounts
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
		cout << "Our bank has no Accounts now.\n" << endl;
	}
	else {
		// Account Number
		do {
			cout << "[Withdraw Money]" << endl;
			cout << "Account Number: ";
			cin >> findAccount;

			// Check Accounts
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
		cout << "Our bank has no Accounts now.\n" << endl;
	}
	else {
		cout << "----- Account lists -----" << endl;
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

	cout << "¡Ø¡Ø¡Ø Banking System Ver 0.6 ¡Ø¡Ø¡Ø\n" << endl;

	while (1) {
		// Show menu & choose the menu number
		handler.ShowMenu();
		cout << "Selection: ";
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