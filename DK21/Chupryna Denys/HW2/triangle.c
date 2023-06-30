#include"triangle.h"
#include"point.h"
#include"line.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>


Triangle *CreateTriangle(int ax, int ay, int bx, int by, int cx, int cy)
{
	Triangle *result = (malloc(sizeof(Triangle)));
	if (NULL != result)
	{
		result->A = CreatePoint(ax, ay);
		result->B = CreatePoint(bx, by);
		result->C = CreatePoint(cx, cy);
	}
	return result;
}

void PrintTriangle(Triangle *aTriangle)
{
	if (NULL == aTriangle)
	{
		return;
	}
	printf("A:");
	PrintPoint(aTriangle->A);
	printf("B:");
	PrintPoint(aTriangle->B);
	printf("C:");
	PrintPoint(aTriangle->C);
	printf("\n");

}


void DeleteTriangle(Triangle *aTriangle)
{
	if (NULL == aTriangle)
	{
		return;
	}
	DeletePoint(aTriangle->A);
	DeletePoint(aTriangle->B);
	DeletePoint(aTriangle->C);
	free(aTriangle);

}
double Area(Triangle* aTriangle)
{

	Line *A= CreateLine(aTriangle->A->x, aTriangle->A->y, aTriangle->B->x, aTriangle->B->y);
	double al = LengthLine(A);
	
	Line* B = CreateLine(aTriangle->B->x, aTriangle->B->y, aTriangle->C->x, aTriangle->C->y);
	double bl = LengthLine(B);
	
	Line* C = CreateLine(aTriangle->C->x, aTriangle->C->y, aTriangle->A->x, aTriangle->A->y);
	double cl = LengthLine(C);
	double per = al + bl + cl;
	
	return sqrt(per * (per-al) * (per-bl) * (per-cl));
}