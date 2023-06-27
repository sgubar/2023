#ifndef ARRAYTRIANGLE_H_INCLUDED
#define ARRAYTRIANGLE_H_INCLUDED
#include <stdio.h>
#include "triangle.h"

typedef struct tagArryOfTriangles {
	Triangle **storage;
	int preservedCount;
	int count;
} ArrayOfTriangles;

ArrayOfTriangles *createArrayOfTriangles(int aReserved);
void destroyArrayOfTriangles(ArrayOfTriangles *anArray);

int addTriangle(ArrayOfTriangles *anArray, Triangle *aTriangle);
int addTriangleByCords(ArrayOfTriangles *anArray, int x1, int y1, int x2, int y2, int x3, int y3);
int addTriangleAtIndex(ArrayOfTriangles *anArray, Triangle *aTriangle, int index);
Triangle *getTriangleAt(ArrayOfTriangles *anArray, int aIndex);

void printArrayOfTriangles(ArrayOfTriangles *anArray);
int countArrayOfTriangles(ArrayOfTriangles *anArray);
int extendArrayOfTriangles(ArrayOfTriangles *anArray);


#endif // ARRAYTRIANGLE_H_INCLUDED
