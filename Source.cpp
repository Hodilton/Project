#include "stdafx.h"
#include "CConsole.h"
#include "CTree.h"
#include "CFund.h"
#include "CFstream.h"
#include "CFile.h"

int main() {
    const File files;
	CTree<CFund> tree_fund;

	if (!CFstream<CFund>::Read(tree_fund, files.fund_txt)) return 0;
	//tree_fund.Print(cout);

    CBinaryFileIO<CFund> fund_file_bin("fund_test_bin");
    fund_file_bin.Write(tree_fund);

    CTree<CFund> tree_fund1;
    fund_file_bin.Read(tree_fund1);
    tree_fund1.Print(cout);

	return 0;
}