#include <stdio.h>
#include "array.h"
#include "figure.h"

int main(void) {
    struct TriangleArray *array = createTriangleArray(0);
    printf("Inserting 3 elements to array\n");
    addTriangleArray(array, createTriangle(0, 0, 0, 3, 4, 0));
    addTriangleArray(array, createTriangle(3, 3, 3, 8, 7, 3));
    addTriangleArray(array, createTriangle(-4, 0, 4, 0, 0, 3));
    printTriangleArray(array);
    printf("\n\nInserting 1 element to begin\n");
    insertTriangleArray(array, createTriangle(0, 0, 10, 10, 10, 0), 0);
    printTriangleArray(array);
    printf("\n\nInserting 1 element before end\n");
    insertTriangleArray(array, createTriangle(0, 0, 30, 30, 30, 0), getCount(array) - 1);
    printTriangleArray(array);
    for (int i = 0; i < getCount(array); i++)
        freeTriangle(getItem(array, i));
    freeTriangleArray(array);
    return 0;
}
