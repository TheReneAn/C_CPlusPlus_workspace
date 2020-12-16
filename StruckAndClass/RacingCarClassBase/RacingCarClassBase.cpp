#define _CRT_SECURE_NO_WARNINGS			// For "strcpy"

#include <iostream>
#include <cstring>
using namespace std;

namespace CAR_CONST
{
	enum
	{
		ID_LEN = 20,
		MAX_SPD = 200,
		FUEL_STEP = 2,
		ACC_STEP = 10,
		BRK_STEP = 10
	};
}

class Car
{
private:
	char gamerID[CAR_CONST::ID_LEN];	// User ID
	int fuelGauge;						// Fuel Gauge
	int curSpeed;						// Current Speed
public:
	void InitMembers(const char* ID, int fuel);
	void ShowCarstate();
	void Accel();
	void Break();
};

void Car::InitMembers(const char* ID, int fuel)
{
	strcpy(gamerID, ID);
	fuelGauge = fuel;
	curSpeed = 0;
}

void Car::ShowCarstate()
{
	cout << "User ID: " << gamerID << endl;
	cout << "Fuel Gauge: " << fuelGauge << "%" << endl;
	cout << "Current Speed: " << curSpeed << "km/s" << endl;
}

void Car::Accel()
{
	if (fuelGauge <= 0) {
		return;
	}
	else {
		fuelGauge -= CAR_CONST::FUEL_STEP;
	}

	if (curSpeed + CAR_CONST::ACC_STEP > CAR_CONST::MAX_SPD) {
		curSpeed = CAR_CONST::MAX_SPD;
		return;
	}

	curSpeed += CAR_CONST::ACC_STEP;
}

void Car::Break() {
	if (curSpeed < CAR_CONST::BRK_STEP) {
		curSpeed = 0;
		return;
	}

	curSpeed -= CAR_CONST::BRK_STEP;
}

int main(void) {
	Car run99;

	run99.InitMembers("run99", 100);

	run99.Accel();
	run99.Accel();
	run99.Accel();
	run99.ShowCarstate();

	cout << endl;
	run99.Break();
	run99.ShowCarstate();

	return 0;
}