#include "tree.h"
#include <stdlib.h>


DoubleTree *createDoubleTree()
{
	DoubleTree *NewTree = (DoubleTree *)malloc(sizeof(DoubleTree));

	if (NULL != NewTree)
	{
		NewTree->root = NULL;
		NewTree->count = 0;
	}

	return NewTree;
}
void destroyNode(DoubleNode *Node)
{
	if (NULL != Node)
	{
		destroyNode(Node->leftChild);
		destroyNode(Node->rightChild);

		free(Node);
	}
}

void destroyTree(DoubleTree *Tree)
{
	if (NULL != Tree)
	{
		destroyNode(Tree->root);
		free(Tree);
	}
}

void insertdoubleValueToTree(DoubleTree *Tree, double Value)
{
	if (NULL == Tree)
	{
		return;
	}

	DoubleNode *Node = createDoubleNodeWithValue(Value);
	if (NULL == Node)
	{
		return;
	}

	if (NULL == Tree->root)
	{
		Tree->root = Node;
		Tree->count ++;
	}
	else
	{
		DoubleNode *Current = Tree->root;
		DoubleNode *Parent = NULL;

		while (1)
		{
			Parent = Current;

			if (Value < Current->value)
			{
				Current = Current->leftChild;
				if (NULL == Current)
				{
					Parent->leftChild = Node;
					break;
				}
			}
			else
			{
				Current = Current->rightChild;
				if (NULL == Current)
				{
					Parent->rightChild = Node;
					break;
				}
			}
		}

		Tree->count ++;
	}
}

DoubleNode *findNodeWithValue(DoubleTree *Tree, double Value)
{
	DoubleNode *CurrentNode = NULL;

	if (NULL != Tree && NULL != Tree->root)
	{
		CurrentNode = Tree->root;
		while (Value != CurrentNode->value)
		{
			CurrentNode = (Value < CurrentNode->value)
						? CurrentNode->leftChild
						: CurrentNode->rightChild;

			if (NULL == CurrentNode)
			{
				break;
			}
		}
	}

	return CurrentNode;
}

void deleteNodeWithValue(DoubleTree *Tree, double Value) {

	if (NULL == Tree || NULL == Tree->root) {
		return ;
	}

	DoubleNode *current = Tree->root;
	DoubleNode *parent = Tree->root;

	while (Value != current->value) {
		parent = current;
		if (Value < current->value) {
			current = current->leftChild;
		} else {
			current = current->rightChild;
		}

		if (NULL == current) {
			return ;
		}
	}

	if (NULL == current->leftChild && NULL == current->rightChild) {
		if (Tree->root == current) {
			Tree->root = NULL;
		} else if (parent->leftChild == current) {
			parent->leftChild = NULL;
		} else {
			parent->rightChild = NULL;
		}

		Tree->count --;
	} else if (NULL == current->rightChild) {
		if (Tree->root == current) {
			Tree->root = current->leftChild;
		} else if (parent->leftChild == current) {
			parent->leftChild = current->leftChild;
		} else {
			parent->rightChild = current->rightChild;
		}
	} else if (NULL == current->leftChild) {
		if (Tree->root == current) {
			Tree->root = current->rightChild;
		} else if (parent->rightChild == current) {
		 	parent->rightChild = current->rightChild;
		} else {
			parent->leftChild = current->leftChild;
		}
	} else {
		DoubleNode *successor = getSuccessor(Tree, current);
		if (Tree->root == successor) {
			Tree->root = NULL;
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

void printTree(DoubleTree *Tree) {
	print_double_node(Tree->root);
}

void print_double_node(DoubleNode *node) {
	if (node == NULL)
		return;
	print_double_node(node->leftChild);
	printf("element: %f\n", node->value);
	print_double_node(node->rightChild);
}

void printNode(DoubleNode *aNode)
{
	if (aNode == NULL)
	 return;

	printf("found element: %f\n", aNode->value);
}



DoubleNode *createDoubleNodeWithValue(double aValue)
{
	DoubleNode *theNode = (DoubleNode *)malloc(sizeof(DoubleNode));

	if (NULL != theNode)
	{
		theNode->leftChild = NULL;
		theNode->rightChild = NULL;
		theNode->value = aValue;
	}

	return theNode;
}

DoubleNode *getSuccessor(DoubleTree *tree, DoubleNode *toDelete) {
	DoubleNode *successParent = toDelete;
	DoubleNode *successor = toDelete;
	DoubleNode *current = toDelete->rightChild;

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
