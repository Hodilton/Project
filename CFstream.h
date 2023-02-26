#pragma once
#include "stdafx.h"
#include "CTree.h"

template<typename T>
class CFstream {
public:
	static bool Read(CTree<T>& root, const string& file_name) {
		ifstream fin;
		fin.open(file_name, ios::in);

		if (!fin.is_open()) {
			cout << "File " << file_name << " was not open for read." << endl;
			system("pause");
			fin.close();
			return false;
		}

		while (!fin.eof()) {
			T temp;
			fin >> temp;
			root.AddNode(temp);
		}

		fin.close();
		return true;
	}

	static bool Write(CTree<T>& root, const string& file_name) {
		ofstream fout;
		fout.open(file_name, ios::out);

		if (!fout.is_open()) {
			cout << "File " << file_name << " was not open for write." << endl;
			system("pause");
			fout.close();
			return false;
		}

		root->Print(fout);

		fout.close();
		return 0;
	}

private:
	CFstream() = delete;
	CFstream(const CFstream&) = delete;
	CFstream& operator=(const CFstream&) = delete;
};