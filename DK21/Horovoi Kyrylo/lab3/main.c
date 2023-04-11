#include <stdio.h>
#include "tree.h"
#include "dk_tool.h"
#include <stdbool.h>
int main(int argc, char *argv[])
{
    FloatTree *Tree = createFloatTree();
    int choice;
    float value;
    while(1)
    {
        printf("1 - ������ �������, 2 - ������ �������, 3 - �������� �������, 4 - ���������� ������ ");
        do
        {
            choice = get_inttext(":");
        }while(choice<1||choice>4);
        switch(choice)
        {
        case 1:
            value = get_floattext("������ ���: ");
            insertFloatValueToTree(Tree, value);
            break;
        case 2:
            value = get_floattext("������ ���: ");
            FloatNode *tmp = findNodeWithValue(Tree, value);
            if(tmp == NULL)
            {
                printf("������� �� ��������\n");
            }
            else
                printNode(tmp);
            break;
        case 3:
            value = get_floattext("������ ���: ");
            deleteNodeWithValue(Tree, value);
            break;
        case 4:
            destroyTree(Tree);
            return 0;
        }
       printTree(Tree);
    }
}

