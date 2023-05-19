#ifndef tree_h
#define tree_h

#include <stdio.h>

typedef struct __tagNode
{
	float value;
	struct __tagNode *leftChild;
	struct __tagNode *rightChild;
} floatNode;

typedef struct __tagTree
{
	floatNode *root;
	int count;
} floatTree;

floatNode *createfloatNodeWithValue(float value);
floatTree *createfloatTree();
void destroyfloatTree(floatTree *aTree);

void insertfloatValueToTree(floatTree *aTree, float value);
floatNode *findNodeWithValue(floatTree *aTree, float value);
void deleteNodeWithValue(floatTree *aTree,float value);

void mergeTrees(floatTree *aTreeDst, floatTree *aTreeSrc);

void printTree(floatTree *aTree);
void printNode(floatNode *aNode);
int countNodesWithTree(floatTree *aTree);

#endif

