int modulus(int a, int b, int c)
{
	int tmp = a * c - b;
	return  tmp < 0 ? tmp * (-1) : tmp;
}

int mul(int c)
{
	int n = 1;
	for (int i = 1; i <= c; ++i) {
		n = i * i * i;
	}
	return n;
}
int m(int k)
{
	int n = 1;
	return n << k;
}
int suma(int a) 
{
	int result = 0;
	for (int d = 0; d <= a; ++d) {
		result += m(d);
	}
	return result;
}
