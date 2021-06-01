#include <iostream>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) : bullet(bnum)
	{ }
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police {
private:
	int handcuffs;
	Gun* pistol;
public:
	Police(int bnum, int bcuff) 
		: handcuffs(bcuff)
	{
		if (bnum > 0) {
			pistol = new Gun(bnum);
		}
		else {
			pistol = NULL;
		}
	}

	// Copy Constructor
	Police(const Police& ref)
		: handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL) {
			pistol = new Gun(*(ref.pistol));
		}
		else {
			pistol = NULL;
		}
	}
	// Assignment operator
	Police& operator= (const Police& ref) {
		if (pistol != NULL) {
			delete pistol;
		}

		if (ref.pistol != NULL) {
			pistol = new Gun(*(ref.pistol));
		}
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;

		return *this;
	}

	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}
	void Shot() {
		if (pistol == NULL) {
			cout << "Hut BBANG!" << endl;
		}
		else {
			pistol->Shot();
		}
	}
	~Police() {
		if (pistol != NULL) {
			delete pistol;
		}
	}
};

int main() 
{
	Police pman1(5, 3);
	Police pman2 = pman1;	// Copy constructor
	pman2.Shot();
	pman2.PutHandcuff();

	Police pman3(0, 3);
	pman3 = pman1;			// Assignment operator
	pman3.Shot();
	pman3.PutHandcuff();

	return 0;
}

