#include "square.h"
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

Color_s* createColor(float R, float G, float B) {
	Color_s* color = (Color_s*)malloc(sizeof(Color_s));

	if (color != NULL) {
		color->R = R;
		color->G = G;
		color->B = B;
	}

	return color;
}

void deleteColor(Color_s* color) {
	if (NULL != color) {
		free(color);
	}
}

int min(int a, int b) {
	return (a < b) ? a : b;
}

int max(int a, int b) {
	return (a > b) ? a : b;
}

Square_s* createSquare(Point** points, Color_s* color) { //input of Square by points of diagonal
	if (points[0]->x == points[1]->x || points[0]->y == points[1]->y) { //bad input
		return NULL;
	}

	Square_s* aSquare = (Square_s*)malloc(sizeof(Square_s));

	if (aSquare != NULL) {
		aSquare->points[0] = createPoint(min(points[0]->x, points[1]->x), min(points[0]->y, points[1]->y));
		aSquare->points[1] = createPoint(max(points[0]->x, points[1]->x), min(points[0]->y, points[1]->y));
		aSquare->points[2] = createPoint(max(points[0]->x, points[1]->x), max(points[0]->y, points[1]->y));
		aSquare->points[3] = createPoint(min(points[0]->x, points[1]->x), max(points[0]->y, points[1]->y));

		aSquare->color = color;
	}

	return aSquare;
}

void deleteSquare(Square_s* aSquare) {
	if (NULL != aSquare) {
		for (int i = 0; i < PT_NUM; i++) {
			destroyPoint(aSquare->points[i]);
		}
		deleteColor(aSquare->color);
	}

	free(aSquare);
}


void drawSquare(Square_s* aSquare) {
	
	glBegin(GL_QUADS);
	
	glColor3f(aSquare->color->R, aSquare->color->G, aSquare->color->B);

	glVertex2f(aSquare->points[0]->x / 100.0f, aSquare->points[0]->y / 100.0f);
	glVertex2f(aSquare->points[1]->x / 100.0f, aSquare->points[1]->y / 100.0f);
	glVertex2f(aSquare->points[2]->x / 100.0f, aSquare->points[2]->y / 100.0f);
	glVertex2f(aSquare->points[3]->x / 100.0f, aSquare->points[3]->y / 100.0f);
	
	glEnd();
}


SquareListElement_s* createListElement(Square_s* aSquare) {
	SquareListElement_s* result = (SquareListElement_s*)malloc(sizeof(SquareListElement_s));

	if (NULL != result) {
		result->figure = aSquare;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteListElement(SquareListElement_s* listElement) {
	if (NULL != listElement) {
		deleteSquare(listElement->figure);
		free(listElement);
	}
}

void drawListElement(SquareListElement_s* listElement) {
	if (NULL != listElement) {
		drawSquare(listElement->figure);
	}
}



SquareList_s* createSquareList(void) {
	SquareList_s* result = (SquareList_s*)malloc(sizeof(SquareList_s));

	if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void deleteSquareList(SquareList_s* list) {
	if (NULL == list) {
		return;
	}

	SquareListElement_s* element = list->head;

	while (NULL != element) {
		SquareListElement_s* tmp = element->next;
		deleteListElement(element);
		element = tmp;
	}

	free(list);
}

void drawSquareList(SquareList_s* list) {

	if (NULL == list) {
		return;
	}

	SquareListElement_s* element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		drawListElement(element);
	}

	if (element != NULL) {
		drawListElement(element);
	}
}

long countOfSquareList(SquareList_s* list) {
	if (NULL == list) {
		return 0;
	}

	long count = 0;

	for (SquareListElement_s* element = list->head; element != NULL; element = element->next, count++);

	return count;
}

int addSquareToSquareList(SquareList_s* list, Square_s* figure) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	SquareListElement_s* element = createListElement(figure);
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

void removeLastElementFromSquareList(SquareList_s* list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	// is single element list?
	if (list->head == list->tail) {
		deleteListElement(list->head);
		list->head = NULL;
		list->tail = NULL;
		return;
	}

	SquareListElement_s* toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteListElement(toDelete);
}

void removeFirstElementFromSquareList(SquareList_s* list) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return;
	}

	if (NULL == list->head) {
		return;
	}

	if (list->head == list->tail) {
		deleteListElement(list->head);
		list->head = list->tail = NULL;
		return;
	}

	SquareListElement_s* toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteListElement(toDelete);
}

int insertSquareToSquareListAtIndex(SquareList_s* list, int index, Square_s* aSquare) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	long count = countOfSquareList(list);

	if (count == index) {
		return addSquareToSquareList(list, aSquare);
	}
	else if (index > count) {
		return 0;
	}

	SquareListElement_s* element = createListElement(aSquare);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	}
	else {
		int current = 0;
		SquareListElement_s* ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeSquareFromSquareListAtIndex(SquareList_s* list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
		return 0;
	}

	long count = countOfSquareList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromSquareList(list);
		return 1;
	}
	else if (index == (count - 1)) {
		removeLastElementFromSquareList(list);
		return 1;
	}
	else {
		int current = 0;
		SquareListElement_s* ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteListElement(ex_element);
	}

	return 1;
}
