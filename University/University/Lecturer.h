#ifndef __LECTURER_H
#define __LECTURER_H

#include "Worker.h"
#include "Course.h"
#include "Department.h"
#include <vector>
using namespace std;

class Department;
class Student;

class Lecturer : public Worker
{
public:
	Lecturer(Worker& worker);
	bool operator==(const int other) const;
	vector<Course> getCourses() const;
    vector<Department> getDepartments() const;

	bool addCourse(Course& course);
	bool addDepartment(Department& department);
	bool removeCourse(int courseId);
	bool removeDepartment(int departmentId);

	int numberOfCourses;
	int numberOfDepartments;
	bool Lecturer::operator==(const Lecturer& other) const;
	
protected:
	vector<Course>teachingCourses;
	vector<Department>departments;
	void toOs(ostream& os) const;
};

#endif