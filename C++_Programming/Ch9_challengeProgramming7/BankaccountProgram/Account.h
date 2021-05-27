/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: Account.h
*/

#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

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
	virtual ~Account();
};

#endif // !__ACCOUNT_H__
