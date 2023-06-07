#include "m.h"
int main(void)
{
	int a = 0, b = 0 ,c = 0;
	printf("Enter A, B, C: ");
	scanf("%d%d%d", &a, &b, &c);
	if (c == 0) {
		printf("Error: can't div by zero\n");
		return 1;
	}
	float result =  ((float)modulus(a, b, c) / (float)mul(c)) * suma(a);  
	printf("Result: %f;\n", result);

	return 0;
}
