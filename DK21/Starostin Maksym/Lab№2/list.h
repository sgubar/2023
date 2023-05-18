#ifndef MAIN_C_
#define MAIN_C_

// Code for header body
#include <stdio.h>

typedef struct tagSingleListIntElement SingleListIntElement;

struct tagSingleListIntElement {
	SingleListIntElement *next;
	int value;
};

SingleListIntElement *createSingleListIntElement(int value);
void deleteSingleListIntElement(SingleListIntElement *element);
void prsingle_listIntElement(SingleListIntElement *element);

typedef struct tagsingle_list {
	SingleListIntElement *head;
} single_list;

single_list *create_single_list(void);
void deletesingle_list(single_list *list);

void printsingle_list(single_list *list);

long countOfsingle_list(single_list *list);

void removeLastElementFromsingle_list(single_list *list);
void removeFirstElementFromsingle_list(single_list *list);
// 1: success, 0 - fail
int addIntValueTosingle_list(single_list *list, int value);
int removeIntElementFromsingle_listAtIndex(single_list *list, int index);
float findAverageFromsingle_list(single_list *list);

#endif //MAIN_C_
