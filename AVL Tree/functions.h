#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct Node {
    int val;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int);
Node* buildTree(Node*, int);
void inorder(Node*);
void preorder(Node*);
void postorder(Node*);
int maxx(int ,int);
int height(Node*);
int balanceFactor(Node*);
Node* balanceTree(Node*);
void traversal(Node*);
Node* pred(Node*);
Node* deleteHelper(Node*, int);
Node* deleteNode(Node*, int);
Node* constructAVLTree(int*, int n);
void input(int*, int);
#endif
