#pragma once
#include "stdafx.h"

class OutputTable {
public:
	static void DisplayCustomer() {
		DisplayCustomerTitle();
		tree_customer.Print(cout);
	}

	static void DisplayFund() {
		DisplayFundTitle();
		tree_fund.Print(cout);
	}

	static void DisplayFreeFund() {
		DisplayFundTitle();
		DisplayFundHelper(tree_fund.GetRoot(), false);
	}

	static void DisplayBusyFund() {
		DisplayFundTitle();
		DisplayFundHelper(tree_fund.GetRoot(), true);
	}

private:
	static void DisplayFundTitle() {
		PrintLine(156);
		cout << setw(14) << left << "Идентификатор";
		cout << "|" << setw(15) << left << "Пасспорт 1";
		cout << "|" << setw(15) << left << "Пасспорт 2";
		cout << "|" << setw(15) << left << "Пасспорт 3";
		cout << "|" << setw(30) << left << "Дата заезда";
		cout << "|" << setw(30) << left << "Дата выезда";
		cout << "|" << setw(8) << left << "Прайс";
		cout << "|" << setw(8) << left << "Стоимость";
		PrintLine(156);

		cout << setw(15) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|";

		cout << setw(5) << left << "День" << "|" << setw(8) << left << "Месяц" << "|" << setw(15) << left << "Год" << "|";
		cout << setw(5) << left << "День" << "|" << setw(8) << left << "Месяц" << "|" << setw(15) << left << "Год";

		PrintLine(156);
	}

	static void DisplayCustomerTitle() {
		PrintLine(168);
		cout << "|" << setw(25) << left << "Фамилия";
		cout << "|" << setw(20) << left << "Имя";
		cout << "|" << setw(25) << left << "Отчество";
		cout << "|" << setw(10) << left << "Пасспорт";
		cout << "|" << setw(30) << left << "Город";
		cout << "|" << setw(25) << left << "Улица";
		cout << "|" << setw(3) << left << "Дом";
		cout << "|" << setw(8) << left << "Квартира";
		cout << "|" << setw(12) << left << "ID";
		PrintLine(168);
	}

	static void DisplayFundHelper(const Node<Fund>* root, bool is_busy) {
		if (root) {
			DisplayFundHelper(root->left, is_busy);

			if (is_busy) {
				if (root->data.passport_1 != 0) {
					cout << root->data << endl << endl;
				}
			}
			else {
				if (root->data.passport_1 == 0) {
					cout << root->data << endl << endl;
				}
			}
			
			DisplayFundHelper(root->right, is_busy);
		}
	}

	static void PrintLine(int value) {
		cout << endl;

		for (int i = 0; i < value; i++) {
			cout << '-';
		} cout << endl;	
	}
};