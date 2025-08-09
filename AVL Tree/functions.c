#include "functions.h"
#include "stdlib.h"
#include "stdio.h"

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* buildTree(Node* root, int val) {
    if(!root) return createNode(val);
    if(root->val>val) root->left = buildTree(root->left, val);
    else root->right = buildTree(root->right, val);
    return root;
}

void inorder(Node* root) {
    if(!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

void preorder(Node* root) {
    if(!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int maxx(int a, int b) {
    return a>b ? a : b;
}

int height(Node* root) {
    return !root ? 0 : 1 + maxx(height(root->left), height(root->right));
}

int balanceFactor(Node* root) {
    int left = height(root->left);
    int right = height(root->right);
    return left - right;
}

Node* balanceTree(Node* root) {
    if(!root) return NULL;
    root->left = balanceTree(root->left);
    root->right = balanceTree(root->right);
    int bF = balanceFactor(root);
    if(bF==2) {
        int bF2 = balanceFactor(root->left);
        if(bF2==1) { // R - Rotation
            Node* temp = root->left;
            root->left = temp->right;
            temp->right = root;
            return temp;
        } else { // LR - Rotation
            Node* temp = root->left;
            Node* temp2 = temp->right;
            temp->right = temp2->left;
            temp2->left = temp;
            root->left = temp2;

            temp = root->left;
            root->left = temp->right;
            temp->right = root;
            return temp;
        }
    } else if(bF==-2) {
        int bF2 = balanceFactor(root->right);
        if(bF2==-1) { // L - Rotation
            Node* temp = root->right;
            root->right = temp->left;
            temp->left = root;
            return temp;
        } else { // RL - Rotation
            Node* temp = root->right;
            Node* temp2 = temp->left;
            temp->left = temp2->right;
            temp2->right = temp;
            root->right = temp2;

            temp = root->right;
            root->right = temp->left;
            temp->left = root;
            return temp;
        }
    } return root;
}

void traversal(Node* root) {
    printf("Preorder Tarversal: ");
    preorder(root);
    printf("\n");
    printf("Inorder Tarversal: ");
    inorder(root);
    printf("\n");
    printf("Postorder Tarversal: ");
    postorder(root);
    printf("\n");
}

Node* pred(Node* root) {
    Node* temp = root->left;
    while(temp->right) temp = temp->right;
    return temp;
}

Node* deleteHelper(Node* root,int val) {
    if(!root){
        printf("%d is not found in the Tree!!\n", val);
        return NULL;
    } if(root->val==val) {
        if(root->left && root->right) {
            Node* temp = pred(root);
            root->val = temp->val;
            root->left = deleteHelper(root->left, temp->val);
            return root;
        } else if(root->left)
            return root->left;
        else if(root->right)
            return root->right;
        else
            return NULL;
    } if(root->val>val)
        root->left = deleteHelper(root->left, val);
    else
        root->right = deleteHelper(root->right, val);
    return root;
}

Node* deleteNode(Node* root, int val) {
    root = deleteHelper(root, val);
    root = balanceTree(root);
    return root;
}

Node* constructAVLTree(int* arr, int n) {
    Node* root = NULL;
    for(int i=0;i<n;i++) {
        root = buildTree(root, *(arr+i));
        root = balanceTree(root);
    } return root;
}

void input(int* arr, int n) {
    printf("Enter Input Values: ");
    for(int i=0;i<n;i++)
        scanf("%d", (arr+i));
}
