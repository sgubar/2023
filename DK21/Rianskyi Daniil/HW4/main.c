#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main() {

    Point p1 = {0.0, 0.0};
    Point p2 = {2.0, 0.0};
    Point p3 = {8.0, 6.0};
    Point p4 = {0.0, 9.0};

    Rectangle* rect = createRectangle(p1, p2, p3, p4);

    float area = calculateArea(rect);
    printf("Area: %.2f\n", area);

    printRectangle(rect);

    destroyRectangle(rect);

    sumPoints(rect);

    return 0;
}
