#include "bst.h"
#include <iostream>
#include <algorithm>
using namespace std;

BST::BST() {
    root = nullptr;
}

void BST::insertR(Node*& p, const string& value) {
    if (p == nullptr) {
        Node* n = new Node(value);
        p = n;
    } else {
        if (p->data >= value)
            insertR(p->left, value);
        else
            insertR(p->right, value);
    }
}

void BST::insert(const string& value) {
    insertR(root, value);
}

int BST::sizeR(Node* p) {
    if (p == nullptr)
        return 0;
    else
        return 1 + sizeR(p->left) + sizeR(p->right);
}

int BST::size() {
    return sizeR(root);
}

int BST::heightR(Node* p) {
    if (p == nullptr) return -1;
    return 1 + max(heightR(p->left), heightR(p->right));
}

int BST::height() {
    return heightR(root);
}

void BST::completionsR(Node* p, const string& prefix) {
    if (p == nullptr) return;

    if (p->data.substr(0, prefix.size()) == prefix) {
        cout << p->data << " ";
    }

    completionsR(p->left, prefix);
    completionsR(p->right, prefix);
}

void BST::completions(const string& prefix) {
    completionsR(root, prefix);
}
