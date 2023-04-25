#include "Customer.h"

Customer::Customer() : last_name(""), first_name(""), middle_name(""), passport(0), city(""), street(""), home(0), apartment(0), id(0) {
	memset(last_name, 0, sizeof(last_name));
	memset(first_name, 0, sizeof(first_name));
	memset(middle_name, 0, sizeof(middle_name));
	memset(city, 0, sizeof(city));
	memset(street, 0, sizeof(street));
}

Customer::Customer(const char* last_name, const char* first_name, const char* middle_name, const size_t& passport,
	const char* city, const char* street, const size_t& home, const size_t& apartment, const size_t& id)
	: passport(passport), home(home), apartment(apartment), id(id)
{
	strncpy_s(this->last_name, last_name, sizeof(this->last_name));
	strncpy_s(this->first_name, first_name, sizeof(this->first_name));
	strncpy_s(this->middle_name, middle_name, sizeof(this->middle_name));
	strncpy_s(this->city, city, sizeof(this->city));
	strncpy_s(this->street, street, sizeof(this->street));
}

Customer::Customer(const Customer& another)
	: passport(another.passport), home(another.home), apartment(another.apartment), id(another.id)
{
	strncpy_s(this->last_name, another.last_name, sizeof(this->last_name));
	strncpy_s(this->first_name, another.first_name, sizeof(this->first_name));
	strncpy_s(this->middle_name, another.middle_name, sizeof(this->middle_name));
	strncpy_s(this->city, another.city, sizeof(this->city));
	strncpy_s(this->street, another.street, sizeof(this->street));
}

void Customer::ReadToConsole()
{
    cout << endl;
    cout << "Last Name: ";
    cin >> this->last_name;
    cout << "First Name: ";
    cin >> this->first_name;
    cout << "Middle Name: ";
    cin >> this->middle_name;
    cout << "Passport: ";
    cin >> this->passport;

    /*cout << "City: ";
    cin >> this->city;
    cout << "Street: ";
    cin >> this->street;
    cout << "Home: ";
    cin >> this->home;
    cout << "Apartment: ";
    cin >> this->apartment;
    cout << "ID: ";
    cin >> this->id;*/

}

bool Customer::operator<(const Customer& another) const
{
    int result = strcmp(this->last_name, another.last_name);
    if (result < 0) {
        return true;
    }
    else if (result == 0) {
        result = strcmp(this->first_name, another.first_name);
        if (result < 0) {
            return true;
        }
        else if (result == 0) {
            return strcmp(this->middle_name, another.middle_name) < 0;
        }
    }
    return false;
}

bool Customer::operator>(const Customer& another) const
{
    int result = strcmp(this->last_name, another.last_name);
    if (result > 0) {
        return true;
    }
    else if (result == 0) {
        result = strcmp(this->first_name, another.first_name);
        if (result > 0) {
            return true;
        }
        else if (result == 0) {
            return strcmp(this->middle_name, another.middle_name) > 0;
        }
    }
    return false;
}

bool Customer::operator==(const Customer& another) const
{
    const string state = Compare::GetState();
    if (state == "lfm") {
        return strcmp(this->last_name, another.last_name) == 0
            && strcmp(this->first_name, another.first_name) == 0
            && strcmp(this->middle_name, another.middle_name) == 0;
    }
    if (state == "lf") {
        return strcmp(this->last_name, another.last_name) == 0
            && strcmp(this->first_name, another.first_name) == 0;
    }
    if (state == "l") {
        return strcmp(this->last_name, another.last_name) == 0;
    }
    if (state == "f") {
        return strcmp(this->first_name, another.first_name) == 0;
    }
    if (state == "m") {
        return strcmp(this->middle_name, another.middle_name) == 0;
    }
    if (state == "p") {
        return this->passport == another.passport;
    }
}

Customer& Customer::operator=(const Customer& another)
{
    strcpy_s(this->last_name, another.last_name);
    strcpy_s(this->first_name, another.first_name);
    strcpy_s(this->middle_name, another.middle_name);
    this->passport = another.passport;
    strcpy_s(this->city, another.city);
    strcpy_s(this->street, another.street);
    this->home = another.home;
    this->apartment = another.apartment;
    this->id = another.id;
    return *this;
}

istream& operator>>(istream& in, Customer& another)
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

ostream& operator<<(ostream& out, const Customer& another)
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