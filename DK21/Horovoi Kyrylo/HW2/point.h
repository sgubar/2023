#ifndef POINT_H_INCLUDED
#define POINT_H_INCLUDED

#include <stdio.h>

typedef struct tagPoint {
	int x;
	int y;
} Point;

Point *createPoint(int x, int y);
void destroyPoint(Point *aPoint);
void printPoint(Point *aPoint);

#endif // POINT_H_INCLUDED
