#include "Date.h"

Date::Date() : day(0), month(0), year(0) {}

Date::Date(const size_t& day, const size_t& month, const size_t& year) : day(day), month(month), year(year) {}

Date::Date(const Date& another) : day(another.day), month(another.month), year(another.year) {}

int Date::GetSeconds(Date& date)
{
	int year = date.year;
	int month = date.month;
	int day = date.day;

	int y = year - (month < 3 ? 1 : 0);
	int m = month + 9;
	int d = day;

	int c = y / 100;
	int ya = y - 100 * c;

	int julian_day = (146097 * c) / 4 + (1461 * ya) / 4 + (153 * m + 2) / 5 + d + 1721119 - 2400001;
	int seconds = julian_day * 24 * 60 * 60;

	return seconds;
}

void Date::ReadToConsole(vector<string>& text, bool cin_ignore)
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