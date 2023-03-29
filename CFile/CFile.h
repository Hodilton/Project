#pragma once
#include "stdafx.h"
#include "CFileIO.h"
#include "CBinaryFileIO.h"

class ÑFilePath {
public:
    static const string data_directory;
    static const string base_directory;
};

const string ÑFilePath::data_directory = "/Data/";
const string ÑFilePath::base_directory = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/"));

class ÑFundFilePath {
public:
    static const string txt;
    static const string bin;
    static const string source;
};

const string ÑFundFilePath::txt = "Fund.txt";
const string ÑFundFilePath::bin = "Fund.bin";
const string ÑFundFilePath::source = "Fund_Source.txt";

class ÑCustomerFilePath {
public:
    static const string txt;
    static const string bin;
    static const string source;
};

const string ÑCustomerFilePath::txt = "Customer.txt";
const string ÑCustomerFilePath::bin = "Customer.bin";
const string ÑCustomerFilePath::source = "Customer_Source.txt";

class ÑFileName {
public:
    static const string fund_txt;
    static const string customer_txt;
    static const string fund_bin;
    static const string customer_bin;

    static const string fund_source;
    static const string customer_source;
};

const string ÑFileName::fund_txt = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑFundFilePath::txt;
const string ÑFileName::customer_txt = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑCustomerFilePath::txt;

const string ÑFileName::fund_bin = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑFundFilePath::bin;
const string ÑFileName::customer_bin = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑCustomerFilePath::bin;

const string ÑFileName::fund_source = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑFundFilePath::source;
const string ÑFileName::customer_source = ÑFilePath::base_directory + ÑFilePath::data_directory + ÑCustomerFilePath::source;

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