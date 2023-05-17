#ifndef rectangle_h
#define rectangle_h

#include <stdio.h>
#include "point.h"

#define PT_NUM 4


// Колір як стурктура
typedef struct Color_s{
    float R;
    float G;
    float B;
} Color_s;
// Методи для роботи з кольором
Color_s* createColor(float R, float G, float B);
void deleteColor(Color_s* color);


// Фігура як масив точок з кольором
typedef struct tagRectangle{
    Point* points[PT_NUM]; // ВАЖЛИВО: в прикладі координати мають значення від [-100;100], але потім масштабуються до [-1;1] як цього потребує OpenGL
    Color_s* color;
} Rectangle_s;
// Методи для роботи з фігурою
Rectangle_s* createRectangle(Point** points, Color_s * color);
void deleteRectangle(Rectangle_s* aRectangle);
void drawRectangle(Rectangle_s* aRectangle);


// Елемент списку фігур
typedef struct RectangleListElement_s RectangleListElement_s;
struct RectangleListElement_s{
    RectangleListElement_s* prev;
    RectangleListElement_s* next;
    Rectangle_s* figure;
};
// Методи для роботи з елементом списку фігур
RectangleListElement_s* createListElement(Rectangle_s* aRectangle);
void deleteListElement(RectangleListElement_s* listElement);
void drawListElement(RectangleListElement_s* listElement);


// Двозв'язний список фігур
typedef struct tagRectangleList_s{
    RectangleListElement_s* head;
    RectangleListElement_s* tail;
} RectangleList_s;
// Методи для роботи зі списком фігур
RectangleList_s *createRectangleList(void);
void deleteRectangleList(RectangleList_s *list);
void drawRectangleList(RectangleList_s *list);
long countOfRectangleList(RectangleList_s *list);
int addRectangleToRectangleList(RectangleList_s *list, Rectangle_s* aRectangle); // 1 - успіх, 0 - провал
void removeLastElementFromRectangleList(RectangleList_s *list);
void removeFirstElementFromRectangleList(RectangleList_s *list);
int insertRectangleToRectangleListAtIndex(RectangleList_s *list, int index, Rectangle_s* aRectangle); // 1 - успіх, 0 - провал
int removeRectangleFromRectangleListAtIndex(RectangleList_s *list, int index); // 1 - успіх, 0 - провал

#endif