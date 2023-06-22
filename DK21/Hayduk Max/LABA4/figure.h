#ifndef FIGURE_H
#define FIGURE_H

struct Circle {
    float x;            // Координата x центра кола
    float y;            // Координата y центра кола
    float radius;       // Радіус кола
    float angle;        // Кут повороту кола
    struct Circle* next; // Вказівник на наступне коло
    struct Circle* prev; // Вказівник на попереднє коло
};

void createCircle(struct Circle* circle, float x, float y, float radius, float angle);
void drawCircle(struct Circle circle);
void rotateCircle(struct Circle* circle, float angle);
void display();
void update(int value);
void destroyList();
void addCircle(float x, float y, float radius);

#endif
