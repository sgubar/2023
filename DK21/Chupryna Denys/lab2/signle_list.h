#ifndef signle_list_h
#define signle_list_h

#include <stdio.h>

typedef struct tagSingleListIntElement Node;

struct tagSingleListIntElement {
	Node* next;
	int value;
};

Node* createSingleListIntElement(int value);
void deleteSingleListIntElement(Node* element);
void printSingleListIntElement(Node* element);

typedef struct tagIntSingleList {
	Node* head;
	
} IntSingleList;

IntSingleList* createIntSingleList(void);
void deleteIntSingleList(IntSingleList* list);

void printIntSingleList(IntSingleList* list);

long countOfIntSingleList(IntSingleList* list);

int addIntValueToIntSingleList(IntSingleList* list, int value);
void removeLastElementFromIntSingleList(IntSingleList* list);
void removeFirstElementFromIntSingleList(IntSingleList* list);




#endif 