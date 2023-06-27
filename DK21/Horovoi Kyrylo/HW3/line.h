#ifndef LINE_H_INCLUDED
#define LINE_H_INCLUDED
#include <stdio.h>
#include "point.h"

typedef struct tagLine {
	Point *A;
	Point *B;
} Line;

Line *createLine(int ax, int ay, int bx, int by);
Line *createLineByPoints(Point *anA, Point *aB);
void destroyLine(Line *aLine);

void printLine(Line *aLine);
double lenghtLine(Line *aLine);
double segmentLength(Point* first, Point* second);
#endif // LINE_H_INCLUDED
