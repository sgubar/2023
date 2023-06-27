#include<stdio.h>
#include"dk_tool.h"
#include"math.h"
int main(){
    printf("The code will calculate (A+B+C)/(100-B-C) + Σ(D=0->A)(2^(D+A))\nEnter only integer values \n");
    int A = get_inttext("A:");
    if (A <= 0)
    {
        printf("Incorrect value\n");
        return -1;
    }
    int B = get_inttext("B:");
    int C = get_inttext("C:");
    if (100 - B - C == 0)
    {
        printf("B-C cannot be equal to -100\n");
        return -1;
    }
    double Q = (double)(A + B + C) / (100 - B - C) + sum_exp(formula, 0, A);
    printf("%f", Q);
}