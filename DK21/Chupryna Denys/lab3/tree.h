#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>

typedef struct __tagNode
{
	double value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} DoubleNode;

typedef struct __tagTree
{
	DoubleNode *root;
	int count;
} DoubleTree;

DoubleTree *createDoubleTree();
void destroyNode(DoubleNode *Node);
void destroyTree(DoubleTree *Tree);

void insertDoubleValueToTree(DoubleTree *Tree, double Value);
DoubleNode *findNodeWithValue(DoubleTree *Tree, double Value);
void deleteNodeWithValue(DoubleTree *Tree, double Value);

void printTree(DoubleTree *Tree);
void printNode(DoubleNode *Node);
void print_Double_node(DoubleNode *Node);
DoubleTree *createDoubleTreewithValue(double Value);
DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete);
DoubleNode *createDoubleNodeWithValue(double aValue);
#endif // TREE_H_INCLUDED
