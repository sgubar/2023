#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "dk21_tool.h"

BinTree* crtTree()
{
    BinTree* aTree = (BinTree*)malloc(sizeof(BinTree));
    if (NULL != aTree)
    {
        aTree->root = NULL;
        aTree->count = 0;
    }
    return aTree;
}

void dstrTree(BinTree* aTree)
{
    if (NULL != aTree)
    {
        free(aTree);
    }
}

void dbgTree(BinTree* ATree)
{
    addNd(ATree, 5);
    addNd(ATree, 7);
    addNd(ATree, 16);
    addNd(ATree, 3);
    addNd(ATree, 9);
}
Node* crtNd(int aValue)
{
    Node* theNode = (Node*)malloc(sizeof(Node));

    if (NULL != theNode)
    {
        theNode->leftChild = NULL;
        theNode->rightChild = NULL;
        theNode->value = aValue;
    }

    return theNode;
}

void dstrNd(Node* aNode)
{
    if (NULL != aNode)
    {
        free(aNode);
    }
}

Node* dstrTreeNd(Node* treeRoot, int value)
{
    if (treeRoot == NULL)
    {
        return treeRoot;
    }
    if (value < treeRoot->value)
    {
        treeRoot->leftChild = dstrTreeNd(treeRoot->leftChild, value);
    }
    else if (value > treeRoot->value)
    {
        treeRoot->rightChild = dstrTreeNd(treeRoot->rightChild, value);
    }
    else
    {
        if (treeRoot->leftChild == NULL)
        {
            Node* tempNode = treeRoot->rightChild;
            dstrNd(treeRoot);
            return tempNode;
        }
        else if (treeRoot->rightChild == NULL)
        {
            Node* tempNode = treeRoot->leftChild;
            dstrNd(treeRoot);
            return tempNode;
        }
        Node* tempNode = getSucc(treeRoot->rightChild);
        treeRoot->value = tempNode->value;
        treeRoot->rightChild = dstrTreeNd(treeRoot->rightChild, tempNode->value);
    }
    return treeRoot;
}

Node* getSucc(Node* treeRoot)
{
    Node* theCurrent = treeRoot;
    while (theCurrent && theCurrent->leftChild != NULL)
    {
        theCurrent = theCurrent->leftChild;
    }
    return theCurrent;
}

void addNd(BinTree* aTree, int aValue)
{
    if (NULL == aTree)
    {
        return;
    }
    Node* theNode = crtNd(aValue);
    if (NULL == theNode)
    {
        return;
    }
    if (NULL == aTree->root)
    {
        aTree->root = theNode;
        aTree->count++;
    }
    else
    {
        Node* theCurrent = aTree->root;
        Node* theParent = NULL;
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

        aTree->count++;
    }
}

Node* fndNd(BinTree* aTree, int aValue)
{
    Node* theCurrentNode = NULL;
    if (NULL != aTree->root)
    {
        theCurrentNode = aTree->root;
        while (aValue != theCurrentNode->value)
        {

            if (aValue < theCurrentNode->value)
            {
                theCurrentNode = theCurrentNode->leftChild;
            }
            else
                theCurrentNode = theCurrentNode->rightChild;

            if (NULL == theCurrentNode)
            {
                break;
            }
        }
    }

    return theCurrentNode;
}

void prntTree(Node* aNode)
{
    if (NULL != aNode)
    {
        prntTree(aNode->leftChild);
        printf("[%d] ", aNode->value);
        prntTree(aNode->rightChild);
    }
}

int delValFrTree(BinTree* aTree, int aValue)
{
    int theResult = 1;
    Node* theCurrentNode = aTree->root;
    Node* theParent = aTree->root;
    int LeftChild = 1;

    while (aValue != theCurrentNode->value)
    {
        theParent = theCurrentNode;
        if (aValue < theCurrentNode->value)
        {
            LeftChild = 1;
            theCurrentNode = theCurrentNode->leftChild;
        }
        else
        {
            LeftChild = 0;
            theCurrentNode = theCurrentNode->rightChild;
        }

        if (NULL == theCurrentNode)
            return 0;
    }

    if (NULL == theCurrentNode->leftChild && NULL == theCurrentNode->rightChild)
    {
        if (aTree->root == theCurrentNode)
            aTree->root = NULL;

        else if (LeftChild)
            theParent->leftChild = NULL;

        else
            theParent->rightChild = NULL;
    }
    else if (NULL == theCurrentNode->rightChild)
    {
        if (aTree->root == theCurrentNode)
            aTree->root = theCurrentNode->leftChild;

        else if (LeftChild)
            theParent->leftChild = theCurrentNode->leftChild;

        else
            theParent->rightChild = theCurrentNode->leftChild;
    }
    else if (NULL == theCurrentNode->leftChild)
    {
        if (aTree->root == theCurrentNode)
            aTree->root = theCurrentNode->rightChild;

        else if (LeftChild)
            theParent->leftChild = theCurrentNode->rightChild;

        else
            theParent->rightChild = theCurrentNode->rightChild;
    }

    free(theCurrentNode);
    theResult = 1;
    return theResult;
}