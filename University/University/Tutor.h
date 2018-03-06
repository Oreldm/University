#ifndef __TUTOR_H
#define __TUTOR_H

#include "Course.h"
#include "Worker.h"
#include <algorithm>
using namespace std;

class Department;
class Tutor : virtual public Worker
{

public:
	static const int MAX_NUMBER_OF_CORESES = 20;

	Tutor(Worker& worker, Department* department);
	Tutor(const Tutor& other);

	inline const vector<const Course*> getCourses() const;
	inline const Department* getDepartment() const;
	inline int getNumberOfCourses() const;

	bool addCourse(const Course& course);
	void setDepartment(const Department& department);
	bool removeCourse(int courseId);

	bool operator==(const Tutor& other) const;
	bool operator==(const int other) const;
	virtual void toOs(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Tutor& tutor);

protected:
	
	vector<const Course*>teachingCourses;
	const Department* department;
};

#endif