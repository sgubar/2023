#ifndef triangle_h
#define triangle_h
#include<stdint.h>
#include"point.h"
#include"line.h"
typedef struct TagTriangle {
	Point *A;
	Point *B;
	Point *C;
}Triangle;


Triangle* CreateTriangle(int ax, int ay, int bx, int by, int cx, int cy);
void PrintTriangle(Triangle *aTriangle);
void DeleteTriangle(Triangle* aTriangle);
double Area(Triangle* aTriangle);
#endif