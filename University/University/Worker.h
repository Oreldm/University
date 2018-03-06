#ifndef __WORKER_H
#define __WORKER_H

#include "Person.h"

class State;
class Worker : virtual public Person
{

protected:
	double salary;
	State* current;

public:
	Worker(const Person& person, double salary = 0); //added const to Person& person
	Worker(const Worker& worker);
	~Worker();

	inline double getSalary() const;

	void setSalary(double salary);
	
	virtual void toOs(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Worker& worker);

	void setCurrent(State* s){current = s;}
	void employee();
	void unemployee();

};

#endif