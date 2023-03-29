#include "CCustomer.h"

CCustomer::CCustomer() : last_name(""), first_name(""), middle_name(""), passport(0), city(""), street(""), home(0), apartment(0), id(0) {}

CCustomer::CCustomer(const string& last_name, const string& first_name, const string& middle_name, const size_t& passport, 
	                 const string& city, const string& street, const size_t& home, const size_t& apartment, const size_t& id)
	: last_name(last_name), first_name(first_name), middle_name(middle_name), passport(passport), city(city), 
	  street(street), home(home), apartment(apartment), id(id) {}


CCustomer::CCustomer(const CCustomer& another)
	: last_name(another.last_name), first_name(another.first_name), middle_name(another.middle_name), passport(another.passport), 
	  city(another.city), street(another.street), home(another.home), apartment(another.apartment), id(another.id) {}

bool CCustomer::operator<(const CCustomer& another) const
{
	return this->last_name < another.last_name
		|| (this->last_name == another.last_name && this->first_name < another.first_name)
		|| (this->last_name == another.last_name && this->first_name == another.first_name && this->middle_name < another.middle_name);
}

bool CCustomer::operator>(const CCustomer& another) const
{
	return this->last_name > another.last_name
		|| (this->last_name == another.last_name && this->first_name > another.first_name)
		|| (this->last_name == another.last_name && this->first_name == another.first_name && this->middle_name > another.middle_name);
}

bool CCustomer::operator==(const CCustomer& another) const
{
	return this->last_name == another.last_name
		&& this->first_name == another.first_name
		&& this->middle_name == another.middle_name;
}

CCustomer& CCustomer::operator=(const CCustomer& another)
{

	this->last_name =  another.last_name;
	this->first_name = another.first_name;
	this->middle_name = another.middle_name;
	this->city = another.city;
	this->street = another.street;
	this->home = another.home;
	this->apartment = another.apartment;
	this->id = another.id;
	return *this;
}

istream& operator>>(istream& in, CCustomer& another)
{
	ReadAfterColon(in, another.last_name);
	ReadAfterColon(in, another.first_name);
	ReadAfterColon(in, another.middle_name);
	ReadAfterColon(in, another.passport);
	ReadAfterColon(in, another.city);
	ReadAfterColon(in, another.street);
	ReadAfterColon(in, another.home);
	ReadAfterColon(in, another.apartment);
	ReadAfterColon(in, another.id);
	return in;
}

ostream& operator<<(ostream& out, const CCustomer& another)
{
	out << "Last Name: " << another.last_name << endl;
	out << "First Name: " << another.first_name << endl;
	out << "Middle Name: " << another.middle_name << endl;
	out << "Passport: " << another.passport << endl;
	out << "City: " << another.city << endl;
	out << "Street: " << another.street << endl;
	out << "Home: " << another.home << endl;
	out << "Apartment: " << another.apartment << endl;
	out << "ID: " << another.id;
	return out;
}