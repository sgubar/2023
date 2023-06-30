#include"line.h"
#include"point.h"
#include<math.h>
#include<stdlib.h>
#include<stdio.h>

Line* CreateLine(int ax, int ay, int bx, int by)
{
	Line* result = (malloc(sizeof(Line)));
	if (NULL != result)
	{
		result->A = CreatePoint(ax, ay);
		result->B = CreatePoint(bx, by);
	}
	return result;
}
void DeleteLine(Line* aLine)
{
	if (NULL == aLine)
	{
		return;
	}
	DeletePoint(aLine->A);
	DeletePoint(aLine->B);
	free(aLine);

}
void PrintLine(Line* aLine)
{
	if (NULL == aLine)
	{
		return;
	}
	PrintPoint(aLine->A);
	printf("-");
	PrintPoint(aLine->B);
	printf("\n");

}
double LengthLine(Line* aLine)
{
	if (NULL == aLine)
	{
		return -1;
	}
	return sqrt((aLine->B->x - aLine->A->x) * (aLine->B->x - aLine->A->x) + (aLine->B->y - aLine->A->y) * (aLine->B->y - aLine->A->y));
}