#include "math.h"

int part3(int a, int d)
{
	int n = 1;
	for (int i = 1; i <= a + d; ++i) {
		n *= 2;

	}
	return n;
}
int part2(int a)
{
	int n = 1;
	int result = 0;
	for (int d = 0; d <= a; ++d) {
		result += part3(a, d);
	}
	return result;
}

