#pragma once
#include "stdafx.h"

class CDate {
public:
	size_t day;
	size_t month;
	size_t year;

	CDate();
	CDate(const size_t& day, const size_t& month, const size_t& year);
	CDate(const CDate& another);

	CDate& operator=(const CDate& another);
	friend istream& operator>>(istream& in, CDate& another);
	friend ostream& operator<<(ostream& out, const CDate& another);
};