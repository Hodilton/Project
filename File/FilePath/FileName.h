#pragma once
#include "stdafx.h"
#include "FilePath.h"

class FileName {
public:
    static const string fund_txt;
    static const string customer_txt;
    static const string fund_bin;
    static const string customer_bin;

    static const string fund_source;
    static const string customer_source;
};

const string FileName::fund_txt = FilePath::base_directory + FilePath::data_directory + FundFilePath::txt;
const string FileName::customer_txt = FilePath::base_directory + FilePath::data_directory + CustomerFilePath::txt;

const string FileName::fund_bin = FilePath::base_directory + FilePath::data_directory + FundFilePath::bin;
const string FileName::customer_bin = FilePath::base_directory + FilePath::data_directory + CustomerFilePath::bin;

const string FileName::fund_source = FilePath::base_directory + FilePath::data_directory + FundFilePath::source;
const string FileName::customer_source = FilePath::base_directory + FilePath::data_directory + CustomerFilePath::source;