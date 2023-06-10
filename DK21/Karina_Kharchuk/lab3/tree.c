#include "tree.h"
#include <stdlib.h>

static void destroyNode(FloatNode *aNode);

FloatTree *createFloatTree()
{
	FloatTree *theTree = (FloatTree *)malloc(sizeof(FloatTree));
	
	if (NULL != theTree)
	{
		theTree->root = NULL;
	}
	
	return theTree;
}

void print_float_node(FloatNode *node) {
	if (node == NULL)
	{	
		return;
	}
	print_float_node(node->leftChild);
	print_float_node(node->rightChild);
	printf("Елемент: %f\n", node->value);
}

void printTree(FloatTree *aTree) 
{
	FloatNode* item = aTree->root;
    	print_float_node(item);
}

void printNode(FloatNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("value(%f)", aNode->value);
}

void destroyNode(FloatNode *aNode)
{
	if (NULL != aNode)
	{
		destroyNode(aNode->leftChild);
		destroyNode(aNode->rightChild);
	
		free(aNode);
	}
}

void destroyFloatTree(FloatTree *aTree)
{
        if (NULL != aTree)
        {
                destroyNode(aTree->root);
                free(aTree);
        }
}

FloatNode *getSuccessor(FloatNode *toDelete) {
        FloatNode *successParent = toDelete;
        FloatNode *successor = toDelete;
        FloatNode *current = toDelete->rightChild;

        while(NULL != current) {
                successParent = successor;
                successor = current;
                current = current->leftChild;
        }

        if (successor != toDelete->rightChild) {
                successParent->rightChild = successor->rightChild;
                successor->rightChild = toDelete->rightChild;
        }

        successor->leftChild = toDelete->leftChild;

        return successor;
}

void deleteNodeWithValue(FloatTree *aTree, float aValue) 
{
	if (NULL == aTree || NULL == aTree->root) {
		return ;
	}

	FloatNode *current = aTree->root;
	FloatNode *parent = aTree->root;

	// шукаємо яку видалити
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

	//чи це листкова нода
	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		
	} else if (NULL == current->rightChild) {
		if (aTree->root == current) {
			aTree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->leftChild;
		}
	} else if (NULL == current->leftChild) {
		if (aTree->root == current) {
			aTree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->rightChild;
		}
	} else {
		FloatNode *successor = getSuccessor(current);
		if (aTree->root == current) 
		{
			aTree->root = successor;
		}	else if (parent->leftChild == current) {
			parent->leftChild = successor;
		} else {
			parent->rightChild = successor;
		}
		current->leftChild = NULL;
		current->rightChild = NULL;
	}

	destroyNode(current);
}

FloatNode *createFloatNodeWithValue(float aValue)
{
        FloatNode *theNode = (FloatNode *)malloc(sizeof(FloatNode));

        if (NULL != theNode)
        {
                theNode->leftChild = NULL;
                theNode->rightChild = NULL;
                theNode->value = aValue;
        }

        return theNode;
}

void insertFloatValueToTree(FloatTree *aTree, float aValue)
{
	if (NULL == aTree)
	{
		return;
	}

	FloatNode *theNode = createFloatNodeWithValue(aValue);
	if (NULL == theNode)
	{
		return;
	}

	if (NULL == aTree->root)
	{
		aTree->root = theNode;
	}
	else
	{
		FloatNode *theCurrent = aTree->root;
		FloatNode *theParent = NULL;

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

FloatNode *findNodeWithValue(FloatTree *aTree, float aValue)
{
	FloatNode *theCurrentNode = NULL;

	if (NULL != aTree && NULL != aTree->root)
	{
		theCurrentNode = aTree->root; //починаємо від корення
		while (aValue != theCurrentNode->value) 
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
