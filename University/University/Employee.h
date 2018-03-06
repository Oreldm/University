#ifndef __EMPLOYEE_H
#define __EMPLOYEE_H

#include "State.h"

class Employee : public State
{
public:
	Employee(); 
	~Employee();
	virtual void unemployee(Worker& w);
};

#endif