#include "Employee.h"
#include "Unemployee.h"

Employee::Employee()    {cout << "   ON-ctor\n";}
Employee::~Employee()   {cout << "   dtor-ON\n";}

void Employee::unemployee(Worker& w)
{
	cout << "   Worker is now going to be unemployee";
	w.setCurrent(new Unemployee());
	delete this;
}