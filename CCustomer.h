#pragma once
#include "stdafx.h"

class CCustomer {
public:
	char last_name[256];
	char first_name[256];
	char middle_name[256];
	size_t passport;
	char city[256];
	char street[256];
	size_t home;
	size_t apartment;
	size_t id;

	CCustomer();
	CCustomer(const char* last_name, const char* first_name, const char* middle_name, const size_t& passport, const char* city,
		      const char* street, const size_t& home, const size_t& apartment, const size_t& id);
	CCustomer(const CCustomer& another);

	bool operator<(const CCustomer& another) const;
	bool operator>(const CCustomer& another) const;
	bool operator==(const CCustomer& another) const;

	CCustomer& operator=(const CCustomer& another);
	friend istream& operator>>(istream& in, CCustomer& another);
	friend ostream& operator<<(ostream& out, const CCustomer& another);
};