#include "stdafx.h"
//#include "CConsole.h"
#include "CTree.h"
#include "CFund.h"
#include "CCustomer.h"

#include "CFile.h"

#include"CMenuItem.h"

int main() {
	CTree<CFund> tree_fund;
	CTree<CCustomer> tree_customer;

	CFile::customer_txt.Read(tree_customer);
	CFile::customer_bin.Write(tree_customer);
	tree_customer.~CTree();

	CFile::customer_bin.Read(tree_customer);
	tree_customer.Print(cout);

	CFile::fund_bin.Read(tree_fund);
	tree_fund.Print(cout);

    /*CMenuItems menu_items;
    CMenu::Display(menu_items.main);*/

	return 0;
}