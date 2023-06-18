#include "array.h"
#include <stdio.h>
#include <stdlib.h>

struct TriangleArray {
    struct Triangle **arr;
    int count;
    int capacity;
};

struct TriangleArray* createTriangleArray(int capacity) {
    struct TriangleArray *arr = (struct TriangleArray*)malloc(sizeof(struct TriangleArray));
    arr->arr = NULL;
    arr->count = arr->capacity = 0;
    if (capacity <= 0)
        return arr;
    arr->arr = (struct Triangle**)malloc(sizeof(struct Triangle*) * capacity);
    arr->count = 0;
    arr->capacity = capacity;
    return arr;
}

void freeTriangleArray(struct TriangleArray *a) {
    if (a == NULL || a->arr == NULL)
        return;
    free(a->arr);
    free(a);
}

void increaseCapacity(struct TriangleArray *a) {
    if (a == NULL || a->capacity >= a->count + 1)
        return;
    int newCapacity = a->capacity == 0 ? 10 : a->capacity * 2;
    struct Triangle** arr = (struct Triangle**)malloc(sizeof(struct Triangle*) * newCapacity);
    for (int i = 0; i < a->count; i++)
        arr[i] = a->arr[i];
    free(a->arr);
    a->arr = arr;
    a->capacity = newCapacity;
}

int addTriangleArray(struct TriangleArray *a, struct Triangle *t) {
    if (a == NULL)
        return -1;
    int last = a->count;
    increaseCapacity(a);
    a->arr[last] = t;
    a->count = last + 1;
    return last;
}

int insertTriangleArray(struct TriangleArray *a, struct Triangle *t, int index) {
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

void printTriangleArray(struct TriangleArray *a) {
    for (int i = 0; i < a->count; i++) {
        printf("%d\n", i + 1);
        printTriangle(a->arr[i]);
    }
}

int getCount(struct TriangleArray *a) {
    return a->count;
}
struct Triangle* getItem(struct TriangleArray *a, int i) {
    return a->arr[i];
}

void setItem(struct TriangleArray *a, int i, struct Triangle *t) {
    a->arr[i] = t;
}
