#include <stdio.h>
#include "figure.h"

int main(void) {
    struct Triangle *triangles[3] = {
        createTriangle(0, 0, 0, 3, 4, 0),
        createTriangle(3, 3, 3, 8, 7, 3),
        createTriangle(-4, 0, 4, 0, 0, 3)
    };
    for (int i = 0; i < 3; i++) {
        printf("%d\n", i + 1);
        printTriangle(triangles[i]);
        freeTriangle(triangles[i]);
    }
}
