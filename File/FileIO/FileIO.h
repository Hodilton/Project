#pragma once
#include "stdafx.h"
#include "Tree.h"
#include "FileIOBase.h"

template<typename T>
class FileIO : public FileIOBase<T> {
public:
	FileIO() : FileIOBase<T>("") {};
	FileIO(const string& file_name) : FileIOBase<T>(file_name, false) {}

private:
	void BehaviorWrite(ostream& fout, const Tree<T>& tree, const Node<T>* root) const override {
		tree.Print(fout);
	}

	void BehaviorRead(ifstream& fin, Tree<T>& tree) const override {
		while (!fin.eof()) {
			T temp;
			fin >> temp;
			tree.AddNode(temp);
		}
	}

	FileIO& operator=(const FileIO&) = delete;
};