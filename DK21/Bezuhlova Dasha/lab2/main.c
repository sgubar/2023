#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "dk21_tool.h"

int main()
{
    FILE* flow = fopen("test.txt", "r");

    char tmpCharacter;

    Row* tmpRow = crtRow();

    while ((tmpCharacter = fgetc(flow)) != EOF)
    {
        if (tmpCharacter == '\n')
        {
            prntRvrsRow(tmpRow);

            delRow(tmpRow);

            tmpRow = crtRow();
        }

        else
        {
            addChrctrToRow(tmpRow, tmpCharacter);
        }
    }

    prntRvrsRow(tmpRow);

    delRow(tmpRow);

    fclose(flow);

    return 0;
}