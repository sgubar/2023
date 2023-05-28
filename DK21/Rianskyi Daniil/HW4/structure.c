#include <stdio.h>
#include <stdlib.h>

#include "structure.h"

Rectangle* createRectangle(Point p1, Point p2, Point p3, Point p4) {
    Rectangle* rect = (Rectangle*)malloc(sizeof(Rectangle));
    rect->points[0] = p1;
    rect->points[1] = p2;
    rect->points[2] = p3;
    rect->points[3] = p4;
    return rect;
}

float calculateArea(Rectangle* rect) {
    float width = rect->points[1].x - rect->points[0].x;
    float height = rect->points[2].y - rect->points[0].y;
    return width * height;
}

void destroyRectangle(Rectangle* rect) {
    free(rect);
}

void printRectangle(Rectangle* rect) {
    for (int i = 0; i < 4; i++) {
        printf("Point %d: (%.2f, %.2f)\n", i + 1, rect->points[i].x, rect->points[i].y);
    }
}

void sumPoints(Rectangle* rect) {
    int count = 0;
    int usedPoints[4] = {0}; // Масив для відстеження використовуваних точок
    
    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            if (rect->points[i].x == rect->points[j].x && rect->points[i].y == rect->points[j].y) {
                // Якщо точки співпадають, відзначаємо їх як використані
                usedPoints[i] = 1;
                usedPoints[j] = 1;
            }
        }
    }
    
    // Підраховуємо кількість використовуваних точок
    for (int i = 0; i < 4; i++) {
        if (usedPoints[i] == 1) {
            count++;
        }
    }
    
    printf("Number of used points: %d\n", count);
}
