#include "Math.h"
#include<stdio.h>
#include <stdlib.h>

#define MOD(n) (n<0 ? -n : n) // (condition) ? <> : <>//
double power(int base, int pow) {
    double  result = 1;
    int pw = MOD(pow);
    for (int i = 0; i < pw; i++) {
        result *= base;

    }
    return (pow < 0) ? 1.0 / result : result;
}
long factorial(int number) {
    long result = 1;
    if (number < 0) {
        return -1;
    }
    for (int i = 1; i <= number; i++) {
        result *= i;
    }
    return result;
}
long sum_factor(int start, int finish) {
    long result = 0;
    for (int i = start; i < finish; i++) {
        result += factorial(i);
    }
    return result;
}
double q(int A, int B, int C) {

    if ((B + power(C, 2)) == 0) {
        printf("Не можна ділити на нуль\n");
        return -1;
    }
    return (double)(A * B) / (double)(B + power(C, 2)) + (double)sum_factor(0, B);
}