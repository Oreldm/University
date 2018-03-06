#include "TutorStudent.h"


TutorStudent::TutorStudent(Student& student, Tutor& tutor): Student(student) , Tutor(tutor), Worker(student), Person(student)
{ 
}

void TutorStudent::toOs(ostream& os) const
{
	os<< "\tis a Tutor Student " <<endl;
}