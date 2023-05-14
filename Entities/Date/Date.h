#pragma once
#include "stdafx.h"
#include "Console.h"
#include "BaseEntities.h"

class Date : BaseEntities {
public:
	size_t day;
	size_t month;
	size_t year;

	Date();
	Date(const size_t& day, const size_t& month, const size_t& year);
	Date(const Date& another);

	static int GetSeconds(Date& date);

	void ReadToConsole(vector<string>& text, bool cin_ignore = false) override;
	void ReadForSearch() override { };

	Date& operator=(const Date& another);
	friend istream& operator>>(istream& in, Date& another);
	friend ostream& operator<<(ostream& out, const Date& another);
};