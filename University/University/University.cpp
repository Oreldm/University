#include "University.h"

University University::theUniversity("Afeka-College");
University* University::getInstance()
{

	return &theUniversity;
}


University::University(const string& name)
{
	this->name=name;
}

inline string University::getName() const
{
	return name;
}

University::~University()
{
	for(int i=0;i<workers.size();i++)
	{
		delete workers[i];
	}
}

vector<const Department*> University::getDepartments() const
{
	return departments;
}


vector<const Worker*> University::getWorkers() const
{
	return this->workers;
}

inline int University::getNumberOfDepartments() const
{
	return departments.size();
}

inline int University::getNumberOfWorkers() const
{
	return workers.size();
}

bool University::addDepartment(const Department& department)
{
	departments.push_back(&department);
	return true;
}

bool University::removeDepartment(const Department& department)
{
	int numberOfDepartments=this->getNumberOfDepartments();
	
	for(int i=0;i<numberOfDepartments;i++)
	{
		if(departments[i]->getId() == department.getId())
		{
			departments.erase(departments.begin()+i);
			return true;
		}
	}
	return false;
}


bool University::addWorker(const Worker& worker)
{
	workers.push_back(new Worker(worker));
	return true;
}

ostream& operator<<(ostream& os, const University& university)
{
	int numberOfDepartments=university.getNumberOfDepartments();
	int numberOfWorkers=university.getNumberOfWorkers();
	os<< "University " << university.getName() << " have: " << "number of workers: " << numberOfWorkers << "total workers." << endl;
	os << "amount of departments= " <<numberOfDepartments << ":\n " << endl;
	for(int i=0;i<numberOfDepartments;i++)
	{
		os << "DEPARTMENT " << i+1 << ":\n";
		os << *(university.getDepartments()[i]) << endl; 
	}
	return os;
}