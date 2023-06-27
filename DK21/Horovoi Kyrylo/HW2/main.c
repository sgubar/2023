#include "point.h"
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"
#include "line.h"

int main(int argc, char* argv[])
{
    char k=65;
    Point* points[3];
    for(int i=0; i<3; i++, k++)
    {
        int x, y;
        printf("Координати точки %c\n", k);
        printf("x:"); scanf("%d", &x);
        printf("y:"); scanf("%d", &y);
        points[i]=createPoint(x, y);
    }
    Triangle *A=createTriangleByArray(points);
    if(IsRightTriangle(A) ==false)
    {
        printf("Трикутний не прямокутний або його не існує\n");
        destroyTriangle(A);
        return -1;
    }

    printTriangle(A);
    printf("Площа прямокутного трикутника: %f\n", AreaOfRightTriangle(A));
    destroyTriangle(A);
    for(int j=0; j<3; j++)
    {
        destroyPoint(points[j]);
    }
    Triangle *B=createTriangle(1, 13, 6, 1, 1, 1);
    printTriangle(B);
    printf("Площа другого прямокутного трикутника: %f\n", AreaOfRightTriangle(B));
    destroyTriangle(B);
}
