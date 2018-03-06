#include "Department.h"

Department::Department(const string& name, int id)
{
	this->name=name;
	this->id= id;
}

	vector<Course*> Department::getCourses() const
	{
		return courses;
	}
	vector<Student> Department::getStudents() const
	{
		return students;
	}
	vector<Tutor> Department::getTutors() const
	{
		return tutors;
	}
	vector<Lecturer> Department::getLecturers() const
	{
		return lecturers;
	}


	int Department::getId() const
	{
		return this->id;
	}

	bool Department::addStudent(Student& student)
	{
		students.push_back(student);
		return true;
	}

	bool Department::operator==(const Department& other) const
	{
		if(this->getId()==other.getId())
		{
			return true;
		}
		return false;
	}

	bool Department::addCourse(Course& course)
	{
				
		vector<Course*>::iterator itr= courses.begin();
		vector<Course*>::iterator itrEnd= courses.end();
		int id=course.getId();
		
		for(int pos=0;itr!=itrEnd;++itr, pos++)
		{
			if((*itr)->getId() == id)
			{
				return false;
			}
		}

		courses.push_back(new Course(course));
		return true;
	}

	bool Department::addLecturer(Lecturer& lecturer)
	{
		if(find(lecturers.begin(), lecturers.end(), lecturer) != lecturers.end()) 
		{
			return false;
		} 

		(this->lecturers).push_back(lecturer);
		return true;
	}

	
	bool Department::addTutor(Tutor& tutor)
	{
		if(find(tutors.begin(), tutors.end(), tutor) != tutors.end()) 
		{
			return false;
		} 
		
		(this->tutors).push_back(tutor);
		return true;
	}


bool Department::removeStudent(int studentId)
	{
		if(find(students.begin(), students.end(), studentId) != students.end()) 
		{
			int pos=distance(students.begin(), find(students.begin(), students.end(), studentId));
			students.erase(students.begin()+pos);
			return true;
		}
		return false;
	}

	bool Department::removeCourse(int courseId)
	{
		vector<Course*>::iterator itr= courses.begin();
		vector<Course*>::iterator itrEnd= courses.end();
		
		for(int pos=0;itr!=itrEnd;++itr, pos++ )
		{
			if((*itr)->getId() == courseId)
			{
				courses.erase(courses.begin()+pos);
				return true;
			}
		}
		return false;
	}

	bool Department::removeLecturer(int lecturerId)
	{
		const Date d1(1992,5,5);
		const Address addr("asd","asd",3);
		string tempName="asd";
		const Person p(lecturerId,tempName,d1,addr);
		Worker* w=new Worker(p);
		Lecturer *l=new Lecturer(*w);

		if(find(lecturers.begin(), lecturers.end(), *l) != lecturers.end()) 
		{
			int pos=distance(lecturers.begin(), find(lecturers.begin(), lecturers.end(), lecturerId));
			lecturers.erase(lecturers.begin()+pos);
			return true;
		}
		return false;
	}

	bool Department::removeTutor(int tutorId)
	{
		const Date d1(1992,5,5);
		const Address addr("asd","asd",3);
		string tempName="asd";
		Person p(tutorId,tempName,d1,addr);
		Worker w(p);
		Department d("name",2);
		Tutor* t=new Tutor(w,&d);

	if(find(tutors.begin(), tutors.end(), *t) != tutors.end()) 
		{
			int pos=distance(tutors.begin(), find(tutors.begin(), tutors.end(), tutorId));
			tutors.erase(tutors.begin()+pos);
			return true;
		}
		return false;
	}

	ostream& operator<<(ostream& os, const Department& department)
	{
		os << "Deparment Name: " <<department.name <<"\tID: " << department.id << endl << "Lecturers : " <<endl;
		for(int i=0; i<department.lecturers.size(); i++)
		{
			os<< department.lecturers[i] ;
		}
		os << endl << "Tutors: " <<endl;

		for(int i=0; i<department.tutors.size(); i++)
		{
			os<< department.tutors[i] ;
		}
		os << endl << "Courses: " <<endl;
		for(int i=0; i<department.courses.size(); i++)
		{
			os<< *department.courses[i] ;
		}
		os << endl << "Students: " <<endl;
		for(int i=0; i<department.students.size(); i++)
		{
			os<< department.students[i] ;
		}

		return os;
	}
