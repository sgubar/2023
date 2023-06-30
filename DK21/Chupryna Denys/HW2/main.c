#include"point.h"
#include"triangle.h"
#include"line.h"
#include<stdlib.h>
#include<stdio.h>

int main() 
{
	
	Triangle *ABC= CreateTriangle(1,2,3,4,5,6);

	PrintTriangle(ABC);

	double c = Area(ABC);

	printf("area:%f",c);

	DeleteTriangle(ABC);
	return 1;
}