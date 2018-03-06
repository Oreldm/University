#ifndef __COURSE_H
#define __COURSE_H

#include "Date.h"
#include "ClassRoom.h"
#include <iostream>
#include <vector>
using namespace std;
#define MAX_STUDENTS_IN_COURSE 20 //added by me

class Student;
class Lecturer;
class Tutor;
class Course
{

public:
	Course();
	Course(const string& name, int points, Date& startDate, Date& endDate, Lecturer* lecturer, Tutor* tutor, const ClassRoom& classRoom);	//changed to Date&, Lecturer&, Tutor& and ClassRoom& (from *)
	~Course();


	inline int getId() const;
	inline int getPoints() const;
	inline int getNumberOfStudent() const;
	inline const string getName() const;
	inline const Date& getStartDate() const;
	inline const Date& getEndDate() const;
	vector<const Student*> Course::getStudents() const;
	inline const Tutor* getTutor() const;
	inline const Lecturer* getLecturer() const;
	inline const ClassRoom* getClassRoom() const;

	void setClassRoom(const ClassRoom& classRoom);
	void setTutor(const Tutor* tutor);
	void setLecturer(const Lecturer& lecturer);
	void setId(int id);

	bool addStudent(const Student& student);
	bool removeStudent(const Student* other);
	bool finishCourse();

	// add student to course
	const Course& operator+=(const Student& student);
	// remove student from couse
	const Course& operator-=(const Student& student);
//	const Course& operator=(const Course& other) = delete;
	friend ostream& operator<<(ostream& os, const Course& course);



	void setName(const string& name); //added by me
	void setPoints(int points); //added by me
	void setStartDate(const Date& startDate); //added by me
	void setEndDate(const Date& startDate); //added by me
	bool operator==(const Course& other) const; //added by me.
	bool operator==(int other) const;
	Student& operator[](const string& name); //Student& cause maybe we will want to change the obj


private:
	const Tutor* tutor;
	int id;
	string name;
	int points;
	Date startDate;
	Date endDate;
	vector<const Student*> students;

	//const Student** students; //added const
	const Lecturer* lecturer;
	const ClassRoom* classRoom;
	static int idGenerator; //changed to privated from public

};

#endif