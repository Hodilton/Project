#pragma once
#include "stdafx.h"
#include "CTree.h"
#include"IFile.h"

template <typename T>
class CBinaryFileIO : public IFile<T> {
public:
    CBinaryFileIO() : IFile<T>("") {}
    CBinaryFileIO(const string& file_name) : IFile<T>(file_name, true) {}

private:
    void BehaviorWrite(ostream& fout, const CTree<T>& tree, const CNode<T>* root) const override {
        if (root) {
            BehaviorWrite(fout, tree, root->right);
            fout.write(reinterpret_cast<const char*>(&root->data), sizeof(T));
            BehaviorWrite(fout, tree, root->left);
        }
    }

    void BehaviorRead(ifstream& fin, CTree<T>& tree) const override {
        T temp;
        while (fin.read(reinterpret_cast<char*>(&temp), sizeof(T))) {
            tree.AddNode(temp);
        }
    }
};