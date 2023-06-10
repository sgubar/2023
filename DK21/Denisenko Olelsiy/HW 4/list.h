#ifndef list_h
#define list_h

#include <stdio.h>

typedef struct tagFloatListElement {
	float value;
	struct tagFloatListElement *prev;
	struct tagFloatListElement*next;
} FloatListElement;

FloatListElement *createFloatListElement(float value);
void deleteFloatListElement(FloatListElement *element);
void printFloatListElement(FloatListElement *element);

typedef struct tagFloatList {
	FloatListElement *head;
	FloatListElement *tail;
} FloatList;

FloatList *createFloatList(void);
void deleteFloatList(FloatList *list);

void printFloatList(FloatList *list);

long countOfFloatList(FloatList *list);
// 1: success, 0 - fail
int addFloatValueToFloatList(FloatList *list, float value);
void removeLastElementFromFloatList(FloatList *list);
void removeFirstElementFromFloatList(FloatList *list);

// 1: success, 0 - fail
int insertFloatElementToFloatListAtIndex(FloatList *list, int index, float value);
// 1: success, 0 - fail
int removeFloatElementFromFloatListAtIndex(FloatList *list, int index);


#endif /* list_h */
