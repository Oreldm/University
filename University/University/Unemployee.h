#ifndef __UNEMPLOYEE_H
#define __UNEMPLOYEE_H

#include "State.h"
#include <iostream>
using namespace std;

class Unemployee : public State
{
public:
	Unemployee();
	~Unemployee();
	virtual void employee(Worker& w);
};


#endif