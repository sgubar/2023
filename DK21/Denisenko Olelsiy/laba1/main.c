#include <stdio.h>
#include <stdlib.h>

int getFactorial(int number){

    if(number < 0){
        printf("The nuber A is wrong!");
        return -1;
    }

    int factorial = 1;

    for(int i = 1; i <= number;i++){
      factorial *= i;
    }

    return factorial;
}

int main()
{
    int A;
    int B;
    double result;

    printf("Enter the number A (the number must be bigger than 0 and whole): ");
    scanf("%d",&A);
    printf("Enter the number B (the number mustn't equal 2*A ): ");
    scanf("%d",&B);

    int factorialOfA = getFactorial(A);
    int denominator = abs(2*A+B);

    if(denominator == 0){
        printf("The nuber B is wrong!");
        return 0;
    }

    printf("%d! / |2*%d+%d| \n", A, A, B);
    result = (double) factorialOfA/denominator;
    printf("Q <- %f", result);
    return 0;
}
