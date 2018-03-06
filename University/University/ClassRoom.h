#ifndef __CLASS_ROOM_H
#define __CLASS_ROOM_H

#include <iostream>
#include <string>
using namespace std;

class ClassRoom 
{
private:
	static int idGenerator;
	int id;
	int numOfChairs;
	bool isLaboratory;
	bool hasProjector;

	void setId(); //added by me


public:
	ClassRoom(const ClassRoom& other);
	ClassRoom(int numOfChairs = 0, bool isLaboratory = false, bool hasProjector = false);

	inline int getId() const;
	inline int getNumOfChairs() const;
	inline bool getIsLaboratory() const;
	inline bool getHasProjector() const;

	friend ostream& operator<<(ostream& os, const ClassRoom& classRoom);
	bool operator==(int other) const;
	bool operator==(const ClassRoom& other) const;

	void setNumOfChairs(int numOfChairs) throw (const string); //added by me
	void setLaboratory(bool isLabaratory); //added by me
	void setProjector(bool hasProjector); //added by me
};


#endif