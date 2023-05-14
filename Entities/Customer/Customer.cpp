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

void Customer::ReadForSearch()
{
    const string search_state = Compare::GetState();
    vector<string> text;

    if (search_state == "lfm") { // фамилия, имя и отчество
        text.push_back("Last Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->last_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->last_name));

        text.push_back("First Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->first_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->first_name));

        text.push_back("Middle Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->middle_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->middle_name));
    }
    if (search_state == "lf") { // фамилия и имя
        text.push_back("Last Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->last_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->last_name));

        text.push_back("First Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->first_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->first_name));
    }
    if (search_state == "l") { // фамилия
        text.push_back("Last Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->last_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->last_name));
    }
    if (search_state == "f") { // имя
        text.push_back("First Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->first_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->first_name));
    }
    if (search_state == "m") { // отчество
        text.push_back("Middle Name: ");
        Console<string>::ReadString(text);
        strncpy_s(this->middle_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->middle_name));
    }
    if (search_state == "p") { // пасспорт
        text.push_back("Passport: ");
        Console<int>::ReadNumber(text, cin, 0, 10e+9);
        this->passport = stoi(text[text.size() - 2]);
    }
}

void Customer::ReadToConsole(vector<string>& text, bool cin_ignore)
{
    if(cin_ignore) cin.ignore();
    text.push_back("Last Name: "); 
    Console<string>::ReadString(text);
    strncpy_s(this->last_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->last_name));

    text.push_back("First Name: ");
    Console<string>::ReadString(text);
    strncpy_s(this->first_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->first_name));

    text.push_back("Middle Name: ");
    Console<string>::ReadString(text);
    strncpy_s(this->middle_name, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->middle_name));

    text.push_back("Passport: ");
    Console<int>::ReadNumber(text, cin, 1);
    text.push_back("\n");
    this->passport = stoi(text[text.size() - 2]);

    text.push_back("City: ");
    Console<string>::ReadString(text);
    strncpy_s(this->city, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->city));

    text.push_back("Street: ");
    Console<string>::ReadString(text);
    strncpy_s(this->street, const_cast<char*>(text[text.size() - 2].c_str()), sizeof(this->street));
   
    text.push_back("Home: ");
    Console<int>::ReadNumber(text, cin, 1);
    text.push_back("\n");
    this->home = stoi(text[text.size() - 2]);

    text.push_back("Apartment: ");
    Console<int>::ReadNumber(text, cin, 1);
    text.push_back("\n");
    this->apartment = stoi(text[text.size() - 2]);

    text.push_back("\n");
}

bool Customer::operator<(const Customer& another) const
{
    if (*this == another) {
        return false; // объекты равны
    }

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
    if (*this == another) {
        return false; // объекты равны
    }

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
    const string search_state = Compare::GetState();
    if (search_state == "lfm") { // фамилия, имя и отчество
        return strcmp(this->last_name, another.last_name) == 0
            && strcmp(this->first_name, another.first_name) == 0
            && strcmp(this->middle_name, another.middle_name) == 0;
    }
    if (search_state == "lf") { // фамилия и имя
        return strcmp(this->last_name, another.last_name) == 0
            && strcmp(this->first_name, another.first_name) == 0;
    }
    if (search_state == "l") { // фамилия
        return strcmp(this->last_name, another.last_name) == 0;
    }
    if (search_state == "f") { // имя
        return strcmp(this->first_name, another.first_name) == 0;
    }
    if (search_state == "m") { // отчество
        return strcmp(this->middle_name, another.middle_name) == 0;
    }
    if (search_state == "p") { // пасспорт
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
	/*out << "Last Name: " << another.last_name << endl;
	out << "First Name: " << another.first_name << endl;
	out << "Middle Name: " << another.middle_name << endl;
	out << "Passport: " << another.passport << endl;
	out << "City: " << another.city << endl;
	out << "Street: " << another.street << endl;
	out << "Home: " << another.home << endl;
	out << "Apartment: " << another.apartment << endl;
	out << "ID: " << another.id;*/

    out << "|" << setw(25) << left << another.last_name;
    out << "|" << setw(20) << left << another.first_name;
    out << "|" << setw(25) << left << another.middle_name;
    out << "|" << setw(10) << left << another.passport;
    out << "|" << setw(30) << left << another.city;
    out << "|" << setw(25) << left << another.street;
    out << "|" << setw(3) << left << another.home;
    if (another.apartment != 0) {
        out << "|" << setw(8) << left << another.apartment;
    }
    else {
        out << "|" << setw(8) << left << "Нет";
    }
    out << "|" << setw(12) << left << another.id;

    out << endl;
    for (int i = 0; i < 168; i++) {
        out << '-';
    } out << endl;

	return out;
}