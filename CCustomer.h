#pragma once
#include "stdafx.h"

class CCompare {
public:
	CCompare() {
		current_state = 5;
	}

	unsigned short GetState() {
		return current_state;
	}

	void SwitchState(unsigned short state) {
		current_state = state;
	}

private:
	enum class StateCmp { First = 1, Last = 2, Middle = 4, Pass = 5 };
	unsigned short current_state;
};

class CCustomer {
public:
	string last_name;
	string first_name;
	string middle_name;
	size_t passport;
	string city;
	string street;
	size_t home;
	size_t apartment;
	size_t id;

	CCustomer();
	CCustomer(const string& last_name, const string& first_name, const string& middle_name, const size_t& passport, const string& city,
	          const string& street, const size_t& home, const size_t& apartment, const size_t& id);
	CCustomer(const CCustomer& another);

	bool operator<(const CCustomer& another) const;
	bool operator>(const CCustomer& another) const;
	bool operator==(const CCustomer& another) const;

	CCustomer& operator=(const CCustomer& another);
	friend istream& operator>>(istream& in, CCustomer& another);
	friend ostream& operator<<(ostream& out, const CCustomer& another);
};