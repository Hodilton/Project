#pragma once
#include "Fund.h"
#include "Customer.h"
#include "FileName.h"
#include "FileIO.h"
#include "FileIOBinary.h"

class File {
public:
    static const FileIO<Fund> fund_txt;
    static const FileIO<Customer> customer_txt;
    static const FileIOBinary<Fund> fund_bin;
    static const FileIOBinary<Customer> customer_bin;

    static const FileIO<Fund> fund_source;
    static const FileIO<Customer> customer_source;
};

const FileIO<Fund> File::fund_txt(FileName::fund_txt);
const FileIO<Customer> File::customer_txt(FileName::customer_txt);

const FileIOBinary<Fund> File::fund_bin(FileName::fund_bin);
const FileIOBinary<Customer> File::customer_bin(FileName::customer_bin);

const FileIO<Fund> File::fund_source(FileName::fund_source);
const FileIO<Customer> File::customer_source(FileName::customer_source);