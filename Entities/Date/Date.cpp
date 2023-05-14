#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(const size_t& day, const size_t& month, const size_t& year) : day(day), month(month), year(year) {}

Date::Date(const Date& another) : day(another.day), month(another.month), year(another.year) {}

void Date::ReadToConsole(vector<string>& text)
{
	while (true) {
		Console<int>::ReadNumber(text, cin, 1, 31);
		this->day = stoi(text[text.size() - 1]);
		text.push_back(".");

		Console<int>::ReadNumber(text, cin, 1, 31);
		this->month = stoi(text[text.size() - 1]);
		text.push_back(".");

		Console<int>::ReadNumber(text, cin, 1);
		this->year = stoi(text[text.size() - 1]);

		// Проверка корректности

		break;
	}
}

Date& Date::operator=(const Date& another)
{
	this->day = another.day;
	this->month = another.month;
	this->year = another.year;
	return *this;
}

istream& operator>>(istream& in, Date& another)
{
	ReadAfterColon(in, another.day);
	in.ignore();
	in >> another.month;
	in.ignore();
	in >> another.year;
	return in;
}

ostream& operator<<(ostream& out, const Date& another)
{
	out << another.day << "." << another.month << "." << another.year;
	return out;
}