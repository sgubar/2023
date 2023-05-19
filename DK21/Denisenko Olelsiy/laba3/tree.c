#include "tree.h"
#include <stdlib.h>

static void destroyNode(floatNode *aNode);
static floatNode *createShortNodeWithValue(float value);
static floatNode *getSuccessor(floatTree *tree, floatNode *toDelete);
static void print_float_node(floatNode *node);

floatTree *createfloatTree()
{
	floatTree *theTree = (floatTree *)malloc(sizeof(floatTree));

	if (NULL != theTree)
	{
		theTree->root = NULL;
		theTree->count = 0;
	}

	return theTree;
}

void destroyfloatTree(floatTree *aTree)
{
	if (NULL != aTree)
	{
		destroyNode(aTree->root);
		free(aTree);
	}
}

void insertfloatValueToTree(floatTree *aTree, float value)
{
	if (NULL == aTree)
	{
		return;
	}

	floatNode *theNode = createfloatNodeWithValue(value);
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
		floatNode *theCurrent = aTree->root;
		floatNode *theParent = NULL;

		while (1)
		{
			theParent = theCurrent;

			if (value < theCurrent->value)
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

floatNode *findNodeWithValue(floatTree *aTree, float value)
{
	floatNode *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root;
		while (value != theCurrentNode->value)
		{
			theCurrentNode = (value < theCurrentNode->value)
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

void deleteNodeWithValue(floatTree *aTree, float value) {

	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	floatNode *current = aTree->root;
	floatNode *parent = aTree->root;

	while (value != current->value) {
		parent = current;
		if (value < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

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
		floatNode *successor = getSuccessor(aTree, current);
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

void printTree(floatTree *aTree) {
	floatNode* item = aTree->root;
	print_float_node(item);
}

void print_float_node(floatNode *node) {
	if (node == NULL)
		return;
	print_float_node(node->leftChild);
	print_float_node(node->rightChild);
	printf("element: %f\n", node->value);
}

void printNode(floatNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("value(%f)", aNode->value);
}


#pragma mark -
void destroyNode(floatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);

		free(aNode);
	}
}

floatNode *createfloatNodeWithValue(float value)
{
	floatNode *theNode = (floatNode *)malloc(sizeof(floatNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = value;
	}

	return theNode;
}

floatNode *getSuccessor(floatTree *tree, floatNode *toDelete) {
	floatNode *successParent = toDelete;
	floatNode *successor = toDelete;
	floatNode *current = toDelete->rightChild;

	while(NULL != current) {
		successParent = successor;
		successor = current;
		current = current->leftChild;
	}

	if (successor != toDelete->rightChild) {
		successParent->leftChild = successor->rightChild;
		successor->rightChild = toDelete->rightChild;
	}

	successor->leftChild = toDelete->leftChild;

	return successor;
}
