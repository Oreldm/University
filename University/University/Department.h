#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H

#include "Lecturer.h"
#include "Student.h"
#include "Tutor.h"
#include "Course.h"
#include "ClassRoom.h"
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Course;
class Department 
{

public:
    static int idGenerator;

	Department(const string& name , int id);

	vector<Course*> Department::getCourses() const;
	vector<Student> getStudents() const;
	vector<Tutor> getTutors() const;
	vector<Lecturer> getLecturers() const;
	int getId() const;

	bool addStudent(Student& student);
	bool addCourse(Course& course);
	bool addLecturer(Lecturer& lecturer);
	bool addTutor(Tutor& tutor);
	bool removeStudent(int studentId);
	bool removeCourse(int courseId);
	bool removeLecturer(int lecturerId);
	bool removeTutor(int tutorId);

	friend ostream& operator<<(ostream& os, const Department& department);
	bool operator==(const Department& other) const;

private:
    int id;
    string name;

	vector<Lecturer>lecturers;
	vector<Tutor>tutors;
	vector<Course*>courses;
	vector<Student>students;
};

#endif