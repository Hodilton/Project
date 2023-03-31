#pragma once
#include "stdafx.h"

class FilePath {
public:
    static const string data_directory;
    static const string base_directory;
};

const string FilePath::data_directory = "/Data/";
const string FilePath::base_directory = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/") - 1).substr(0, string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/") - 1).find_last_of("\\/") - 4);

class FundFilePath {
public:
    static const string txt;
    static const string bin;
    static const string source;
};

const string FundFilePath::txt = "Fund.txt";
const string FundFilePath::bin = "Fund.bin";
const string FundFilePath::source = "Fund_Source.txt";

class CustomerFilePath {
public:
    static const string txt;
    static const string bin;
    static const string source;
};

const string CustomerFilePath::txt = "Customer.txt";
const string CustomerFilePath::bin = "Customer.bin";
const string CustomerFilePath::source = "Customer_Source.txt";