#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Employee		// Abstract Class
{
private:
	char name[100];
public:
	Employee(const char* name) {
		strcpy(this->name, name);
	}

	void ShowYourName() const {
		cout << "name: " << name << endl;
	}

	// Pure Virtual Functions
	virtual int GetPay() const = 0;
	virtual void ShowSalaryInfo() const = 0;
};

class PermanentWorker : public Employee
{
private:
	int salary;			// Monthly salary
public:
	PermanentWorker(const char* name, const int money)
		: Employee(name), salary(money)
	{ }

	int GetPay() const {
		return salary;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;		// Total working time this month
	int payPerHour;		// Hourly wage
public:
	TemporaryWorker(const char* name, const int pay)
		: Employee(name), workTime(0), payPerHour(pay)
	{ }
	void AddWorkTime(int time) {
		workTime += time;
	}

	int GetPay() const {
		return workTime * payPerHour;
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;		// Total sales result this month
	double bonusRatio;		// Bonus Ratio
public:
	SalesWorker (const char* name, const int money, const double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{ }
	void AddSalesResult(int value) {
		salesResult += value;
	}

	int GetPay() const {
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	void ShowSalaryInfo() const {
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0)
	{ }

	void AddEmployee(Employee* emp) {
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const {
		for (int i = 0; i < empNum; i++) {
			empList[i]->ShowSalaryInfo();
		}
	}
	void ShowTotalSalary() const {
		int sum = 0;
		for (int i = 0; i < empNum; i++) {
			sum += empList[i]->GetPay();
		}
		cout << "salary sum: " << sum << endl;
	}

	~EmployeeHandler() {
		for (int i = 0; i < empNum; i++) {
			delete empList[i];
		}
	}
};

int main(void)
{
	// Create objects for control classes designed for staff management purposes
	EmployeeHandler handler;

	// Full-time registration
	handler.AddEmployee(new PermanentWorker("Rene", 1000));
	handler.AddEmployee(new PermanentWorker("Youjin", 1500));

	// Temporary Worker registration
	TemporaryWorker* alba = new TemporaryWorker("Jung", 700);
	alba->AddWorkTime(5);
	handler.AddEmployee(alba);

	// Sales Worker registration
	SalesWorker* seller = new SalesWorker("Hong", 1000, 0.1);
	seller->AddSalesResult(7000);
	handler.AddEmployee(seller);

	// Information on pay due this month
	handler.ShowAllSalaryInfo();

	// Total Salary on pay due this month
	handler.ShowTotalSalary();

	return 0;
}