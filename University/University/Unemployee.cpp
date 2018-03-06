#include "Employee.h"
#include "Unemployee.h"

Unemployee::Unemployee()    {cout << "   OFF-ctor\n";}
Unemployee::~Unemployee()   {cout << "   dtor-OFF\n";};

void Unemployee::employee(Worker& w)
{
	cout << "   Worker is now employee!";
	w.setCurrent(new Employee());
	delete this;
}