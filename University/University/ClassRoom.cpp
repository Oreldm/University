#include "ClassRoom.h"

int ClassRoom::idGenerator = 0;

ClassRoom::ClassRoom(int numOfChairs, bool isLaboratory, bool hasProjector)
{
	setId();
	setNumOfChairs(numOfChairs);
	setLaboratory(isLaboratory);
	setProjector(hasProjector);
}

inline int ClassRoom::getId() const { return id; }
inline int ClassRoom::getNumOfChairs() const { return numOfChairs; }
inline bool ClassRoom::getIsLaboratory() const { return isLaboratory; }
inline bool ClassRoom::getHasProjector() const { return hasProjector; }

void ClassRoom::setId()
{
	id=++idGenerator;
}

void ClassRoom::setNumOfChairs(int numOfChairs)
{
	if (numOfChairs < 0)
		throw "number of chairs cannot be negative!";
	this->numOfChairs=numOfChairs;
}
void ClassRoom::setLaboratory(bool isLabaratory)
{
	this->isLaboratory=isLabaratory;
}
void ClassRoom::setProjector(bool hasProjector)
{
	this->hasProjector=hasProjector;
}

ostream& operator<<(ostream& os, const ClassRoom& classRoom)
{
	os << "ClassRoom #" << classRoom.getId() << ": Has " << classRoom.getNumOfChairs() << " Chairs, "
		<< (classRoom.getHasProjector() == true ? "\t Has" : "Hasn't") << " Projector and " << (classRoom.getIsLaboratory() == true ? "is" : "isn't")<< " Labaratory";
	return os;
}

bool ClassRoom::operator==(int other) const
{
	if (this->getId()==other)
		return true;
	return false;
}

bool ClassRoom::operator==(const ClassRoom& other) const
{
	return *this==(other.getId());
}

ClassRoom::ClassRoom(const ClassRoom& other)
{
	if (this != &other)
	{
		this->id=other.getId();
		this->setProjector(other.getHasProjector());
		this->setLaboratory(other.getIsLaboratory());
		this->setNumOfChairs(other.getNumOfChairs());
	}
}