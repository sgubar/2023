#ifndef triangle_h
#define triangle_h

#include <stdio.h>

typedef struct tagPoint
{
        int x;
        int y;
} Point;

typedef struct tagLine
{
        Point *A;
        Point *B;
} Line;

void make_triangle(Point *a, Point *b, Point *c);

Point *create_point(int x, int y);

Point *copy_Point(Point *a);

void destroy_point(Point *a);

void print_point(Point *a);

Line *create_line(int ax, int ay, int bx, int by);

Line *createLineByPoints(Point *anA, Point *aB);

void print_line(Line *aLine);

double length_line(Line *aLine);

int validation(Point *a, Point *b, Point *c);

void destroy_line(Line *aLine);


#endif //triangle_h
