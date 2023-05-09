#pragma once
#include "stdafx.h"
#include "Compare.h"
#include "Console.h"

class BaseEntities {
public:
	virtual void ReadToConsole() = 0;
	virtual void ReadForSearch() = 0;
};

class Customer : BaseEntities {
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

	Customer();
	Customer(const char* last_name, const char* first_name, const char* middle_name, const size_t& passport, const char* city,
		      const char* street, const size_t& home, const size_t& apartment, const size_t& id);
	Customer(const Customer& another);

	void ReadToConsole() override;
	void ReadForSearch() override;

	bool operator<(const Customer& another) const;
	bool operator>(const Customer& another) const;
	bool operator==(const Customer& another) const;

	Customer& operator=(const Customer& another);
	friend istream& operator>>(istream& in, Customer& another);
	friend ostream& operator<<(ostream& out, const Customer& another);
};