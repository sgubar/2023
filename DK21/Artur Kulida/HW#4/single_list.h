#ifndef single_list_h
#define single_list_h

#include <stdio.h>

typedef struct tagSingleListCharElement SingleListCharElement;

struct tagSingleListCharElement {
	SingleListCharElement *next;
	char value;
};

SingleListCharElement *createSingleListCharElement(char value);
void deleteSingleListCharElement(SingleListCharElement *element);
void printSingleListCharElement(SingleListCharElement *element);

typedef struct tagCharSingleList {
	SingleListCharElement *head;
	//long count;
} CharSingleList;

CharSingleList *createCharSingleList(void);
void deleteCharSingleList(CharSingleList *list);

void printCharSingleList(CharSingleList *list);

long countOfCharSingleList(CharSingleList *list);
// 1: success, 0 - fail
int addCharValueToCharSingleList(CharSingleList *list, char value);
void removeLastElementFromCharSingleList(CharSingleList *list);
void removeFirstElementFromCharSingleList(CharSingleList *list);

// 1: success, 0 - fail
int insertCharElementToCharSingleListAtIndex(CharSingleList *list, int index, char value);
// 1: success, 0 - fail
int removeCharElementFromCharSingleListAtIndex(CharSingleList *list, int index);
#endif /* signle_list_h */
