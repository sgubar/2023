#ifndef __FIGURE_H__
#define __FIGURE_H__

struct Point;

struct Triangle;

double getArea(struct Triangle *t);
void freeTriangle(struct Triangle *triangle);
struct Triangle* createTriangle(double ax, double ay, double bx, double by, double cx, double cy);
void printTriangle(struct Triangle *t);

#endif
