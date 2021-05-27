/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: HighCreditAccount.h
*/

#ifndef __HIGHCREDIT_ACCOUNT_H__
#define __HIGHCREDIT_ACCOUNT_H__

#include "NormalAccount.h"

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

#endif // !__HIGHCREDIT_ACCOUNT_H__

