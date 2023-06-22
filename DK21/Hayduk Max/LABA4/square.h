#ifndef square_h
#define square_h

#include <stdio.h>
#include "point.h"

#define PT_NUM 4


typedef struct Color_s {
    float R;
    float G;
    float B;
} Color_s;

Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);



typedef struct tagSquare {
    Point* points[PT_NUM];
    Color_s* color;
} Square_s;

Square_s* createSquare(Point** points, Color_s* color);
void deleteSquare(Square_s* aSquare);
void drawSquare(Square_s* aSquare);



typedef struct SquareListElement_s SquareListElement_s;
struct SquareListElement_s {
    SquareListElement_s* prev;
    SquareListElement_s* next;
    Square_s* figure;
};

SquareListElement_s* createListElement(Square_s* aSquare);
void deleteListElement(SquareListElement_s* listElement);
void drawListElement(SquareListElement_s* listElement);



typedef struct tagSquareList_s {
    SquareListElement_s* head;
    SquareListElement_s* tail;
} SquareList_s;

SquareList_s* createSquareList(void);
void deleteSquareList(SquareList_s* list);
void drawSquareList(SquareList_s* list);
long countOfSquareList(SquareList_s* list);
int addSquareToSquareList(SquareList_s* list, Square_s* aSquare); 
void removeLastElementFromSquareList(SquareList_s* list);
void removeFirstElementFromSquareList(SquareList_s* list);
int insertSquareToSquareListAtIndex(SquareList_s* list, int index, Square_s* aSquare); 
int removeSquareFromSquareListAtIndex(SquareList_s* list, int index); 
#endif
