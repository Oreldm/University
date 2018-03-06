#ifndef __CLEANER_H
#define __CLEANER_H


#include "Worker.h"
#include "ClassRoom.h"
using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

class Cleaner : public Worker
{

public:

	Cleaner(const Worker& worker);	//added const to Worker&

	bool addClassRoom(const ClassRoom &classRoom);
	bool removeClassRoom(int classRoomId);
	vector<ClassRoom> getClassRooms();
	
	Cleaner(const Cleaner& other); //changed from delete
	const int Cleaner::getNumOfClassRooms() const; //added by me

private:
	static const int MAX_CLASS_ROOM = 20;
	vector<ClassRoom> classRooms;

	const Cleaner& operator=(const Cleaner& other); //changed from delete
	virtual void toOs(ostream& os) const;

};

#endif