#pragma once
#include "stdafx.h"

template<typename T>
class CBinaryFileIO {
public:
    CBinaryFileIO() : _file_name("") {};
    CBinaryFileIO(const string& filename) : _file_name(filename) {}

    bool Write(CTree<T>& tree, bool append = false) const {
        ios_base::openmode mode = append
            ? ios_base::out | ios_base::binary | ios_base::app
            : ios_base::out | ios_base::binary;

        fstream fout(_file_name, mode);

        if (!IsFileOpen(fout, "write")) {
            fout.close();
            return false;
        }

        CNode<T>* tree_root;
        tree_root = tree.GetRoot();
        WriteTree(fout, tree_root);

        fout.close();

        return true;
    }

    bool Read(CTree<T>& tree) const {
        ios_base::openmode mode = ios_base::in | ios_base::binary;

        fstream fin(_file_name, mode);

        if (!IsFileOpen(fin, "read")) {
            fin.close();
            return false;
        }

        T temp;
        while (fin.read(reinterpret_cast<char*>(&temp), sizeof(T))) {
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

    void WriteTree(basic_fstream<char>& stream, const CNode<T>* tree) const {
        if (tree) {
            WriteTree(stream, tree->right);
            stream.write(reinterpret_cast<const char*>(&tree->data), sizeof(T));
            WriteTree(stream, tree->left);
        }
    }

    CBinaryFileIO& operator=(const CBinaryFileIO&) = delete;
};