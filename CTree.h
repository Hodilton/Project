#pragma once
#ifndef _CTREE_H_
#define _CTREE_H_
#include "stdafx.h"

template <typename T>
class CNode {
public:
    T data;
    CNode* left;
    CNode* right;

    CNode() : left(nullptr), right(nullptr) {}
    CNode(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class CTree {
private:
    CNode<T>* _root;

    CTree(const CTree&) = delete;
    CTree& operator=(const CTree&) = delete;

    CNode<T>* CreateRoot(const T& data);
    void AddNode(CNode<T>** root, const T& data);
    void DeleteNode(CNode<T>** root, const T& data);
    void Print(ostream& out, CNode<T>* root);
    void FreeMemory(CNode<T>** root);

    CNode<T>* FindMin(CNode<T>* data);

public:
    CTree() : _root(nullptr) {}
    ~CTree();

    void AddNode(const T& data);
    void DeleteNode(const T& data);
    void Print(ostream& out);

    CNode<T>* GetRoot() const;
};

#include "CTree.cpp"
#endif // !_CTREE_H_