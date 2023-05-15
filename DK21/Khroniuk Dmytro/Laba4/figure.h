#ifndef FIGURE_H
#define FIGURE_H

struct Circle {
    float x;            // ���������� x ������ ����
    float y;            // ���������� y ������ ����
    float radius;       // ����� ����
    float angle;        // ��� �������� ����
    struct Circle* next; // �������� �� �������� ����
    struct Circle* prev; // �������� �� �������� ����
};

void createCircle(struct Circle* circle, float x, float y, float radius, float angle);
void drawCircle(struct Circle circle);
void rotateCircle(struct Circle* circle, float angle);
void display();
void update(int value);
void destroyList();
void addCircle(float x, float y, float radius);

#endif
