#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Point;

typedef struct {
    Point a, b, c;
} Triangle;

double getArea(Triangle *t) {
    double a = t->a.x - t->c.x;
    double b = t->a.y - t->c.y;
    double c = t->b.x - t->c.x;
    double d = t->b.y - t->c.y;
    return fabs(a * d - b * c) / 2;
}

void freeTriangle(Triangle *triangle) {
    free(triangle);
}

Triangle* createTriangle(double ax, double ay, double bx, double by, double cx, double cy) {
    Triangle *t = (Triangle*)malloc(sizeof(Triangle));
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

void printTriangle(Triangle *t) {
    if (t == NULL) {
        printf("Invalid triangle(or it was not created)\n");
        return;
    }
    printf("Triangle (%.2f; %.2f), (%.2f; %.2f), (%.2f; %.2f)\n", t->a.x, t->a.y, t->b.x, t->b.y, t->c.x, t->c.y);
    printf("Area: %.4f\n", getArea(t));
}

typedef struct {
    Triangle **arr;
    int count;
    int capacity;
} TriangleArray;

TriangleArray createTriangleArray(int capacity) {
    TriangleArray arr;
    arr.arr = NULL;
    arr.count = arr.capacity = 0;
    if (capacity <= 0)
        return arr;
    arr.arr = (Triangle**)malloc(sizeof(Triangle*) * capacity);
    arr.count = 0;
    arr.capacity = capacity;
    return arr;
}

void freeTriangleArray(TriangleArray *a) {
    if (a == NULL || a->arr == NULL)
        return;
    for (int i = 0; i < a->count; i++)
        free(a->arr[i]);
    free(a->arr);
    a->count = 0;
    a->capacity = 0;
}

void increaseCapacity(TriangleArray *a) {
    if (a == NULL || a->capacity >= a->count + 1)
        return;
    int newCapacity = a->capacity == 0 ? 10 : a->capacity * 2;
    Triangle** arr = (Triangle**)malloc(sizeof(Triangle*) * newCapacity);
    for (int i = 0; i < a->count; i++)
        arr[i] = a->arr[i];
    free(a->arr);
    a->arr = arr;
    a->capacity = newCapacity;
}

int addTriangleArray(TriangleArray *a, Triangle *t) {
    if (a == NULL)
        return -1;
    int last = a->count;
    increaseCapacity(a);
    a->arr[last] = t;
    a->count = last + 1;
    return last;
}

int insertTriangleArray(TriangleArray *a, Triangle *t, int index) {
    if (a == NULL)
        return -1;
    if (!(0 <= index && index <= a->count))
        return -1;
    increaseCapacity(a);
    int count = a->count;
    a->count++;
    for (int i = count; i > index; i--)
        a->arr[i] = a->arr[i-1];
    a->arr[index] = t;
    return index;
}

void printTriangleArray(TriangleArray a) {
    for (int i = 0; i < a.count; i++) {
        printf("%d\n", i + 1);
        printTriangle(a.arr[i]);
    }
}

int main(void) {
    TriangleArray array = createTriangleArray(0);
    printf("Inserting 3 elements to array\n");
    addTriangleArray(&array, createTriangle(0, 0, 0, 3, 4, 0));
    addTriangleArray(&array, createTriangle(3, 3, 3, 8, 7, 3));
    addTriangleArray(&array, createTriangle(-4, 0, 4, 0, 0, 3));
    printTriangleArray(array);
    printf("\n\nInserting 1 element to begin\n");
    insertTriangleArray(&array, createTriangle(0, 0, 10, 10, 10, 0), 0);
    printTriangleArray(array);
    printf("\n\nInserting 1 element before end\n");
    insertTriangleArray(&array, createTriangle(0, 0, 30, 30, 30, 0), array.count - 1);
    printTriangleArray(array);
    freeTriangleArray(&array);
    return 0;
}
