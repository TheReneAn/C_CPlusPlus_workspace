/*
* Banking System Ver 0.7
* cusName: Rene An
* Content: Splitting files
* File name: BankingSystemMain.cpp
*/

#include "BackingCommonDecl.h"
#include "AccountHandler.h"

int main() {

	AccountHandler handler;
	int menuNum = 0;

	cout << "『『『 Banking System Ver 0.7 『『『\n" << endl;

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