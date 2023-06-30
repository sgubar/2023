#ifndef line_h
#define line_h
#include<stdint.h>
#include"point.h"
typedef struct TagLine {
	Point* A;
	Point* B;
}Line;
Line* CreateLine(int ax, int ay, int bx, int by);
void DeleteLine(Line* aLine);
void PrintLine(Line* aLine);
double LengthLine(Line* aLine);
#endif