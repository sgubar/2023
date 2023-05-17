#include <stdio.h>
#include <stdlib.h>

double power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}


int main(void) {
    int A, B, C;
    printf("Enter A (integer): ");
    if (scanf("%d", &A) != 1) {
        printf("Error: Invalid input for A.\n");
        exit(1);
    }
    printf("Enter B (non-negative integer): ");
    if (scanf("%d", &B) != 1) {
        printf("Error: Invalid input for B.\n");
        exit(1);
    }
    printf("Enter C (non-negative integer): ");
    if (scanf("%d", &C) != 1) {
        printf("Error: Invalid input for C.\n");
        exit(1);
    }

    // Check for invalid values
    if (B + 5 * power(C, 2) == 0) {
        printf("Error: Denominator cannot be zero.\n");
        exit(1);
    }
    if (B < 0 || C < 0) {
        printf("Error: B and C must be non-negative.\n");
        exit(1);
    }
    double Q = (power(A, 2) + power(B, 2)) / (B + power(5, C)) + factorial(B);
    printf("Q = %lf\n", Q);
    return 0;
}
