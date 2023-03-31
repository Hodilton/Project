#pragma once
#include "stdafx.h"
#include "Tree.h"
#include "FileIOBase.h"

template <typename T>
class FileIOBinary : public FileIOBase<T> {
public:
    FileIOBinary() : FileIOBase<T>("") {}
    FileIOBinary(const string& file_name) : FileIOBase<T>(file_name, true) {}

private:
    void BehaviorWrite(ostream& fout, const Tree<T>& tree, const Node<T>* root) const override {
        if (root) {
            BehaviorWrite(fout, tree, root->right);
            fout.write(reinterpret_cast<const char*>(&root->data), sizeof(T));
            BehaviorWrite(fout, tree, root->left);
        }
    }

    void BehaviorRead(ifstream& fin, Tree<T>& tree) const override {
        T temp;
        while (fin.read(reinterpret_cast<char*>(&temp), sizeof(T))) {
            tree.AddNode(temp);
        }
    }
};