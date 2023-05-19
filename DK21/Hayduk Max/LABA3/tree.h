#ifndef TREE_H
#define TREE_H

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data);
struct Node* insert(struct Node* root, int data);
void printTree(struct Node* root);
struct Node* search(struct Node* root, int data);
struct Node* deleteNode(struct Node* root, int data);
void deleteTree(struct Node* root);

#endif
