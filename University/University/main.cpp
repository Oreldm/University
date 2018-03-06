#pragma warning( disable : 4290 )
#include "Address.h"
#include "ClassRoom.h"
#include "Date.h"
#include "University.h"
#include "TutorStudent.h"
#include "Department.h"
#include "Tutor.h"
#include "Cleaner.h"
#include "Worker.h"
#include "Person.h"
#include "Lecturer.h"
#include "Student.h"
#include "MyLinkedList.h"
#include <time.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

void printRiskStudents(const Department& department)
{
		cout << "PRINTING STUDENTS IN RISK! : " << endl ;
		int sum=0;
		for(int i=0;i<department.getLecturers().size();i++)
		{
			if (((department.getStudents()[i])).getAverage() < 65)
			{
				cout << department.getStudents()[i]<< "   " <<endl;
				sum++;
			}
		}
		if (sum==0)
			cout << "There is no Students in risk!" << endl;
		cout<< "\n\n" << endl;
}

Worker* getWorkerFromLinkedList(const MyLinkedList<Worker*>& workers, int index)
{
	Node<Worker*>* workerNode=workers.getHead();
	for(int i=0;i<index;i++)
	{
		workerNode=workerNode->getNext();
	}
	
	return (workerNode->getData());
}

int main(int argc, const char * argv[])
{
	const int NAMES_ARR_SIZE = 15;
    const int ADDRESSES_ARR_SIZE = 15;
    int namesIndx = 0;
    int addressIndx = 0;

	vector<string> names;
	names.push_back("Guy");
	names.push_back("Orel");
	names.push_back("Tomer");
	names.push_back("Lotem");
	names.push_back("Miri");
	names.push_back("Bibi");
	names.push_back("Bar");
	names.push_back("Dolev");
	names.push_back("Ofek");
	names.push_back("Natali");
	names.push_back("Shani");
	names.push_back("Meni");
	names.push_back("Muhamad");
	names.push_back("Dana");
	names.push_back("Din");

	srand(time(NULL)); 

	vector<Address*> addresses;
	addresses.push_back(new Address("Tel-Aviv","Moshe-Sne", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Beit-El", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Meyasdim", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Hanegev", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Tzionut", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Alon", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Dekel", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Kafrisin", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Istadrut", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Zalman", rand()%200+1));
	addresses.push_back(new Address("Tel-Aviv","Herzel", rand()%200+1));

	Date d1(1951,2,21);

	try
	{
		University afeka= *(University::getInstance());
		Department software("Software" , 42);
		Department electricity("Electricity", 53);


		afeka.addDepartment(software);
		afeka.addDepartment(electricity);

		vector<Student*> students;

		addressIndx=0;
		for(int i=0;
            i < 7 && namesIndx < NAMES_ARR_SIZE && addressIndx < ADDRESSES_ARR_SIZE;
            i++, namesIndx++, addressIndx++)
		{
            Person p(i, names[namesIndx], d1, *addresses[addressIndx]);
			students.push_back(new Student(p));
            if((i%2)==0)
                software.addStudent(*students[i]);
			else
                electricity.addStudent(*students[i]);
		}
		addressIndx=0;

		MyLinkedList<Worker*> workers;
		
		for(int i=0;
			i < 10 && namesIndx < NAMES_ARR_SIZE && addressIndx < ADDRESSES_ARR_SIZE;
            i++, namesIndx++, addressIndx++)
		{
			Person p(i, names[namesIndx], d1, *addresses[addressIndx]);
			workers.add(new Worker(p));

			Worker* tempWorker = (getWorkerFromLinkedList(workers,i));
			tempWorker->setSalary(rand()%5000+15000);
			afeka.addWorker(*tempWorker);
		}

		Lecturer* lecturer1 = new Lecturer(*getWorkerFromLinkedList(workers,0));
        Lecturer* lecturer2 = new Lecturer(*getWorkerFromLinkedList(workers,1));
        Lecturer* lecturer3 = new Lecturer(*getWorkerFromLinkedList(workers,2));
        Lecturer* lecturer4 = new Lecturer(*getWorkerFromLinkedList(workers,3));

		Tutor* tutor1 = new Tutor(*getWorkerFromLinkedList(workers,4), &software);
        Tutor* tutor2 = new Tutor(*getWorkerFromLinkedList(workers,5), &software);
        Tutor* tutor3 = new Tutor(*getWorkerFromLinkedList(workers,6), &electricity);
        Tutor* tutor4 = new Tutor(*getWorkerFromLinkedList(workers,7), &electricity);

        TutorStudent* tutorStudent = new TutorStudent(*students[0], *tutor4);

        Cleaner* cleaner = new Cleaner(*getWorkerFromLinkedList(workers,7));

        software.addLecturer(*lecturer1);
        software.addLecturer(*lecturer2);
        electricity.addLecturer(*lecturer3);
        electricity.addLecturer(*lecturer4);

        software.addTutor(*tutor1);
        software.addTutor(*tutor2);
        software.addTutor(*tutorStudent);

        electricity.addTutor(*tutor3);
        electricity.addTutor(*tutor4);

        vector<ClassRoom*> classRooms;
		classRooms.push_back(new ClassRoom(rand()%10+15, true, false));
		classRooms.push_back(new ClassRoom(rand()%10+15, false, false));
		classRooms.push_back(new ClassRoom(rand()%10+15, false, true));
		classRooms.push_back(new ClassRoom(rand()%10+15, true, true));

		vector<Course*>courses;
		courses.push_back(new Course("Hedva", 5, Date(2017,10,18), Date(2017,1,17), lecturer1, tutor1, *classRooms[0]));
		courses.push_back(new Course("Liniar-Algebra", 2, Date(2017,10,18), Date(2017,1,17), lecturer2, tutor2, *classRooms[1]));
		courses.push_back(new Course("CPP", 3, Date(2017,10,18), Date(2017,1,17), lecturer3, tutor3, *classRooms[2]));
		courses.push_back(new Course("JAVA", 4, Date(2017,10,18), Date(2017,1,17), lecturer4, tutor4, *classRooms[3]));


	    electricity.addCourse(*courses[0]);
        electricity.addCourse(*courses[1]);
        software.addCourse(*courses[2]);
        software.addCourse(*courses[3]);

        cleaner->addClassRoom(*classRooms[0]);
        cleaner->addClassRoom(*classRooms[2]);


        cout<<afeka;
		cout<< endl << "---------State Design Pattern Example-----------\n\n";
		lecturer1->employee();
		lecturer1->unemployee();
		cout <<endl;

	}
	catch (const string& e)
	{
		cout<<e;
	}

	return 0;
}
