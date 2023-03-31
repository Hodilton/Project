#pragma once
#include"stdafx.h"

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