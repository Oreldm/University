#ifndef __PERSON_H
#define __PERSON_H

#include "Address.h"
#include "Date.h"
#include <iostream>
using namespace std;

class Person 
{
	int id;
	string name;
	Date* birthDate;	//changed to *
	Address* address;	//changed to *

public:
	Person(int id, string name, const Date& date, const Address& address);
	Person(const Person& other); 
	virtual ~Person();

	virtual int getId() const;
	const string getName() const;
	inline const Date& getBirthDate() const;
	inline const Address& getAddress() const;

	const Person& operator=(const Person& other);
	virtual void toOs(ostream& os) const;

	friend ostream& operator<<(ostream& os, const Person& person);
    static int generateRandomId();


	void setId(int id); //added by me
	void setName(const string& name); //added by me
	void setBirthDate(const Date& date); //added by me
	void setAddress(const Address& address); //added by me

};

#endif