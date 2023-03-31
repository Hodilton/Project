#pragma once
#include"stdafx.h"
#include"FilePath.h"

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
