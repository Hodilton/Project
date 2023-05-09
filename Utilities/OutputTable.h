#pragma once
#include "stdafx.h"

class OutputTable {
public:
	static void Customer() {
		PrintLine(156);
		cout << "|" << setw(25) << left << "Фамилия";
		cout << "|" << setw(20) << left << "Имя";
		cout << "|" << setw(25) << left << "Отчество";
		cout << "|" << setw(10) << left << "Пасспорт";
		cout << "|" << setw(30) << left << "Город";
		cout << "|" << setw(25) << left << "Улица";
		cout << "|" << setw(3) << left << "Дом";
		cout << "|" << setw(8) << left << "Квартира";
		PrintLine(156);
		
		tree_customer.Print(cout);
	}

	static void Fund() {
		PrintLine(156);
		cout << setw(14) << left << "Идентификатор";
		cout << "|" << setw(15) << left << "Пасспорт 1";
		cout << "|" << setw(15) << left << "Пасспорт 2";
		cout << "|" << setw(15) << left << "Пасспорт 3";
		cout << "|" << setw(30) << left << "Дата заезда";
		cout << "|" << setw(30) << left << "Дата выезда";
		PrintLine(156);

		cout << setw(15) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|";

		cout << setw(5) << left << "День" << "|" << setw(8) << left << "Месяц" << "|" << setw(15) << left << "Год" << "|";
		cout << setw(5) << left << "День" << "|" << setw(8) << left << "Месяц" << "|" << setw(15) << left << "Год";

		PrintLine(156);

		tree_fund.Print(cout);
	}

private:
	static void PrintLine(int value) {
		cout << endl;

		for (int i = 0; i < value; i++) {
			cout << '-';
		} cout << endl;	
	}
};