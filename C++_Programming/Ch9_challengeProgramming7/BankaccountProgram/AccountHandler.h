/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: AccountHandler.h
*/

#ifndef _ACCOUNT_HANDLER_H__
#define _ACCOUNT_HANDLER_H__

#include "Account.h"
#include "BackingCommonDecl.h"

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

#endif // !_ACCOUNT_HANDLER_H__
