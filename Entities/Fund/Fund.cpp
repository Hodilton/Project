#include "Fund.h"

Fund::Fund() : id(0), passport_1(0), passport_2(0), passport_3(0), depart(), arrival(), price(0), cost(0) {}

Fund::Fund(const size_t& id, const size_t& passport_1, const size_t& passport_2, const size_t& passport_3, const Date& arrival, const Date& depart, const size_t& price, const size_t& cost)
	: id(id), passport_1(passport_1), passport_2(passport_2), passport_3(passport_3), depart(depart), arrival(arrival), price(price), cost(cost) {}

Fund::Fund(const Fund& another) 
	: id(another.id), passport_1(another.passport_1), passport_2(another.passport_2), passport_3(another.passport_3), depart(another.depart), arrival(another.arrival), price(another.price), cost(another.cost) {}

void Fund::UpdatePassports(vector<int>& passports)
{
	this->passport_1 = passports[0];
	this->passport_2 = passports.size() > 1 ? passports[1] : 0;
	this->passport_3 = passports.size() > 2 ? passports[2] : 0;
}

void Fund::UpdateCost()
{
	int arrival_seconds = Date::GetSeconds(this->arrival);
	int depart_seconds = Date::GetSeconds(this->depart);

	int duration_seconds = depart_seconds - arrival_seconds;
	int nights = duration_seconds / (24 * 60 * 60);

	int total_price = nights * this->price;
	this->cost = total_price;
}

void Fund::ReadToConsole(vector<string>& text, bool cin_ignore)
{
	text.push_back("Arrival date: ");
	this->arrival.ReadToConsole(text);
	text.push_back("\n");

	text.push_back("Depart date: ");
	this->depart.ReadToConsole(text);
	text.push_back("\n");
}

bool Fund::operator<(const Fund& another) const
{
	return this->id < another.id;
}

bool Fund::operator>(const Fund& another) const
{
	return this->id > another.id;
}

bool Fund::operator==(const Fund& another) const
{
	return this->id == another.id;
}

Fund& Fund::operator=(const Fund& another)
{
	this->id = another.id;
	this->passport_1 = another.passport_1;
	this->passport_2 = another.passport_2;
	this->passport_3 = another.passport_3;
	this->arrival = another.arrival;
	this->depart = another.depart;
	this->price = another.price;
	this->cost = another.cost;
	return *this;
}

istream& operator>>(istream& in, Fund& another)
{
	ReadAfterColon(in, another.id);
	in >> another.arrival;
	in >> another.depart;
	ReadAfterColon(in, another.price);
	ReadAfterColon(in, another.cost);
	ReadAfterColon(in, another.passport_1);
	ReadAfterColon(in, another.passport_2);
	ReadAfterColon(in, another.passport_3);
	return in;
}

ostream& operator<<(ostream& out, const Fund& another)
{
	/*out << "ID: " << another.id << endl;
	out << "Arrival: " << another.arrival << endl;
	out << "Depart: " << another.depart << endl;
	out << "Passport_1: " << another.passport_1 << endl;
	out << "Passport_2: " << another.passport_2 << endl;
	out << "Passport_3: " << another.passport_3;*/

	out << setw(14) << left << another.id;
	if (another.id <= 2000)
	{
		out << "|" << setw(15) << left << another.passport_1;
		out << "|" << setw(15) << "Нет";
		out << "|" << setw(15) << "Нет";
	} else
	if (another.id <= 3000)
	{
	cout << "|" << setw(15) << left << another.passport_1;
		out << "|" << setw(15) << left << another.passport_2;
		out << "|" << setw(15) << "Нет";
	} else 
	if (another.id <= 4000)
	{
		out << "|" << setw(15) << left << another.passport_1;
		out << "|" << setw(15) << left << another.passport_2;
		out << "|" << setw(15) << left << another.passport_3;
	}

	out << "|" << setw(5) << left << another.arrival.day;
	out << "|" << setw(8) << left << another.arrival.month;
	out << "|" << setw(15) << left << another.arrival.year;
	out << "|" << setw(5) << left << another.depart.day;
	out << "|" << setw(8) << left << another.depart.month;
	out << "|" << setw(15) << left << another.depart.year;

	out << "|" << setw(8) << left << another.price;
	out << "|" << setw(8) << left << another.cost;

	cout << endl;
	for (int i = 0; i < 156; i++) {
		cout << '-';
	} cout << endl;

	return out;
}