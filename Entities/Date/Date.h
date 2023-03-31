#pragma once
#include "stdafx.h"

class Date {
public:
	size_t day;
	size_t month;
	size_t year;

	Date();
	Date(const size_t& day, const size_t& month, const size_t& year);
	Date(const Date& another);

	Date& operator=(const Date& another);
	friend istream& operator>>(istream& in, Date& another);
	friend ostream& operator<<(ostream& out, const Date& another);
};