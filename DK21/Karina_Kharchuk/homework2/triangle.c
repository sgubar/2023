#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "triangle.h"

double length_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return -1;
        }
        return sqrt((aLine->B->x - aLine->A->x) * (aLine->B->x - aLine->A->x) + (aLine->B->y - aLine->A->y) * (aLine->B->y - aLine->A->y));

}

Point *create_point(int x, int y)
{
        Point *result = (Point *)malloc(sizeof(Point));
        if(NULL != result)
        {
                result->x = x;
                result->y = y;
        }

 }

void print_point(Point *aPoint)
 {
        if(NULL == aPoint)
        {
                printf("Invalid object");
                return;
        }

  printf("{%d, %d}", aPoint->x, aPoint->y);
 }

void destroy_point(Point *a) 
{
        if (NULL != a) 
        {
                free(a);
        }
}

void make_triangle(Point *a, Point *b, Point *c)
{
	Line *bc = createLineByPoints(b, c);
	printf("length bc: %f\n", length_line(bc));
	print_line(bc);

	Line *ca = createLineByPoints(c, a);
	printf("length ca: %f\n", length_line(ca));
        print_line(ca);

	Line *ab = createLineByPoints(a, b);
        printf("length ab: %f\n", length_line(ab));
        print_line(ab);

	printf("площа трикутника: %f\n", (length_line(ab)*length_line(ca))/2);

	for (int i = 1; i <= length_line(ab); ++i)
        {
                for (int j = 1; j <= i; ++j)
                {
                        printf("* ");
                }
                printf("\n");
        }

	return;
}

Line *create_line(int ax, int ay, int bx, int by)
{
        Line *result = (Line *)malloc(sizeof(Line));

        if(NULL != result)
        {
                result->A = create_point(ax, ay);
                result->B = create_point(bx, by);
        }

        return result;
}

Line *createLineByPoints(Point *anA, Point *aB)
{
        if (NULL == anA || NULL == aB)
        {
                return NULL;
        }

        return create_line(anA->x, anA->y, aB->x, aB->y);
}
void print_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return;
        }

        print_point(aLine->A);
        printf("-");
        print_point(aLine->B);
        printf("\n");
}

int validation(Point *a, Point *b, Point *c)
{
	Line *bc = createLineByPoints(b, c);
	Line *ca = createLineByPoints(c, a);
	Line *ab = createLineByPoints(a, b);
	
        if(length_line(ab) >= length_line(bc) || length_line(ca) >= length_line(bc))
        {
                printf("гіпотенуза не може бути більшою ніж катет\n");
                return 0;
        }
        return 1;
}

void destroy_line(Line *aLine)
{
        if(NULL == aLine)
        {
                return;
        }

        destroy_point(aLine->A);
        destroy_point(aLine->B);

        free(aLine);
}
