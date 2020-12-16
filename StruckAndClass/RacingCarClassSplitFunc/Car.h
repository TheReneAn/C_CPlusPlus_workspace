#ifndef __CAR_H__
#define	__CAR_H__

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

#endif