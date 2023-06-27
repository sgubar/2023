#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#define MOD(n) (n<0 ? -n : n)

double formula(int D, int B)
{
    return exponentiate(2, D + B);
}
double exponentiate(int dig, int degree)
{
    int result = 1;
    for (int i = 0; i < MOD(degree); i++)
    {
        result *= dig;
    }

    return (double)(degree < 0 ? 1 / result : result);
}
double sum_exp(double (*func)(int, int), int start, int finish)
{
    double result = 0;
    for (int i = start; i <= finish; i++)
    {
        result += func(i, finish);
    }
    return result;
}