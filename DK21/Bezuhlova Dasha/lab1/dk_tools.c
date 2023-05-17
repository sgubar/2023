#include "dk_tools.h"
#include <stdlib.h>
#include<stdio.h>

int sum(int a, int b) {
	return a + b;
}
int multipl(int a, int b) {
	return a * b;
}

int get_dodint(char* text)
{
    int n;
    while (1)
    {
        printf("%s", text);
        n = get_int();
        if (n > 0)
            break;
    }
    return n;

}

int get_int()
{
    int n;
    while (scanf_s("%d", &n) != 1)
    {
        printf("Треба вводити лише числа. Спробуйте знову:");
        while (getchar() != '\n')
            continue;
    }
    return n;
}