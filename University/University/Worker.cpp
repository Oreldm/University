
#include "Worker.h"
#include "State.h"

#include "Employee.h"
#include "Unemployee.h"

Worker::Worker(const Person& person, double salary) : Person(person), salary(salary) {current = new Unemployee();}
Worker::Worker(const Worker& worker) : Person(worker), salary(worker.getSalary()) {current = new Employee();}
Worker::~Worker() { delete current;}


inline double Worker::getSalary() const { return salary; }
void Worker::setSalary(double salary)
{
	this->salary=salary;
}

void Worker::toOs(ostream& os) const
{
}

ostream& operator<<(ostream& os, const Worker& worker)
	{
		os << ((Person)worker);
		os << "\tSalary: " << worker.getSalary() << endl;
		(worker).toOs(os);
		return os;
	}

void Worker::employee()  
{
	current->employee(*this);
}

void Worker::unemployee() 
{
	current->unemployee(*this);
}
