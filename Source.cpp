#include "stdafx.h"
#include "Fund.h"
#include "Customer.h"
#include "Tree.h"
#include "File.h"

Tree<Fund> tree_fund;
Tree<Customer> tree_customer;
#include "MainMenu.h"

string Compare::_current_state = "lfm";
string Compare::_temp_state = "lfm";

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	File::customer_bin.Read(tree_customer);
	File::fund_bin.Read(tree_fund);

	const MainMenu main_menu;
	Menu::Display(main_menu);
	
	File::customer_txt.Write(tree_customer);
	File::fund_txt.Write(tree_fund);

	return 0;
}