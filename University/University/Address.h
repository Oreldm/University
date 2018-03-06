#ifndef __ADDRESS_H
#define __ADDRESS_H

#include <iostream>
#include <string>
using namespace std;

class Address
{
private:
	string city;
	string street;
	int houseNumber;

public:
	Address(string city, string street, int houseNumber);
	Address(const Address& other);

	inline const string getCity() const;
	inline const string getStreet() const;
	inline int getHouseNumber() const;

	const Address& operator=(const Address& address);
	friend ostream& operator<<(ostream& os, const Address& address);

	void setCity(const string& city) throw (const string&); //added by me
	void setStreet(const string& street) throw (const string&); //added by me
	void setHouseNumber(int houseNumber) throw (const string&); //added by me

};

#endif