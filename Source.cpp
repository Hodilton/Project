#include "stdafx.h"
#include "CFstream.h"
#include "CConsole.h"
#include "CTree.h"
#include "CFund.h"

int main() {
	CTree<CFund> tree_fund;

	if (!CFstream<CFund>::Read(tree_fund, "Fund.txt")) return 0;
	tree_fund.Print(cout);

	return 0;
}