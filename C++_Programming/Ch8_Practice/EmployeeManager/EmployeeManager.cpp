#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
using namespace std;

const int EMP_NUM = 50;

class Employee {
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}

	// Print Info
	void ShowYourName() const {
		cout << "Name: " << name << endl;
	}
};

class PermanentWorker : public Employee {
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money)
	{ }

	int GetPay() const { return salary; }

	// Print Info
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << salary << endl;
	}
};

class TemporaryWorker : public Employee {
private:
	int workTime;		// Total number of hours worked this month.
	int payPerHour;		// Hourly pay
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }

	void AddWorkTime(int time) {
		workTime += time;
	}

	int GetPay() const { return workTime * payPerHour; }

	// Print Info
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "Salary: " << GetPay() <<endl << endl;
	}
};

class SaleWorker : public PermanentWorker {
private:
	int saleResult;			// Monthly Sales Performance
	double bounusRatio;
public:
	SaleWorker(const char* name, int money, double ratio) 
		: PermanentWorker(name, money), saleResult(0), bounusRatio(ratio)
	{	}

	void AddSaleResult(int value) {
		saleResult += value;
	}

	int GetPay() const {
		return PermanentWorker::GetPay()		// PermanenWorker's GetPay()
			+ (int)(saleResult * bounusRatio);
	}

	// Print Info
	void ShowSalaryInfo() const {
		ShowYourName();
		// SaleWorker's GetPay()
		cout << "Salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler {
private:
	Employee* empList[EMP_NUM];		// 50
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{
		for (int i = 0; i < EMP_NUM; i++) {
			empList[i] = nullptr;
		}
	}

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}

	// Print Info
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {

		}
	}
	void ShowTotalSalary() const {
		int sum = 0;

		for (int i = 0; i < empNum; i++) {

		}

		cout << "Salary sum: " << sum << endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main()
{
	// Create objects for control classes designed for employees management
	EmployeeHandler handler;

	// Add PermanentWorker
	handler.AddEmployee(new PermanentWorker("KIM", 1000));
	handler.AddEmployee(new PermanentWorker("LEE", 1500));

	// Add TemporaryWorker
	TemporaryWorker* partTime = new TemporaryWorker("Jung", 700);
	partTime->AddWorkTime(5);	// The worker worked 5 hours
	handler.AddEmployee(partTime);

	// Add SalesWorker
	SaleWorker* seller = new SaleWorker("Hong", 100, 0.1);
	seller->AddSaleResult(700);
	handler.AddEmployee(seller);

	// Information on salaries due this month.
	handler.ShowAllSalaryInfo();

	// Information on salaries's total due this month.
	handler.ShowTotalSalary();

	return 0;
}
