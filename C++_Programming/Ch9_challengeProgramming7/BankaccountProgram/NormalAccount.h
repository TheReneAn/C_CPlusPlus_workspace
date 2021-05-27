/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: NormalAccount.h
*/

#ifndef  __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "BackingCommonDecl.h"
#include "Account.h"

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


#endif // __NORMAL_ACCOUNT_H__
