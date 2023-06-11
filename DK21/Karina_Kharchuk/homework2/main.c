#include <stdio.h>
#include "triangle.h"

int main (int argc, const char *argv[])
{
        printf("ab і ас є катетами, а bc - гіпотенуза\n");
	
	Point *a = create_point(1, 1);
	Point *b = create_point(1, 5);
	Point *c = create_point(5, 1);

	make_triangle(a, b, c);

	int val = validation(a, b, c);

	destroy_triangle(a, b, c);

	return 0;
}
