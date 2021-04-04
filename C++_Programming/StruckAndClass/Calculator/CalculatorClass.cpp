#include <iostream>
using namespace std;

class Calculator
{
private:
	int totalAddNum;
	int totalMinNum;
	int totalDivNum;
	int totalMulNum;

public:
	void Init();
	double Add(double input1, double input2);
	double Min(double input1, double input2);
	double Div(double input1, double input2);
	double Mul(double input1, double input2);

	void ShowOpCount();
};

void Calculator::Init() {
	totalAddNum = 0;
	totalMinNum = 0;
	totalDivNum = 0;
	totalMulNum = 0;
}

double Calculator::Add(double input1, double input2)
{
	totalAddNum++;
	return input1 + input2;
}

double Calculator::Min(double input1, double input2)
{
	totalMinNum++;
	return input1 - input2;
}

double Calculator::Div(double input1, double input2)
{
	totalDivNum++;
	return input1 / input2;
}

double Calculator::Mul(double input1, double input2)
{
	totalMulNum++;
	return input1 * input2;
}

void Calculator::ShowOpCount()
{
	cout << "Add: " << totalAddNum << " Min: " << totalMinNum << " Mul: " << totalMulNum << " Div: " << totalDivNum << endl;
}

int main(void)
{
	Calculator cal;
	cal.Init();

	cout << "3.4 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "2.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;

	cal.ShowOpCount();

	return 0;
}