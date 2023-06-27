#include <stdio.h>
#include "arraytriangle.h"
#include "triangle.h"

int main () {
    ArrayOfTriangles *arr = createArrayOfTriangles(5);
    Triangle *A = createTriangle(0, 4, 3, 0, 0, 0);

    addTriangleByCords(arr, 0, 3, 5, 5, 9, -4);
    addTriangleByCords(arr, 7, 4, 1, 5, 8, 7);
    printArrayOfTriangles(arr);
    addTriangleByCords(arr, 8, 1, 2, 7, -8, 4);
    addTriangleByCords(arr, 4, 0, 8, 2, 0, 7);
    addTriangle(arr, A);
    printArrayOfTriangles(arr);

    A = createTriangle(0, 1, 3, -1, 1, -4);
    printf("Вставка за 3-м індексом:\n");
    addTriangleAtIndex(arr, A, 3);
    printArrayOfTriangles(arr);

    A = createTriangle(-4, 1, 0, 1, -2, 4);
    printf("Вставка за 22-м індексом:\n");
    addTriangleAtIndex(arr, A, 22);

    printArrayOfTriangles(arr);
    destroyArrayOfTriangles(arr);
    destroyTriangle(A);
    return 0;
}
