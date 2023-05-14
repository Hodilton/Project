#pragma once
#include "stdafx.h"
#include "Date.h"
#include "Console.h"
#include "BaseEntities.h"

class Fund : BaseEntities {
public:
	size_t id;
	size_t passport_1;
	size_t passport_2;
	size_t passport_3;

	Date arrival;
	Date depart;
	
	Fund();
	Fund(const size_t& id, const size_t& passport_1, const size_t& passport_2, const size_t& passport_3, const Date& arrival, const Date& depart);
	Fund(const Fund& another);

	void ReadToConsole(vector<string>& text) override;
	void ReadForSearch() override { } ;

	bool operator<(const Fund& another) const;
	bool operator>(const Fund& another) const;
	bool operator==(const Fund& another) const;

	Fund& operator=(const Fund& another);
	friend istream& operator>>(istream& in, Fund& another);
	friend ostream& operator<<(ostream& out, const Fund& another);
};