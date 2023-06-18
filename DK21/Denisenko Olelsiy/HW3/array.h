#include "figure.h"

struct TriangleArray;

struct TriangleArray* createTriangleArray(int capacity);
void freeTriangleArray(struct TriangleArray *a);
void increaseCapacity(struct TriangleArray *a);
int addTriangleArray(struct TriangleArray *a, struct Triangle *t);
int insertTriangleArray(struct TriangleArray *a, struct Triangle *t, int index);
void printTriangleArray(struct TriangleArray *a);
int getCount(struct TriangleArray *a);
struct Triangle* getItem(struct TriangleArray *a, int i);
void setItem(struct TriangleArray *a, int i, struct Triangle *t);
