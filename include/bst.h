// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
#include <algorithm>

template < class T >
class BST {
 public:
    struct Node {
        T word;
        int count;
        Node* left;
        Node* right;
    };

 private:
    Node* root;
    Node* addNode(Node*, T);
    void printTree(Node*);
    int depthTree(Node*);
    void delTree(Node*);
    void copyTree(Node*, Node**);

 public:
    BST();
    BST(const BST&);
    ~BST();
    BST& operator= (const BST&);
    void add(T);
    void print();
    int depth();
    void clear();
    void remove(int);
    int search(T);
};

template < class T >
BST<T>::BST() {
    root = nullptr;
}

template < class T >
BST<T>::BST(const BST& srcTree) {
    root = nullptr;
    copyTree(srcTree.root, &root);
}

template < class T >
BST<T>& BST<T>::operator= (const BST<T>& srcTree) {
    copyTree(srcTree.root, &root);
    return *this;
}

template < class T >
BST<T>::~BST() {
    if (root)
        delTree(root);
}

template < class T >
void BST<T>::copyTree(Node* src, Node** dst) {
    if (src == nullptr) {
        *dst = nullptr;
        return;
    }
    if (*dst == nullptr) {
        *dst = new Node;
        (*dst)->count = src->count;
        (*dst)->word = src->word;
        (*dst)->left = (*dst)->right = nullptr;
    }
    copyTree(src->left, &((*dst)->left));
    copyTree(src->right, &((*dst)->right));
}

template < class T >
typename BST<T>::Node* BST<T>::addNode(Node* root, T value) {
    if (root == nullptr) {
        root = new Node;
        root->count = 1;
        root->word = value;
        root->left = root->right = nullptr;
    } else if (root->word > value) {
        root->left = addNode(root->left, value);
    } else  if (root->word < value) {
        root->right = addNode(root->right, value);
    } else {
        root->count++;
    }
    return root;
}

template < class T >
void BST<T>::add(T value) {
    root = addNode(root, value);
}

template < class T >
void BST<T>::printTree(Node* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->word << " : " << root->count << std::endl;
    printTree(root->right);
}

template < class T >
void BST<T>::print() {
    printTree(root);
}

template < class T >
void BST<T>::delTree(Node* root) {
    if (root == nullptr) {
        return;
    } else {
        delTree(root->left);
        delTree(root->right);
        delete root;
    }
}

template < class T >
void BST<T>::clear() {
    if (root) {
        delTree(root);
        root = nullptr;
    }
}

template < class T >
int BST<T>::depthTree(Node* root) {
    if (root) {
        return 1 + std::max(depthTree(root->left), depthTree(root->right));
    }
    return -1;
}

template < class T >
int BST<T>::depth() {
    return depthTree(root);
}
template < class T >
int BST<T>::search(T word) {
    Node* p = root;
    if (!p) return 0;
    while (p->word != word) {
        if (p->word > word) {
            p = p->left;
        } else {
            p = p->right;
        }
        if (p == NULL) {
            break;
        }
    }
    if (p) {
        return p->count;
    } else {
        return 0;
    }
}
#endif  // INCLUDE_BST_H_
