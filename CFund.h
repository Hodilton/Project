#pragma once
#include "stdafx.h"
#include "CDate.h"

class CFund {
public:
	size_t id;
	size_t passport_1;
	size_t passport_2;
	size_t passport_3;
	CDate arrival;
	CDate depart;
	
	CFund();
	CFund(const size_t& id, const size_t& passport_1, const size_t& passport_2, const size_t& passport_3, const CDate& arrival, const CDate& depart);
	CFund(const CFund& another);

	bool operator<(const CFund& another) const;
	bool operator>(const CFund& another) const;
	bool operator==(const CFund& another) const;

	CFund& operator=(const CFund& another);
	friend istream& operator>>(istream& in, CFund& another);
	friend ostream& operator<<(ostream& out, const CFund& another);
};