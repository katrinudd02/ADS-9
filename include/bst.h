// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <iostream>
#include <algorithm>

class BST {
 public:
    struct Node {
        std::string word;
        int count;
        Node* left;
        Node* right;
    };

 private:
    Node* root;
    Node* addNode(Node*, std::string);
    void printTree(Node*);
    int depthTree(Node*);
    void delTree(Node*);

 public:
    BST();
    ~BST();
    void add(std::string);
    void print();
    int depth();
    void clear();
    void remove(int);
};
BST::BST() {
    root = nullptr;
}

BST::~BST() {
    if (root)
        delTree(root);
}

struct BST::Node* BST::addNode(Node* root, std::string value) {
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

void BST::add(std::string value) {
    root = addNode(root, value);
}

void BST::printTree(Node* root) {
    if (root == nullptr)
        return;
    printTree(root->left);
    std::cout << root->word << " : " << root->count << std::endl;
    printTree(root->right);
}

void BST::print() {
    printTree(root);
}

void BST::delTree(Node* root) {
    if (root == nullptr) {
        return;
    } else {
        delTree(root->left);
        delTree(root->right);
        delete root;
    }
}

void BST::clear() {
    if (root) {
        delTree(root);
        root = nullptr;
    }
}

int BST::depthTree(Node* root) {
    if (root) {
        return 1 + std::max(depthTree(root->left), depthTree(root->right));
    }
    return -1;
}

int BST::depth() {
    return depthTree(root);
}
#endif  // INCLUDE_BST_H_
