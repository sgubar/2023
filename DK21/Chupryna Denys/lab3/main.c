#include <stdio.h>
#include "tree.h"
#include "dk_tool.h"
#include <stdbool.h>
int main(int argc, char *argv[])
{
    DoubleTree *Tree = createDoubleTree();
    int choice;
    double value;
    while(1)
    {
        printf("1 -add element, 2 - find element, 3 - delete element, 4 - close program ");
        do
        {
            choice = get_inttext(":");
        }while(choice<1||choice>4);
        switch(choice)
        {
        case 1:
            value = get_Doubletext("enter data: ");
            insertdoubleValueToTree(Tree, value);
            break;
        case 2:
            value = get_Doubletext("enter data: ");
            DoubleNode *tmp = findNodeWithValue(Tree, value);
            if(tmp == NULL)
            {
                printf("element not found\n");
            }
            else
                printNode(tmp);
            break;
        case 3:
            value = get_Doubletext("enter data: ");
            deleteNodeWithValue(Tree, value);
            break;
        case 4:
            destroyTree(Tree);
            return 0;
        }
       printTree(Tree);
    }
}
