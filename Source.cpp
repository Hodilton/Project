#include "stdafx.h"
#include "Tree.h"
#include "Fund.h"
#include "Customer.h"
#include "File.h"
#include"MenuItem.h"

int main() {
	Tree<Fund> tree_fund;
	Tree<Customer> tree_customer;

	File::customer_bin.Read(tree_customer);
	tree_customer.Print(cout);

	File::fund_bin.Read(tree_fund);
	tree_fund.Print(cout);

    MenuItems menu_items;
    Menu::Display(menu_items.main);

	return 0;
}