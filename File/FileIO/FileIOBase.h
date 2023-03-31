#pragma once
#include "stdafx.h"
#include "Tree.h"

template <typename T>
class FileIOBase {
public:
    FileIOBase(const string& file_name, const bool& binary_mode) : _file_name(file_name), _binary_mode(binary_mode) {}

    bool Write(const Tree<T>& tree, bool append = false) const {
        ios_base::openmode mode = _binary_mode
            ? (append 
                ? ios_base::out | ios_base::binary | ios_base::app 
                : ios_base::out | ios_base::binary)
            : (append 
                ? ios_base::out | ios_base::app 
                : ios_base::out);

        ofstream fout(_file_name, mode);

        if (!IsFileOpen(fout, "write")) {
            fout.close();
            return false;
        }

        SetBehaviorWrite(fout, tree, tree.GetRoot());
        fout.close();

        return true;
    }

    bool Read(Tree<T>& tree) const {
        ios_base::openmode mode = _binary_mode 
            ? ios_base::in | ios_base::binary 
            : ios_base::in;

        ifstream fin(_file_name, mode);

        if (!IsFileOpen(fin, "read")) {
            fin.close();
            return false;
        }

        SetBehaviorRead(fin, tree);

        fin.close();

        return true;
    }

protected:
    string _file_name;
    bool _binary_mode;

    template <typename Stream>
    bool IsFileOpen(const Stream& stream, const string& mode) const {
        if (!stream.is_open()) {
            cout << "File " << _file_name << " was not open for " << mode << "." << endl;
            system("pause");
            return false;
        }
        return true;
    }

    virtual void SetBehaviorWrite(ostream& fout, const Tree<T>& tree, const Node<T>* root) const = 0;
    virtual void SetBehaviorRead(ifstream& fin, Tree<T>& tree) const = 0;
};