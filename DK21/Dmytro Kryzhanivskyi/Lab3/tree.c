#include "tree.h"
#include <stdlib.h>

static void destroyNode(CharNode *aNode);
static CharNode *createCharNodeWithValue(char aValue);
static CharNode *getSuccessor(CharTree *tree, CharNode *toDelete);
static void print_char_node(CharNode *node);

CharTree *createCharTree()
{
	CharTree *theTree = malloc(sizeof(*theTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}
	
	return theTree;
}

void destroyCharTree(CharTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertCharValueToTree(CharTree *aTree, char aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	CharNode *theNode = createCharNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}
	
	if (NULL == aTree->root)
	{
		aTree->root = theNode;
		aTree->count ++;
	}
	else
	{
		CharNode *theCurrent = aTree->root;
		CharNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;
		
			if (aValue < theCurrent->value)
			{
				theCurrent = theCurrent->leftChild;
				if (NULL == theCurrent)
				{
					theParent->leftChild = theNode;
					break;
				}
			}
			else
			{
				theCurrent = theCurrent->rightChild;
				if (NULL == theCurrent)
				{
					theParent->rightChild = theNode;
					break;
				}
			}
		}
	
		aTree->count ++;
	}
}

CharNode *findNodeWithValue(CharTree *aTree, char aValue)
{
	CharNode *theCurrentNode = NULL;
	
	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root; //<! - start from root
		while (aValue != theCurrentNode->value) //<! - walk through the tree
		{
			theCurrentNode = (aValue < theCurrentNode->value)
						? theCurrentNode->leftChild
						: theCurrentNode->rightChild;
		
			if (NULL == theCurrentNode)
			{
				break;
			}
		}
	}
	
	return theCurrentNode;
}

void deleteNodeWithValue(CharTree *aTree, char aValue) {

	// check input parameters
	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	CharNode *current = aTree->root;
	CharNode *parent = aTree->root;

	// find node for delete
	while (aValue != current->value) {
		parent = current;
		if (aValue < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	//1) the found node is leaf node?
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		aTree->count --;
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		CharNode *successor = getSuccessor(aTree, current);
		if (aTree->root == successor) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

void printTree(CharTree *aTree) {
	CharNode* item = aTree->root;
	print_char_node(item);
}

void print_char_node(CharNode *node) {
	if (node == NULL)
		return;
	print_char_node(node->leftChild);
	printf("Element: %c\n", node->value);
	print_char_node(node->rightChild);
}

void printNode(CharNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("value(%c)", aNode->value);
}

//int countNodesWithTree(CharTree *aTree);

void destroyNode(CharNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

CharNode *createCharNodeWithValue(char aValue)
{
	CharNode *theNode = (CharNode *)malloc(sizeof(CharNode));
	
	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}
	
	return theNode;
}

CharNode *getSuccessor(CharTree *tree, CharNode *toDelete) {
	CharNode *successParent = toDelete;
	CharNode *successor = toDelete;
	CharNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}
	if (successor != toDelete->rightChild) { // 35 != 39
		successParent->leftChild = successor->rightChild; //39 -> NULL
		successor->rightChild = toDelete->rightChild; //35->39
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}
