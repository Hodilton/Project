#include "CDate.h"

CDate::CDate() : day(0), month(0), year(0) {}

CDate::CDate(const size_t& day, const size_t& month, const size_t& year) : day(day), month(month), year(year) {}

CDate::CDate(const CDate& another) : day(another.day), month(another.month), year(another.year) {}

CDate& CDate::operator=(const CDate& another)
{
	this->day = another.day;
	this->month = another.month;
	this->year = another.year;
	return *this;
}

istream& operator>>(istream& in, CDate& another)
{
	ReadAfterColon(in, another.day);
	in.ignore();
	in >> another.month;
	in.ignore();
	in >> another.year;
	return in;
}

ostream& operator<<(ostream& out, const CDate& another)
{
	out << another.day << "." << another.month << "." << another.year;
	return out;
}