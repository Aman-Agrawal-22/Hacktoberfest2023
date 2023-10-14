#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

   
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

bool helper(Node* root, int lb, int ub) {
    if (!root) return 1;
    if (root->data < lb || root->data > ub) return 0;
    bool lans = helper(root->left, lb, root->data);
    bool rans = helper(root->right, root->data, ub);
    return lans && rans;
}

/* Function to check if the given tree is a binary search tree */
int isBST(Node* node) {
    if (!node) return 1;
    return helper(node, INT_MIN, INT_MAX);
    
}

Node* buildTree() {
    int data;
    cin >> data;

    if (data == -1)
        return NULL;

    Node* root = new Node(data);

    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    Node* root = buildTree();

    if (isBST(root))
        cout << "The given binary tree is a BST" << endl;
    else
        cout << "The given binary tree is not a BST" << endl;

    return 0;
}
