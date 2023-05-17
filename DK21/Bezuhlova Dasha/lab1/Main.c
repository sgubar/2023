#include<stdio.h>
#include <stdlib.h>
#include "Math.h"
#include "dk_tools.h" 

int main(int argc, const char* argv[]) {

    int A = get_dodint("¬вед≥ть значенн€ дл€ A:");
    printf("B:");
    int B = get_int();
    printf("C:");
    int C = get_int();
    printf("%f", q(A, B, C));
    return 0;

}