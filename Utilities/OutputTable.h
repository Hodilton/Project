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

	static void DisplayCustomerTitle() {
		PrintLine(168);
		cout << "|" << setw(25) << left << "�������";
		cout << "|" << setw(20) << left << "���";
		cout << "|" << setw(25) << left << "��������";
		cout << "|" << setw(10) << left << "��������";
		cout << "|" << setw(30) << left << "�����";
		cout << "|" << setw(25) << left << "�����";
		cout << "|" << setw(3) << left << "���";
		cout << "|" << setw(8) << left << "��������";
		cout << "|" << setw(12) << left << "ID";
		PrintLine(168);
	}

private:
	static void DisplayFundTitle() {
		PrintLine(156);
		cout << setw(14) << left << "�������������";
		cout << "|" << setw(15) << left << "������� 1";
		cout << "|" << setw(15) << left << "������� 2";
		cout << "|" << setw(15) << left << "������� 3";
		cout << "|" << setw(30) << left << "���� ������";
		cout << "|" << setw(30) << left << "���� ������";
		cout << "|" << setw(8) << left << "�����";
		cout << "|" << setw(8) << left << "���������";
		PrintLine(156);

		cout << setw(15) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|" << setw(16) << right << "|";

		cout << setw(5) << left << "����" << "|" << setw(8) << left << "�����" << "|" << setw(15) << left << "���" << "|";
		cout << setw(5) << left << "����" << "|" << setw(8) << left << "�����" << "|" << setw(15) << left << "���";

		PrintLine(156);
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