#ifndef _TREE_CPP_
#define _TREE_CPP_
#include "Tree.h"

template <typename T>
Node<T>* Tree<T>::CreateRoot(const T& data)
{
    Node<T>* p = new Node<T>(data);
    return p;
}

template<typename T>
void Tree<T>::AddNode(Node<T>** root, const T& data)
{
    if (!*root) *root = CreateRoot(data);
    else
    {
        if (data < (*root)->data) {
            if (!(*root)->left) (*root)->left = CreateRoot(data);
            else AddNode(&(*root)->left, data);
        }

        if (data > (*root)->data) {
            if (!(*root)->right) (*root)->right = CreateRoot(data);
            else AddNode(&(*root)->right, data);
        }
    }
}

template<typename T>
void Tree<T>::DeleteNode(Node<T>** root, const T& data)
{
    if (*root == nullptr) return;

    if (data < (*root)->data) {
        DeleteNode(&(*root)->left, data);
    }
    else if (data > (*root)->data) {
        DeleteNode(&(*root)->right, data);
    }
    else if (data == (*root)->data) {
        if ((*root)->left == nullptr) {
            Node<T>* temp = *root;
            *root = (*root)->right;
            delete temp;
        }
        else if ((*root)->right == nullptr) {
            Node<T>* temp = *root;
            *root = (*root)->left;
            delete temp;
        }
        else // Есть оба потомка
        {
            Node<T>* temp = FindMin((*root)->right); // Находим минимальный элемент в правом поддереве
            (*root)->data = temp->data; // Копируем значение в удаляемый узел
            DeleteNode(&(*root)->right, temp->data); // Удаляем найденный узел
        }
    }
}

template<typename T>
void Tree<T>::Print(ostream& out, Node<T>* root) const
{
   /* if (root) {
        Print(root->right);
        out << root->data << endl << endl;
        Print(root->left);
    }*/

    if (root) {
        bool new_line;
        bool first = true;
        do {
            new_line = false;
            if (root->left == NULL) {
                new_line = true;
                if (!first) out << endl << endl;
                out << root->data;
                root = root->right;
                first = false;
            }
            else {
                Node<T>* temp = root->left;

                while (temp->right && temp->right != root) {
                    temp = temp->right;
                }

                if (temp->right == NULL) {
                    temp->right = root;
                    root = root->left;
                }
                else {
                    new_line = true;
                    temp->right = NULL;
                    if (!first) out << endl << endl;
                    out << root->data;
                    root = root->right;
                    first = false;
                }
            }

        } while (root);
        if (!new_line) out << endl << endl;
    }
    else {
        cout << "Root is empty" << endl;
    }
}

template<typename T>
void Tree<T>::FreeMemory(Node<T>** root)
{
   /* if (*root)
    {
        FreeMemory(&(*root)->left);
        FreeMemory(&(*root)->right);

        delete (*root);
        (*root) = nullptr;
    }*/


    if (*root)
    {
        if ((*root)->left)
        {
            FreeMemory(&(*root)->left);
            (*root)->left = nullptr;
        }
        if ((*root)->right)
        {
            FreeMemory(&(*root)->right);
            (*root)->right = nullptr;
        }

        delete (*root);
        (*root) = nullptr;
    }
}

template<typename T>
Node<T>* Tree<T>::FindMin(Node<T>* data)
{
    while (data->left != nullptr) {
        data = data->left;
    }
    return data;
}

template<typename T>
Tree<T>::~Tree()
{
    this->FreeMemory(&_root);
}

template<typename T>
void Tree<T>::AddNode(const T& data)
{
    this->AddNode(&_root, data);
}

template<typename T>
void Tree<T>::DeleteNode(const T& data)
{
    this->DeleteNode(&_root, data);
}

template<typename T>
void Tree<T>::Print(ostream& out) const
{
    this->Print(out, _root);
}

template<typename T>
Node<T>* Tree<T>::GetRoot() const
{
    return _root;
}

#endif // !_TREE_CPP_