#pragma once
#include "stdafx.h"
#include <chrono>
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

	size_t price;
	size_t cost;
	
	Fund();
	Fund(const size_t& id, const size_t& passport_1, const size_t& passport_2, const size_t& passport_3, const Date& arrival, const Date& depart, const size_t& price, const size_t& cost);
	Fund(const Fund& another);

	void UpdatePassports(vector<int>& passports);
	void UpdateCost();

	void ReadToConsole(vector<string>& text, bool cin_ignore = false) override;
	void ReadForSearch() override { } ;

	bool operator<(const Fund& another) const;
	bool operator>(const Fund& another) const;
	bool operator==(const Fund& another) const;

	Fund& operator=(const Fund& another);
	friend istream& operator>>(istream& in, Fund& another);
	friend ostream& operator<<(ostream& out, const Fund& another);
};