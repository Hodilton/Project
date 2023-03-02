#pragma once
#include "stdafx.h"

template<typename T>
class CBinaryFileIO {
public:
    CBinaryFileIO(const string& filename): _file_name(filename) {}

    bool Write(CTree<T>& tree, bool append = false) {
        ios_base::openmode mode = append
            ? ios_base::out | ios_base::binary | ios_base::app
            : ios_base::out | ios_base::binary;

        fstream fout(_file_name, mode);

        if (!IsFileOpen(fout, "write")) {
            fout.close();
            return false;
        }

        CNode<CFund>* tree_root;
        tree_root = tree.GetRoot();
        do {
            if (tree_root->left == NULL) {
                fout.write(reinterpret_cast<const char*>(&tree_root->data), sizeof(T));
                tree_root = tree_root->right;
            }
            else {
                CNode<CFund>* temp = tree_root->left;

                while (temp->right && temp->right != tree_root) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                    temp->right = tree_root;
                    tree_root = tree_root->left;
                }
                else {
                    temp->right = NULL;
                    fout.write(reinterpret_cast<const char*>(&tree_root->data), sizeof(T));
                    tree_root = tree_root->right;
                }
            }

        } while (tree_root);
        fout.close();

        return true;
    }

    bool Read(CTree<T>& tree) {
        ios_base::openmode mode = ios_base::in | ios_base::binary;

        fstream fin(_file_name, mode);

        if (!IsFileOpen(fin, "read")) {
            fin.close();
            return false;
        }

        T temp;
        while (fin.read(reinterpret_cast<char*>(&temp), sizeof(T)))
            tree.AddNode(temp);

        fin.close();

        return true;
    }

private:
    string _file_name;

    bool IsFileOpen( const basic_fstream<char>& stream /*const basic_ios<char>& stream*/, const string& mode) const {
        if (!stream.is_open()) {
            cout << "File " << _file_name << " was not open for " << mode << "." << endl;
            system("pause");
            return false;
        }

        return true;
    }
};