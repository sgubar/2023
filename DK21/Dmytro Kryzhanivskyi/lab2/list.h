#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#ifndef LIST_H
#define LIST_H

 typedef struct node {
	 int data;
	 struct node *next;
	 struct node *prev;
} Node;

typedef struct list {
	Node *head;
	Node *tail;
} List;

Node *CreateNode(int data);
void DeleteElement(Node *element);
List *CreateList(void);
void DeleteList(List *List);
void PrintList(List *List);
int AddValueToList(List *List, int data);
void SortAfterMin(List *list);

#endif


