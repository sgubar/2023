#include "point.h"
#include <stdlib.h>
#include "triangle.h"
#include "line.h"
#include <stdbool.h>
#include <math.h>

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
bool IsRightTriangle(Triangle *aTriangle)
{
    double AB = segmentLength(aTriangle->points[0], aTriangle->points[1]), BC = segmentLength(aTriangle->points[1], aTriangle->points[2]), AC = segmentLength(aTriangle->points[0], aTriangle->points[2]);
    if(AB==AC || BC==AB || AC==BC) return false;
    else if(pow(AB, 2)== pow(BC, 2) + pow(AC, 2)) return true;
    else if(pow(BC, 2)== pow(AB, 2) + pow(AC, 2)) return true;
    else if(pow(AC, 2)== pow(BC, 2) + pow(AB, 2)) return true;
    else return false;
}
double AreaOfRightTriangle(Triangle *aTriangle)
{
    double AB = segmentLength(aTriangle->points[0], aTriangle->points[1]), BC = segmentLength(aTriangle->points[1], aTriangle->points[2]), AC = segmentLength(aTriangle->points[0], aTriangle->points[2]);
    if(IsRightTriangle(aTriangle)== false)
        return -1;
    double cat1, cat2;
    if(AB>BC && AB>AC)
    {
        cat1=BC;
        cat2=AC;
    }
    else if(BC>AB && BC>AC)
    {
        cat1=AB;
        cat2=AC;
    }
    else
    {
        cat1=BC;
        cat2=AB;
    }
    return (cat1*cat2)/2;
}

