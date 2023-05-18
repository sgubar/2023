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
        printf("\n����'������� �����: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\n����� �� �������� :( .\n");

    delValFrTree(ATree, 7);

    prntTree(ATree->root);

    if (NULL != fndNd(ATree, 7))
    {
        printf("\n����'������� �����: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\n����� �� �������� :( .\n");

    addNd(ATree, 7);

    prntTree(ATree->root);

    if (NULL != fndNd(ATree, 7))
    {
        printf("\n����'������� �����: %d\n", fndNd(ATree, 7)->value);
    }
    else
        printf("\n����� �� �������� :( .\n");

    dstrTree(ATree);

    return 0;
}