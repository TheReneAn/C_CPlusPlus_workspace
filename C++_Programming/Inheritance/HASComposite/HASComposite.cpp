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

class Police
{
private:
	int handcuffs;	// Number of Cuffs Owned
	Gun* pistol;	// Number of Guns Owned
public:
	Police(int bnum, int bcuff) : handcuffs(bcuff)
	{
		if (bnum > 0) {
			pistol = new Gun(bnum);
		}
		else {
			pistol = NULL;
		}
	}
	void Puthandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL)
			cout << "HUNT BBANG!" << endl;
		else
			pistol->Shot();
	}
	~Police() {
		if (pistol != NULL)
			delete pistol;
	}
};

int main(void)
{
	Police pman1(5, 3);	// Bullet: 5, Cuff: 3
	pman1.Shot();
	pman1.Puthandcuff();

	Police pman2(0, 3);	// Don't have a gun
	pman2.Shot();
	pman2.Puthandcuff();

	return 0;
}