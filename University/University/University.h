#ifndef __UNIVERSITY_H
#define __UNIVERSITY_H

#include "Worker.h"
#include "Department.h"
#include <iostream>
using namespace std;

class University 
{

public:
	static University* getInstance();

	static const int MAX_NUMBER_OF_WORKERS		= 200;
	
	~University();
	inline string getName() const;
	vector<const Department*> getDepartments() const;
	vector<const Worker*> getWorkers() const;
	inline int getNumberOfDepartments() const;
	inline int getNumberOfWorkers() const;
	bool addDepartment(const Department& department);
	bool addWorker(const Worker& worker);
	bool removeDepartment(const Department& department);

	friend ostream& operator<<(ostream& os, const University& university);

private:
	string name;
	vector<const Department*>departments;
	vector<const Worker*>workers;
	static University theUniversity;
	University(const string& name);
};

#endif