#include "figure.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point {
    double x, y;
};

struct Triangle {
    struct Point a, b, c;
};

double getArea(struct Triangle *t) {
    double a = t->a.x - t->c.x;
    double b = t->a.y - t->c.y;
    double c = t->b.x - t->c.x;
    double d = t->b.y - t->c.y;
    return fabs(a * d - b * c) / 2;
}

void freeTriangle(struct Triangle *triangle) {
    free(triangle);
}

struct Triangle* createTriangle(double ax, double ay, double bx, double by, double cx, double cy) {
    struct Triangle *t = (struct Triangle*)malloc(sizeof(struct Triangle));
    t->a.x = ax;
    t->a.y = ay;
    t->b.x = bx;
    t->b.y = by;
    t->c.x = cx;
    t->c.y = cy;
    if (getArea(t) < 1e-5) {
        free(t);
        return NULL;
    }
    return t;
}

void printTriangle(struct Triangle *t) {
    if (t == NULL) {
        printf("Invalid triangle(or it was not created)\n");
        return;
    }
    printf("Triangle (%.2f; %.2f), (%.2f; %.2f), (%.2f; %.2f)\n", t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y);
    printf("Area: %.4f\n", getArea(t));
}
