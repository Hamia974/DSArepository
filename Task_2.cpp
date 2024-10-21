#include <iostream>
using namespace std;
class Employee {
public:
	virtual void calculateSalary() = 0;

};
class FullTimeEmployee :public Employee {
private:
	int salary;
public:
	FullTimeEmployee(int s = 0) {
		salary = s;
	}
	void calculateSalary() {
		cout << "Salary of FullTimeEmployee is: " << salary << endl;
	}
};
class HalfTimeEmployee :public Employee {
private:
	int working_hours;
	int hourly_rate;
public:
	HalfTimeEmployee(int h=0,int r=0){
		working_hours = h;
		hourly_rate = r;
	}
	void calculateSalary() {
		int s;
	s = 26*working_hours * hourly_rate;
		cout << "calculateSalary of HalfTimeEmployee is: " <<s << endl;
	}
};
int main() {
	FullTimeEmployee full(80000);
	Employee* s;
	s = &full;
	s->calculateSalary();
    int h, r;
	cout << "enter hourly rate of half time employee: ";
	cin >> r;
	cout << "enter working hours of half time employee: ";
	cin >> h;
	HalfTimeEmployee half (h, r);

	s = &half;
	s->calculateSalary();
	return 0;
}