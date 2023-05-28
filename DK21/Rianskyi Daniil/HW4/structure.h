#ifndef structure_h
#define structure_h
typedef struct {
    float x;
    float y;
} Point;

typedef struct {
    Point points[4];
} Rectangle;

Rectangle* createRectangle(Point p1, Point p2, Point p3, Point p4);
float calculateArea(Rectangle* rect);
void destroyRectangle(Rectangle* rect);
void printRectangle(Rectangle* rect);
void sumPoints(Rectangle* rect);
#endif
