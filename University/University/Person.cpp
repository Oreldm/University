#include "Person.h"
#include <string>

Person::Person(int id, string name, const Date& date, const Address& address)
{
    setId(id);
    this->name = name;
	this->birthDate = new Date(date);
	this->address = new Address(address);
}

Person::Person(const Person& other) : name("")
{
    //*this = other;
		setId(other.id);
		this->name = other.name;
		this->birthDate = new Date(other.getBirthDate());
		this->address = new Address(other.getAddress());
}

Person::~Person()
{
    delete birthDate;
    delete address;
}

int Person::getId() const { return id; }
inline const Date& Person::getBirthDate() const { return *birthDate; }
inline const Address& Person::getAddress() const { return *address; }
const string Person::getName() const { return this->name; }

void Person::setAddress(const Address& address) 
{ 
	delete this->address;
	this->address = new Address(address);
}
void Person::setId(int id){this->id = id; }
void Person::setName(const string& name)
{ 
	this->name=name;
}

void Person::setBirthDate(const Date& date)
{ 
	delete this->birthDate;
	this->birthDate=new Date(date);
}

const Person& Person::operator=(const Person& other)
{
	if (this!=&other)
	{
		setId(other.getId());
		setAddress(other.getAddress());
		setName(other.getName());
		setBirthDate(other.getBirthDate());
	}
	return *this;
}

	void Person::toOs(ostream& os) const{};

	ostream& operator<<(ostream& os, const Person& person)
	{
		os << "Name: " << person.getName() << ", Id: " << person.getId() << " Birth Date: " << person.getBirthDate() << "\n\tAddress: " << person.getAddress();
		person.toOs(os);
		return os;
	}
    static int generateRandomId();
