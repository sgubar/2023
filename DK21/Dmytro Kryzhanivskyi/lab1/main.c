#include <stdio.h>
#include "math.h"
int main(void)
{

	int a = 0, b = 0, c = 0;
	scanf("%d%d%d", &a, &b, &c);
	if (100 - b - c == 0) {
		fprintf(stderr, "Error: cannot be divided by 0 \n");
		return 1;

	}
	float result = (float)(a + b + c) / (float)(100 - b - c) + part2(a); 
	printf("%f", result);
	return 0;
}
