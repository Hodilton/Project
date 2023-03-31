#pragma once
#include"stdafx.h"
#include"CTree.h"

template <typename T>
class IFile {
public:
    IFile(const string& file_name, const bool& binary_mode) : _file_name(file_name), _binary_mode(binary_mode) {}

    bool Write(const CTree<T>& tree, bool append = false) const {
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

        BehaviorWrite(fout, tree, tree.GetRoot());
        fout.close();

        return true;
    }

    bool Read(CTree<T>& tree) const {
        ios_base::openmode mode = _binary_mode 
            ? ios_base::in | ios_base::binary 
            : ios_base::in;

        ifstream fin(_file_name, mode);

        if (!IsFileOpen(fin, "read")) {
            fin.close();
            return false;
        }

        BehaviorRead(fin, tree);

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

    virtual void BehaviorWrite(ostream& fout, const CTree<T>& tree, const CNode<T>* root) const = 0;
    virtual void BehaviorRead(ifstream& fin, CTree<T>& tree) const = 0;
};