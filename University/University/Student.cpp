#include "Student.h"

Student::Student(Person& person) : Person(person)
{
	this->totalPoints=0;
	this->department=nullptr;
}

Student::Student(const Student& other) : Person(other)
{
	*this=other;
}

const Student& Student::operator=(const Student& other)
{
	this->totalPoints=other.totalPoints;
	this->department=other.department;
	int numOfCourses=courses.size();
	for(int i=0;i<numOfCourses; i++)
	{
		this->courses[i]=other.courses[i];
	}
	for (int i=0; i<numOfCourses; i++)
		for (int j=0; j<GRADES; j++)
			this->grades[i][j] = other.grades[i][j];
	return *this;
}


const vector<Course*> Student::getCourses() const
{
	return courses;
}

inline const Department& Student::getDepartment() const
{
	return *department;
}

double Student::getAverage() const
{
	int numOfCourses=courses.size();
	int sum=0;
	for (int i=0; i<numOfCourses; i++)
		sum+=this->grades[i][1];
	if (numOfCourses != 0)
		return sum/numOfCourses;
	return 0;
}
inline double Student::getTotalPoints() const
{
	return totalPoints;
}
int Student::getNumOfCourses() const
{
	return courses.size();
}

void Student::setDepartment(const Department& department)
{
	this->department=&department;
}

bool Student::courseSignUp(const Course* other)
{
	int numOfCourses = courses.size();
	
	for (int i=0; i<numOfCourses; i++)
	{
		if (courses[i] == other)
			throw "You allready signed!";
	}
	courses.push_back(new Course(*other));
	grades[numOfCourses][0]=other->getId();
	grades[numOfCourses][1]=0;
	return true;
}
 
bool Student::courseFinish(int courseId) 
{
	int numOfCourses=courses.size();
	for (int i=0; i<numOfCourses; i++)
	{
		if (courses[i]->getId() == courseId)
		{
			this->totalPoints+=courses[i]->getPoints(); 
			courses.erase(courses.begin()+i);
			return true;
		}
	}
	return false;
}


double Student::avgCalculate() const
{
	int numOfCourses=courses.size();
	int sum=0;
	for (int i=0; i<numOfCourses; i++)
	{
		sum+=courses[i]->getPoints();
	}
	if (numOfCourses != 0)
		return sum/numOfCourses;
	throw "Cant divide by zero!";
}

int Student::getGrade(int courseId) const
{
	int numOfCourses=courses.size();
	for (int i=0; i<numOfCourses; i++)
		if (grades[i][0] == courseId)
			return grades[i][1];
	throw "the student doesnt teach this course!";
}

bool Student::setGrade(int courseId, int grade) throw (const string&)
{
	int numOfCourses=courses.size();
	for(int i=0; i<numOfCourses;i++)
	{
		if(grades[i][0]==courseId)
		{
			grades[i][1]=grade;
			return true;
		}
	}

}

void Student::toOs(ostream& os) const
{
	os << "\tthat learn: " << this->getNumOfCourses() << " Courses, with total points: " << this->getTotalPoints()
		<< " Student Average: " << this->getAverage() << endl;
}

bool Student::operator<(const Student& other) const
{
	if (this->getAverage() < other.getAverage())
		return true;
	return false;
}

bool Student::operator==(const Student& other) const
{
	if(this->getId()==other.getId())
	{
		return true;
	}
	return false;
}

bool Student::operator==(int other) const
{
	if(this->getId()==other)
	{
		return true;
	}
	return false;
}
