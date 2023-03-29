#pragma once
#include "stdafx.h"
#include "CTree.h"

template<typename T>
class CFileIO {
public:
	CFileIO() : _file_name("") {};
	CFileIO(const string& filename) : _file_name(filename) {}

	bool Write(CTree<T>& tree) const {
		ofstream fout;
		fout.open(_file_name, ios::out);

		if (!IsFileOpen(fout, "write")) {
			fout.close();
			return false;
		}

		tree.Print(fout);

		fout.close();
		return 0;
	}

	bool Read(CTree<T>& tree) const {
		ifstream fin;
		fin.open(_file_name, ios::in);

		if (!IsFileOpen(fin, "read")) {
			fin.close();
			return false;
		}
		
		while (!fin.eof()) {
			T temp;
			fin >> temp;
			tree.AddNode(temp);
		}

		fin.close();
		return true;
	}

private:
	string _file_name;

	template<typename Stream>
	bool IsFileOpen(const Stream& stream /*const basic_fstream<char>& stream*/ /*const basic_ios<char>& stream*/, const string& mode) const {
		if (!stream.is_open()) {
			cout << "File " << _file_name << " was not open for " << mode << "." << endl;
			system("pause");
			return false;
		}

		return true;
	}

	CFileIO& operator=(const CFileIO&) = delete;
};