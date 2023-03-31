#pragma once
#include "stdafx.h"
#include"FileName.h"
//#include"CFund.h"
//#include"CCustomer.h"
#include "CFileIO.h"
#include "CBinaryFileIO.h"

class CFile {
public:
    static const CFileIO<CFund> fund_txt;
    static const CFileIO<CCustomer> customer_txt;
    static const CBinaryFileIO<CFund> fund_bin;
    static const CBinaryFileIO<CCustomer> customer_bin;

    static const CFileIO<CFund> fund_source;
    static const CFileIO<CCustomer> customer_source;
};

const CFileIO<CFund> CFile::fund_txt(ÑFileName::fund_txt);
const CFileIO<CCustomer> CFile::customer_txt(ÑFileName::customer_txt);

const CBinaryFileIO<CFund> CFile::fund_bin(ÑFileName::fund_bin);
const CBinaryFileIO<CCustomer> CFile::customer_bin(ÑFileName::customer_bin);

const CFileIO<CFund> CFile::fund_source(ÑFileName::fund_source);
const CFileIO<CCustomer> CFile::customer_source(ÑFileName::customer_source);