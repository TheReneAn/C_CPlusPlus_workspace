#include <iostream>
using namespace std;

#define ID_LEN		20
#define MAX_SPD		200
#define FUEL_STEP	2
#define ACC_STEP	10
#define BRK_STEP	10

struct Car {
	char gamerID[ID_LEN];	// User ID
	int fuelGauge;			// Fuel Gauge
	int curSpeed;			// Current Speed
};

void ShowCarState(const Car& car)
{
	cout << "User ID: " << car.gamerID << endl;
	cout << "Fuel Gauge: " << car.fuelGauge << "%" << endl;
	cout << "Current Speed: " << car.curSpeed << "km/s" << endl;
}

void Aceel(Car& car)
{
	if (car.fuelGauge <= 0) {
		return;
	}
	else {
		car.fuelGauge -= FUEL_STEP;
	}

	if (car.curSpeed + ACC_STEP > MAX_SPD) {
		car.curSpeed = MAX_SPD;
		return;
	}

	car.curSpeed += ACC_STEP;
}

void Break(Car& car) {
	if (car.curSpeed < BRK_STEP) {
		car.curSpeed = 0;
		return;
	}

	car.curSpeed -= BRK_STEP;
}

int main(void) {
	Car run99 = { "run99", 100, 0 };
	Aceel(run99);
	Aceel(run99);
	ShowCarState(run99);

	cout << endl;
	Break(run99);
	ShowCarState(run99);

	return 0;
}