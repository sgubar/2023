#include <stdlib.h>
#include <stdio.h>
#include "dk21_tool.h"
#include <time.h>

int main(int argc, char** argv)
{
    srand(time(NULL));

    BinTree* ATree = crtTree();

    dbgTree(ATree);

    prntTree(ATree->root);

    if (NULL != fndNd(ATree, 7))
    {
        printf("\nОбов'язковий вузол: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\nВузол не знайдено :( .\n");

    delValFrTree(ATree, 7);

    prntTree(ATree->root);

    if (NULL != fndNd(ATree, 7))
    {
        printf("\nОбов'язковий вузол: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\nВузол не знайдено :( .\n");

    addNd(ATree, 7);

    prntTree(ATree->root);

    if (NULL != fndNd(ATree, 7))
    {
        printf("\nОбов'язковий вузол: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\nВузол не знайдено :( .\n");

    dstrTree(ATree);

    return 0;
}