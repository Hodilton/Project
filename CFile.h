#pragma once
#include "stdafx.h"
#include "CBinaryFileIO.h"

struct File{
    string fund_txt = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/")) + "/Data/" + "Fund" + ".txt";
    string fund_bin = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/")) + "/Data/" + "Fund" + ".bin";
};

//class CFileInfo {
//public:
//    string file_path;
//    CBinaryFileIO<CFund> binary_file;
//
//    CFileInfo(const string& path) : file_path(path), binary_file(path) {}
//};
//
//class CFile {
//public:
//    map <string, CFileInfo> files;
//
//    CFile() {
//        AddFileTxt("Fund");
//    }
//
//    CFile& operator[](const string& filename) {
//        //return files[filename];
//    }
//
//private:
//
//    void AddFileBin(const string& file_name) {
//        string file_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/")) + "/Data/"+ file_name + ".bin";
//        files[file_name] = CFileInfo(file_path);
//    }
//
//    void AddFileTxt(const string& file_name) {
//        string file_path = string(__FILE__).substr(0, string(__FILE__).find_last_of("\\/")) + "/Data/" + file_name + ".txt";
//        files[file_name] = CFileInfo(file_path);
//    }
//};