#pragma once
#include "stdafx.h"
#include "CTree.h"
#include"IFile.h"

template<typename T>
class CFileIO : public IFile<T> {
public:
	CFileIO() : IFile<T>("") {};
	CFileIO(const string& file_name) : IFile<T>(file_name, false) {}

private:
	void BehaviorWrite(ostream& fout, const CTree<T>& tree, const CNode<T>* root) const override {
		tree.Print(fout);
	}

	void BehaviorRead(ifstream& fin, CTree<T>& tree) const override {
		while (!fin.eof()) {
			T temp;
			fin >> temp;
			tree.AddNode(temp);
		}
	}

	CFileIO& operator=(const CFileIO&) = delete;
};