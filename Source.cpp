#include "stdafx.h"
#include "Tree.h"
#include "Fund.h"
#include "Customer.h"
#include "File.h"
#include "MainMenu.h"

string Compare::_current_state = "lfm";

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Tree<Fund> tree_fund;
	Tree<Customer> tree_customer;

	//File::customer_source.Read(tree_customer);
	//File::customer_bin.Write(tree_customer);

	//File::customer_bin.Read(tree_customer);
	//tree_customer.Print(cout);

	//File::fund_bin.Read(tree_fund);
	//tree_fund.Print(cout);

	const MainMenu main_menu;
	Menu::Display(main_menu);

	/*Customer customer_search;
	customer_search.ReadToConsole();

	Tree<Customer> tree_search;
	Compare::SwitchState("f");
	tree_customer.SearchNode(tree_search, customer_search);
	tree_search.Print(cout);*/
	
	return 0;
}