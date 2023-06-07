#ifndef list_h
#define list_h
#include<stdio.h>

struct tagSingleListIntElement {
    struct tagSingleListIntElement *next;
    int value;
};
typedef struct tagSingleListIntElement SingleListIntElement;

typedef struct tagIntSingleList {
    SingleListIntElement *head;
} IntSingleList;

IntSingleList *createIntSingleList(void);
void deleteIntSingleList(IntSingleList *list);
SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void printIntSingleList(IntSingleList *list);
int addIntValueToIntSingleList(IntSingleList *list, int value);
void removeDuplicateValues(IntSingleList *list);

#endif /* list_h */
