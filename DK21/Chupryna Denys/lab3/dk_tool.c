#include <stdlib.h>
#include <stdio.h>
#include "dk_tool.h"



int get_inttext(char *text)
{
    int n;
    printf("%s", text);
    while (scanf("%d", &n) != 1)
    {
        printf("%s", text);
        while(getchar()!='\n')
            continue;
    }
    return n;

}
double get_Doubletext(char *text)
{
    double n;
    printf("%s", text);
    while (scanf("%f", &n) != 1)
    {
        printf("%s", text);
        while(getchar()!='\n')
            continue;
    }
    return n;
}

