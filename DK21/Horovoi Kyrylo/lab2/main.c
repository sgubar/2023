#include "dk_tool.h"
#include "list.h"
#include <stdio.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
    Ring *my = createRing();
    int choice;
    while(true)
    {
        printf("1 - ������ ��������� �������, 2 - ������ ��������� �������, 3 - ������� �������, 4 - ��������� ������ ������, 5 - ��������� ������ ����, 6 - �������� ������, 7 - ���������  3-� ��������, 8- ���������� ������");
        do
        {
            choice = get_inttext(":");
        }while(choice<1||choice>8);
        int tmp;
        switch(choice)
        {
        case 1:
            tmp=get_inttext("������ ���:");
            pushNext(my, tmp);
            break;
        case 2:
            tmp=get_inttext("������ ���:");
            pushPrev(my, tmp);
            break;
        case 3:
            printf("%d\n", pull(my));
            break;
        case 4:
            goNext(my);
            break;
        case 5:
            goPrev(my);
            break;
        case 6:
            clearRingList(my);
            break;
        case 7:
            while(my->current->next != my->current->prev)
            {
                delelmord(my, 3);
                printRing(my);
            }
            break;
        case 8:
            deleteRingList(my);
            return 0;
    }
    printRing(my);
}
}
