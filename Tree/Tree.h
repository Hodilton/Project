#pragma once
#ifndef _TREE_H_
#define _TREE_H_
#include "stdafx.h"

template <typename T>
class Node {
public:
    T data;
    Node* left;
    Node* right;

    Node() : left(nullptr), right(nullptr) {}
    Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
};

template <typename T>
class Tree {
private:
    Node<T>* _root;

    Tree(const Tree&) = delete;
    Tree& operator=(const Tree&) = delete;

    Node<T>* CreateRoot(const T& data);
    void AddNode(Node<T>** root, const T& data);
    void DeleteNode(Node<T>** root, const T& data);
    void Print(ostream& out, Node<T>* root) const;
    void FreeMemory(Node<T>** root);

    Node<T>* FindMin(Node<T>* data);

public:
    Tree() : _root(nullptr) {}
    ~Tree();

    void AddNode(const T& data);
    void DeleteNode(const T& data);
    void Print(ostream& out) const;

    Node<T>* GetRoot() const;
};

#include "Tree.cpp"
#endif // !_TREE_H_