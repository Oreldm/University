#include "Lecturer.h"

Lecturer::Lecturer(Worker& worker) : Worker(worker), Person(worker)
{
	numberOfCourses=0;
	numberOfDepartments=0;
}


vector<Course> Lecturer::getCourses() const
{
	if (numberOfCourses >0 )
		return teachingCourses;
	throw "unable to get courses";
}

vector<Department> Lecturer::getDepartments() const
{
	if(numberOfDepartments >0 )
		return departments;
	throw "unable to get department";
}

bool Lecturer::addCourse(Course& course)
{
	teachingCourses.push_back(course);
	return true;
}

bool Lecturer::addDepartment(Department& department)
{
	departments.push_back(department);
	numberOfDepartments++;
	return true;
}

bool Lecturer::removeCourse(int courseId)
{
	if(numberOfCourses==0)
		return false;

	for(int i=0; i<numberOfCourses; i++)
	{
		if(teachingCourses[i].getId() == courseId)
		{
			teachingCourses[i]=teachingCourses[numberOfCourses-1];
			numberOfCourses--;
		}
	}
}

bool Lecturer::removeDepartment(int departmentId)
{
	if(numberOfDepartments==0)
		return false;

	for(int i=0; i<numberOfDepartments; i++)
	{
		if(departments[i].getId() == departmentId)
		{
			departments[i]=departments[numberOfDepartments-1];
			numberOfDepartments--;
		}
	}
}
void Lecturer::toOs(ostream& os) const
{
	os << "\tis a LECTURER" << endl;
}


bool Lecturer::operator==(const int other) const
{
	if(this->getId()==other)
		return true;
	return false;
}

bool Lecturer::operator==(const Lecturer& other) const
{
	/*if(this->getId()==other.getId())
		return true;
	return false;*/
	return *this==other.getId();
}