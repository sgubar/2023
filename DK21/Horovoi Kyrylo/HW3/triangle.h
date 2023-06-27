#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "point.h"
#include <stdbool.h>

typedef struct tagTriangle{
    Point* points[3];
}Triangle;

Triangle *createTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
Triangle *createTriangleByPoints(Point *A, Point *B, Point *C);
void destroyTriangle(Triangle *aTriangle);
void printTriangle(Triangle *aTriangle);
Triangle *createTriangleByArray(Point** points);
bool IsRightTriangle(Triangle *aTriangle);
double AreaOfRightTriangle(Triangle *aTriangle);
#endif // TRIANGLE_H_INCLUDED
