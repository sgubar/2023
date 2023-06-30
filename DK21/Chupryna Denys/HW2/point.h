#ifndef point_h
#define point_h
#include<stdio.h>

typedef struct TagPoint {
	int x;
	int y;
}Point;

Point* CreatePoint(int x, int y);
void DeletePoint(Point *aPoint);
void PrintPoint(Point *aPoint);

#endif // !point_h
