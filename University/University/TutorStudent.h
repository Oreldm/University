#ifndef __TUTOR_STUDENT_H
#define __TUTOR_STUDENT_H
#include "Student.h"
#include "Tutor.h"

class TutorStudent : public Student , virtual public Tutor
{

public:
	TutorStudent(Student& student, Tutor& tutor);

	virtual void toOs (ostream& os) const;

};

#endif