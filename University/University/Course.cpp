
#include "Course.h"

int Course::idGenerator=0;


Course::Course(const string& name, int points, Date& startDate, Date& endDate, Lecturer* lecturer, Tutor* tutor, const ClassRoom& classRoom) :  
					name(name), startDate(startDate), endDate(endDate)
{
	this->id=++idGenerator;
	(this->classRoom)= &(classRoom);
	this->tutor=tutor;
	setPoints(points);
}

Course::~Course()
{
	delete []lecturer;
	delete []tutor;
	int numOfStundets=students.size();
	for (int i=0; i<numOfStundets; i++)
		delete students[i];
}

inline int Course::getId() const { return id; }
inline int Course::getPoints() const { return points; }
inline int Course::getNumberOfStudent() const { return students.size(); }
inline const string Course::getName() const { return name; }
inline const Date& Course::getStartDate() const { return startDate; }
inline const Date& Course::getEndDate() const { return endDate; }
vector<const Student*> Course::getStudents() const { return students; }
inline const Tutor* Course::getTutor() const { return tutor; }
inline const Lecturer* Course::getLecturer() const { return lecturer; }
inline const ClassRoom* Course::getClassRoom() const { return classRoom; }

void Course::setClassRoom(const ClassRoom& classRoom)
{
	if (this->classRoom != &classRoom)
	{
		delete []this->classRoom;
		(this->classRoom) = &classRoom;
	}
}
void Course::setTutor(const Tutor* tutor)
{
	if (this->tutor != tutor)
	{
		delete []this->tutor;
		this->tutor = tutor;
	}
}
void Course::setLecturer(const Lecturer& lecturer)	//lecturer ze deleted function. should be checked l8r
{
	if (this->lecturer != &lecturer)
	{
		delete []this->lecturer;
		(this->lecturer) = &lecturer;
	}
}
void Course::setName(const string& name)
{
	this->name=name;
}
void Course::setPoints(int points) throw (const char*)
{
	if (points < 1)
		throw "points must be posivtive";
	this->points=points;
}
void Course::setStartDate(const Date& startDate)
{
	this->startDate=startDate;
}
void Course::setEndDate(const Date& endDate)
{
	this->endDate=endDate;
}

bool Course::addStudent(const Student& student) 
{
	this->students.push_back(&student);
	return true;
}

bool Course::removeStudent(const Student* other)
{
	int numOfStudents = students.size();
	for (int i=0; i<numOfStudents; i++)
	{
		if (students[i] == other)
		{
			students.erase(students.begin()+i);
			return true;
		}
	}
	return false;
}

bool Course::finishCourse()
{
	Course::~Course();
	return true;
}

const Course& Course::operator+=(const Student& student)
{
	Course::addStudent(student);
	return *this;
}
const Course& Course::operator-=(const Student& student)
{
	Course::removeStudent(&student); 
	return *this;
}

ostream& operator<<(ostream& os, const Course& course)
{
	os << "Course "<< course.getName() << " id: " << course.getId() << ", have " << course.getPoints() << " points. number of register students: " 
		<< course.getNumberOfStudent() << ". \n\tThe course between the dates; " << course.getStartDate() << "-" << course.getEndDate() 
		<< "\n\tThe teaching class number: " << *course.getClassRoom() << endl;
	return os;
}

bool Course::operator==(const Course& other) const
{
	if (this->getId() == other.getId())
		return true;
	return false;
}


bool Course::operator==(int other) const
{
	if (this->getId() == other)
		return true;
	return false;
}

void Course::setId(int id)
{
	this->id=id;
}