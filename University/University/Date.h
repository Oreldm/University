#ifndef __DATE_H
#define __DATE_H

#include <iostream>
using namespace std;


class Date
{
protected:
	int year;
	int month;
	int day;

	Date();	//added by me now!!

public:
	//Date(int year = 0, int month = 0, int day = 0); //there is no meaning
	Date(int year, int month, int day);

	inline int getYear() const;
	inline int getMonth() const;
	inline int getDay() const;

	inline bool setYear(int year) throw (const char*);
	inline bool setMonth(int month) throw (const char*);
	inline bool setDay(int day) throw (const char*);

	friend ostream& operator<<(ostream& os, const Date& date);
};

#endif