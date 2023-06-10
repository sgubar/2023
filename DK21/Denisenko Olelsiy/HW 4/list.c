#include "list.h"
#include <stdlib.h>
#include <string.h>

FloatListElement *createFloatListElement(float value) {
	FloatListElement *ListPtr = malloc(sizeof(*ListPtr));

	if (NULL != ListPtr) {
		bzero(ListPtr, sizeof(FloatListElement));
		ListPtr->value = value;
		ListPtr->next = NULL;
		ListPtr->prev = NULL;
	}

	return ListPtr;
}

void deleteFloatListElement(FloatListElement *element) {
	if (NULL != element) {
		free(element);
	}
}

void printFloatListElement(FloatListElement *element) {
	if (NULL != element) {
		printf("%0.2f", element->value);
	}
}

FloatList *createFloatList(void) {
	FloatList *ListPtr = malloc(sizeof(*ListPtr));

	if (NULL != ListPtr) {
		ListPtr->head = NULL;
		ListPtr->tail = NULL;
		memset(ListPtr, 0, sizeof(FloatList));
	}

	return ListPtr;
}

void deleteFloatList(FloatList *list) {
	if (NULL == list) {
		return ;
	}

	FloatListElement *element = list->head;

	while(NULL != element) {
		FloatListElement *tmp = element->next;
		deleteFloatListElement(element);
		element = tmp;
	}

	free(list);
}

void printFloatList(FloatList *list) {

	if (NULL == list) {
		printf("Invalid a pointer to the list\n");
		return;
	}

	printf("[");

	FloatListElement *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		printFloatListElement(element);
		printf(",");
	}

	if (element != NULL) {
		printFloatListElement(element);
	}

	printf("]\n");
}

long countOfFloatList(FloatList *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (FloatListElement *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addFloatValueToFloatList(FloatList *list, float value) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	FloatListElement *element = createFloatListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (NULL == list->head) {
		list->head = element;
		list->tail = list->head;
		return 1;
	}

	list->tail->next = element;
	element->prev = list->tail;
	list->tail = element;

	return 1;
}

void removeLastElementFromFloatList(FloatList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	// is single element list?
	if (list->head == list->tail) {
		deleteFloatListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	FloatListElement *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteFloatListElement(toDelete);
}

void removeFirstElementFromFloatList(FloatList *list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteFloatListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	FloatListElement *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteFloatListElement(toDelete);
}

int insertFloatElementToFloatListAtIndex(FloatList *list, int index, float value) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfFloatList(list);

	if (count == index) {
		return addFloatValueToFloatList(list, value);
	} else if (index > count) {
		return 0;
	}

	FloatListElement *element = createFloatListElement(value);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		FloatListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeFloatElementFromFloatListAtIndex(FloatList *list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfFloatList(list);
	if (index >= count) {
		return 0;
	}

	if (index == 0) {
		removeFirstElementFromFloatList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromFloatList(list);
		return 1;
	} else {
		int current = 0;
		FloatListElement *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteFloatListElement(ex_element);
	}
	return 1;
}
