#include "point.h"
#include <stdlib.h>
#include "triangle.h"
#include "line.h"

Triangle *createTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    Triangle *result = (Triangle*)malloc(sizeof(Triangle));
    if(result!=NULL){
        result->points[0] = createPoint(x1, y1);
        result->points[1] = createPoint(x2, y2);
        result->points[2] = createPoint(x3, y3);

    }
    return result;
}
Triangle *createTriangleByPoints(Point *A, Point *B, Point *C)
{
    if(A == NULL, B == NULL, C == NULL)
    {
        return NULL;
    }
    return createTriangle(A->x, A->y, B->x, B->y, C->x, C->y);
}

void destroyTriangle(Triangle *aTriangle)
{
    if(aTriangle==NULL)
    {
        return;
    }
    for(int i = 0; i<3; i++)
    {
        destroyPoint(aTriangle->points[i]);
    }
    free(aTriangle);
}
void printTriangle(Triangle *aTriangle)
{
    printf("Трикутник будується на таких точках:");
    for(int i = 0; i<3; i++)
    {
        printPoint(aTriangle->points[i]);
    }
}

Triangle *createTriangleByArray(Point** points)
{
    Triangle *result = (Triangle*)malloc(sizeof(Triangle));
    if(result !=NULL)
    {
        for(int i =0; i<3; i++)
        {
            result->points[i]=createPoint(points[i]->x, points[i]->y);
        }
    }
    return result;
}
double TrianglePerimeter(Triangle *aTriangle)
{
    double p=0;
    Line *Line;
    for(int i =0; i<3; i++)
    {
        Line=createLineByPoints(aTriangle->points[i], aTriangle->points[i+1]);
        p+=lenghtLine(Line);
        destroyLine(Line);
    }
    Line=createLineByPoints(aTriangle->points[0], aTriangle->[2]);
    p+=lenghtLine(Line);
    destroyLine(Line);
    return p;
}
