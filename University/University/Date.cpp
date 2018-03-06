#include "Date.h"

Date::Date(int year, int month, int day)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

inline int Date::getYear() const { return year; }
inline int Date::getMonth() const { return month; }
inline int Date::getDay() const { return day; }

inline bool Date::setYear(int year) 
{
	if (year < 1900)
		throw "cant set the year";
	this->year=year;
}

inline bool Date::setMonth(int month) 
{
	if ((month < 1) || (month > 12))
		throw "cant set the month";
	this->month=month;
}

inline bool Date::setDay(int day)
{
	if ((day < 1) || (day > 31))
		throw "cant set the day";
	this->day=day;
}

ostream& operator<<(ostream& os, const Date& date)
{
	os << date.getDay() << "\\" << date.getMonth() << "\\" << date.getYear();
	return os;
}