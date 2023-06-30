#include"point.h"
#include<stdlib.h>
#include<stdio.h>

Point *CreatePoint(int x, int y) 
{
	Point *result= (malloc(sizeof(Point)));
	if (NULL != result)
	{
		result->x = x;
		result->y = y;
	}
	return result;
}

void DeletePoint(Point *aPoint)
{
	if (NULL != aPoint)
	{
		free(aPoint);
	}
}

void PrintPoint(Point *aPoint)
{
	if (NULL == aPoint)
	{
		printf("Invalid point");
		return;
	}
	printf("{%d, %d}", aPoint->x, aPoint->y);
}