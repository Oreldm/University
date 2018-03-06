#include "Tutor.h"

Tutor::Tutor(Worker& worker, Department* department) : Worker(worker) , Person(worker)
{
	this->department = department;
}

Tutor::Tutor(const Tutor& other) : Worker(other), Person(other)
{
	this->department=other.department;
}

inline const vector<const Course*> Tutor::getCourses() const
{
	return teachingCourses;
}

inline const Department* Tutor::getDepartment() const
{
	return department;
}

inline int Tutor::getNumberOfCourses() const
{
	return teachingCourses.size();
}

bool Tutor::addCourse(const Course& course)
{
	if(find(teachingCourses.begin(), teachingCourses.end(), &course) != teachingCourses.end()) 
	{
		return false;
	}
	teachingCourses.push_back(&course);
	return true;
}

void Tutor::setDepartment(const Department& department)
{
	this->department=&department;
}

bool Tutor::removeCourse(int courseId)
{
	int numberOfCourses=teachingCourses.size();

	for (int i=0; i<numberOfCourses; i++)
	{
		if (courseId == this->teachingCourses[i]->getId())
		{
			teachingCourses.erase(teachingCourses.begin()+i);
			return true;
		}
	}
	return false;
}

bool Tutor::operator==(const Tutor& other) const
{
	if (this->getId() == other.getId())
		return true;
	return false;
} 


ostream& operator<<(ostream& os, const Tutor& tutor)
{
	os << ((Worker)tutor);
	(tutor).toOs(os);
	return os;
}

bool Tutor::operator==(const int other) const
{
	if(other==this->getId())
		return true;
	return false;
}

void Tutor::toOs(ostream& os) const
{
}