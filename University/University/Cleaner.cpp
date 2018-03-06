#include "Cleaner.h"

Cleaner::Cleaner(const Worker& worker) : Worker(worker) , Person(worker)
{
}

bool Cleaner::addClassRoom(const ClassRoom& classRoom)
{
	
	if(find(classRooms.begin(), classRooms.end(), classRoom) != classRooms.end()) 
		{
			return false;
		} 
	this->classRooms.push_back(classRoom);
	return true;
}


bool Cleaner::removeClassRoom(int classRoomId)
{
		vector<ClassRoom>::iterator itr= classRooms.begin();
		vector<ClassRoom>::iterator itrEnd= classRooms.end();
		
		for(int pos=0;itr!=itrEnd;++itr, pos++ )
		{
			if((*itr).getId() == classRoomId)
			{
				classRooms.erase(classRooms.begin()+pos);
				return true;
			}
		}
		return false;
}


vector<ClassRoom> Cleaner::getClassRooms()
{
	return classRooms;
}

const int Cleaner::getNumOfClassRooms() const
{
	return classRooms.size();
}

void Cleaner::toOs(ostream& os) const
{	
	os << "\tis a CLEANER : " << " that cleans: " << this->getNumOfClassRooms()  << " classes: "<< endl;

	for(int i=0; i<classRooms.size();i++)
	{
		os << classRooms[i] << endl;
	}

}

