#include "CFund.h"

CFund::CFund() : id(0), passport_1(0), passport_2(0), passport_3(0), depart(), arrival() {}

CFund::CFund(const size_t& id, const size_t& passport_1, const size_t& passport_2, const size_t& passport_3, const CDate& arrival, const CDate& depart)
	: id(id), passport_1(passport_1), passport_2(passport_2), passport_3(passport_3), depart(depart), arrival(arrival) {}

CFund::CFund(const CFund& another) 
	: id(another.id), passport_1(another.passport_1), passport_2(another.passport_2), passport_3(another.passport_3), depart(another.depart), arrival(another.arrival) {}

bool CFund::operator<(const CFund& another) const
{
	return this->id < another.id;
}

bool CFund::operator>(const CFund& another) const
{
	return this->id > another.id;
}

bool CFund::operator==(const CFund& another) const
{
	return this->id == another.id;
}

CFund& CFund::operator=(const CFund& another)
{
	this->id = another.id;
	this->passport_1 = another.passport_1;
	this->passport_2 = another.passport_2;
	this->passport_3 = another.passport_3;
	this->arrival = another.arrival;
	this->depart = another.depart;
	return *this;
}

istream& operator>>(istream& in, CFund& another)
{
	ReadAfterColon(in, another.id);
	in >> another.arrival;
	in >> another.depart;
	ReadAfterColon(in, another.passport_1);
	ReadAfterColon(in, another.passport_2);
	ReadAfterColon(in, another.passport_3);
	return in;
}

ostream& operator<<(ostream& out, const CFund& another)
{
	out << "ID: " << another.id << endl;
	out << "Arrival: " << another.arrival << endl;
	out << "Depart: " << another.depart << endl;
	out << "Passport_1: " << another.passport_1 << endl;
	out << "Passport_2: " << another.passport_2 << endl;
	out << "Passport_3: " << another.passport_3;
	return out;
}