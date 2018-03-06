#ifndef __STATE_H
#define __STATE_H

#include <iostream>
#include "Worker.h"
using namespace std;


class State
{
public:
	virtual void employee(Worker& w) const
	{
		cout << "   Worker is employee\n";
	}

	virtual void unemployee(Worker& w) const
	{
		cout << "   Worker is unemployee\n";
	}
};  // State

#endif // __STATE_H