#include "Address.h"

Address::Address(string city, string street, int houseNumber) : city(city), street(street)
{
	setHouseNumber(houseNumber);
}
Address::Address(const Address& other) :  city(other.city), street(other.street)
{
	setHouseNumber(other.houseNumber);
}

void Address::setStreet(const string& street)
{
	if (street.length() == 0)
		throw "cannot set empty street!";
	
	this->street= street;
}

void Address::setCity(const string& city)
{
	if (city.length() == 0)
		throw "cannot set empty city!";
	this->city= city;
}
void Address::setHouseNumber(int houseNumber)
{
	if (houseNumber<0)
		throw "house number cannot be nagative!";
	this->houseNumber=houseNumber;
}

inline const string Address::getCity() const
{
	return city;
}

inline const string Address::getStreet() const
{
	return street;
}

inline int Address::getHouseNumber() const
{
	return houseNumber;
}


const Address& Address::operator=(const Address& address)
{
	if (this != &address)
	{
		this->city = address.getCity();
		this->street = address.getStreet();
		this->houseNumber=address.getHouseNumber();
	}
	return *this;
}

ostream& operator<<(ostream& os, const Address& address)
{
	os << "The address is: City: " << address.getCity() << ", Street: " << address.getStreet() << ", House number: " << address.getHouseNumber() <<endl;
	return os;
}