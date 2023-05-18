#ifndef DK21_TOOL_H
#define DK21_TOOL_H

typedef struct tagCharacter Character;

struct tagCharacter
{
    char value;
    Character* prev;
    Character* next;
};

Character* crtChrctr(char value);
void delChrctr(Character* element);
void prntChrctr(Character* element);

typedef struct tagRow
{
    Character* head;

    Character* tail;
} Row;

Row* crtRow(void);

void delRow(Row* list);

void prntRvrsRow(Row* list);

int addChrctrToRow(Row* list, char value);

#endif
