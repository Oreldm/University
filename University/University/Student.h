#ifndef __STUDENT_H
#define __STUDENT_H

#include "Person.h"
#include <iostream>
#include "Course.h"
#include <map>
using namespace std;

class Department;
class Student : virtual public Person
{

public:
	static const int MAX_NUMBER_OF_COURSES = 20;
	static const int GRADES = 2;

	Student(Person& person);
	Student(const Student& other);

	const vector<Course*> getCourses() const;
	inline const Department& getDepartment() const;
	double getAverage() const;
	inline double getTotalPoints() const;
	int getGrade(int courseId) const throw (const string&);

	void setDepartment(const Department& department);

	bool courseSignUp(const Course* other);
	bool courseFinish(int courseId);
	double avgCalculate() const;
	
	const Student& operator=(const Student& other);
	bool operator==(const Student& other) const;
	bool operator==(int other) const;
	virtual void toOs(ostream& os) const;


	int getNumOfCourses() const; // added by me
	bool setGrade(int courseId, int grade) throw (const char*);
	bool operator<(const Student& other) const; //added

	
protected:
	vector<Course*> courses;
	const Department* department;
	double totalPoints;
	int grades[MAX_NUMBER_OF_COURSES][GRADES];
};

#endif