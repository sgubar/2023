#ifndef DK21_TOOL_H
#define DK21_TOOL_H

typedef struct tagNode Node;

struct tagNode
{
    int value;
    Node* leftChild;
    Node* rightChild;
};

typedef struct tagBinTree
{
    Node* root;
    int count;
} BinTree;

BinTree* crtTree();
void dstrTree(BinTree* aTree);
Node* crtNd(int aValue);
void dstrNd(Node* aNode);
Node* dstrTreeNd(Node* treeRoot, int aValue);
Node* getSucc(Node* treeRoot);
void addNd(BinTree* aTree, int aValue);
Node* fndNd(BinTree* aTree, int aValue);
int delValFrTree(BinTree* aTree, int aValue);

void prntTree(Node* aNode);
void dbgTree(BinTree* ATree);

#endif
