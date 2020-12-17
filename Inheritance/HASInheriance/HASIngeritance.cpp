#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Gun
{
private:
	int bullet;		// Number of loaded bullets
public:
	Gun(int bnum) : bullet(bnum) { }
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police : public Gun
{
private:
	int handcuffs;	// Number of Cuffs Owned
public:
	Police(int bnum, int bcuff)
		: Gun(bnum), handcuffs(bcuff)
	{ }
	void Puthandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
};

int main(void) 
{
	Police pman(5, 3);	// Bullet: 5, Cuff: 3
	pman.Shot();
	pman.Puthandcuff();
	
	return 0;
}