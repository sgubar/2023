#ifndef POINT_C_
#define POINT_C_

// Code for header body
#include <stdio.h>

typedef struct tagPoint {
	int x;
	int y;
} Point;

Point *createPoint(int x, int y);
void destroyPoint(Point *aPoint);
void printPoint(Point *aPoint);

#endif //POINT_C_