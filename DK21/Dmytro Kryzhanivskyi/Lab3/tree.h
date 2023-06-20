#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	char value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} CharNode;

typedef struct __tagTree
{
	CharNode *root;
	int count;
} CharTree;

// interface
CharTree *createCharTree();
void destroyCharTree(CharTree *aTree);

void insertCharValueToTree(CharTree *aTree, char aValue);
CharNode *findNodeWithValue(CharTree *aTree, char aValue);
void deleteNodeWithValue(CharTree *aTree, char aValue);

void printTree(CharTree *aTree);
void printNode(CharNode *aNode);
int countNodesWithTree(CharTree *aTree);

#endif /* tree_h */
