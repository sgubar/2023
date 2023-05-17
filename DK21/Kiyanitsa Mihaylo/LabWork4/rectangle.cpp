#include "rectangle.h"
#include <stdlib.h>
#include <string.h>
#include <GL/glut.h>

Color_s* createColor(float R, float G, float B){
    Color_s* color = (Color_s *)malloc(sizeof(Color_s));

    if(color != NULL){
		color->R = R;
		color->G = G;
		color->B = B;
    }

    return color;
}

void deleteColor(Color_s *color) {
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

Rectangle_s* createRectangle(Point** points, Color_s * color){ //input of rectangle by points of diagonal
	if(points[0]->x == points[1]->x || points[0]->y == points[1]->y) { //bad input
		return NULL;
	}

    Rectangle_s* aRectangle = (Rectangle_s *)malloc(sizeof(Rectangle_s));

    if(aRectangle != NULL){
		aRectangle->points[0] = createPoint(min(points[0]->x, points[1]->x), min(points[0]->y, points[1]->y));
		aRectangle->points[1] = createPoint(max(points[0]->x, points[1]->x), min(points[0]->y, points[1]->y));
		aRectangle->points[2] = createPoint(max(points[0]->x, points[1]->x), max(points[0]->y, points[1]->y));
		aRectangle->points[3] = createPoint(min(points[0]->x, points[1]->x), max(points[0]->y, points[1]->y));

		aRectangle->color = color;
	}

    return aRectangle;
}

void deleteRectangle(Rectangle_s *aRectangle) {
	if (NULL != aRectangle) {
		for (int i = 0; i < PT_NUM; i++){
            destroyPoint(aRectangle->points[i]);
        }
        deleteColor(aRectangle->color);
	}

    free(aRectangle);
}


void drawRectangle(Rectangle_s* aRectangle){
    // Початок малювання примітиву
    glBegin(GL_QUADS);
        // Призначення кольору для примітиву
        glColor3f(aRectangle->color->R, aRectangle->color->G, aRectangle->color->B);
		
        // Призначення координат точкам примітиву
        glVertex2f(aRectangle->points[0]->x / 100.0f, aRectangle->points[0]->y / 100.0f);
        glVertex2f(aRectangle->points[1]->x / 100.0f, aRectangle->points[1]->y / 100.0f);
        glVertex2f(aRectangle->points[2]->x / 100.0f, aRectangle->points[2]->y / 100.0f);
        glVertex2f(aRectangle->points[3]->x / 100.0f, aRectangle->points[3]->y / 100.0f);
        // Кінець малювання примітиву
    glEnd();
}


RectangleListElement_s* createListElement(Rectangle_s* aRectangle) {
	RectangleListElement_s *result = (RectangleListElement_s *)malloc(sizeof(RectangleListElement_s));

	if (NULL != result) {
		result->figure = aRectangle;
		result->next = NULL;
		result->prev = NULL;
	}

	return result;
}

void deleteListElement(RectangleListElement_s* listElement) {
	if (NULL != listElement) {
		deleteRectangle(listElement->figure);
		free(listElement);
	}
}

void drawListElement(RectangleListElement_s* listElement) {
	if (NULL != listElement) {
		drawRectangle(listElement->figure);
	}
}



RectangleList_s *createRectangleList(void) {
	RectangleList_s *result = (RectangleList_s *)malloc(sizeof(RectangleList_s));

	if (NULL != result) {
		result->head = NULL;
		result->tail = NULL;
	}

	return result;
}

void deleteRectangleList(RectangleList_s *list) {
	if (NULL == list) {
		return ;
	}

	RectangleListElement_s *element = list->head;

	while(NULL != element) {
		RectangleListElement_s *tmp = element->next;
		deleteListElement(element);
		element = tmp;
	}

	free(list);
}

void drawRectangleList(RectangleList_s *list) {

	if (NULL == list) {
		return;
	}

	RectangleListElement_s *element = NULL;
	for (element = list->head; element != list->tail; element = element->next) {
		drawListElement(element);
	}

	if (element != NULL) {
		drawListElement(element);
	}
}

long countOfRectangleList(RectangleList_s *list) {
	if (NULL == list) {
 		return 0;
	}

	long count = 0;

	for (RectangleListElement_s *element = list->head; element != NULL; element = element->next, count ++);

	return count;
}

int addRectangleToRectangleList(RectangleList_s *list, Rectangle_s* figure) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	RectangleListElement_s *element = createListElement(figure);
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

void removeLastElementFromRectangleList(RectangleList_s *list) {
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

	RectangleListElement_s *toDelete = list->tail;
	list->tail = toDelete->prev;
	list->tail->next = NULL;

	deleteListElement(toDelete);
}

void removeFirstElementFromRectangleList(RectangleList_s *list) {
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

	RectangleListElement_s *toDelete = list->head;
	list->head = toDelete->next;
	list->head->prev = NULL;

	deleteListElement(toDelete);
}

int insertRectangleToRectangleListAtIndex(RectangleList_s *list, int index, Rectangle_s* aRectangle) {

	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfRectangleList(list);

	if (count == index) {
		return addRectangleToRectangleList(list, aRectangle);
	} else if (index > count) {
		return 0;
	}

	RectangleListElement_s *element = createListElement(aRectangle);
	if (NULL == element) {
		return 0;
	}

	if (0 == index) {
		element->next = list->head;
		list->head->prev = element;
		list->head = element;
	} else {
		int current = 0;
		RectangleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		element->next = ex_element;
		element->prev = ex_element->prev;
		ex_element->prev = element;
		element->prev->next = element;
	}

	return 1;
}

int removeRectangleFromRectangleListAtIndex(RectangleList_s *list, int index) {
	if (NULL == list || (list->head == NULL && list->head != list->tail)) {
 		return 0;
	}

	long count = countOfRectangleList(list);
	if (index >= count) {
		return 0;
	}

	if (0 == index) {
		removeFirstElementFromRectangleList(list);
		return 1;
	} else if (index == (count - 1)) {
		removeLastElementFromRectangleList(list);
		return 1;
	} else {
		int current = 0;
		RectangleListElement_s *ex_element = list->head;
		for (; ex_element != NULL && current != index; ex_element = ex_element->next, current ++);

		ex_element->prev->next = ex_element->next;
		ex_element->next->prev = ex_element->prev;

		deleteListElement(ex_element);
	}

	return 1;
}