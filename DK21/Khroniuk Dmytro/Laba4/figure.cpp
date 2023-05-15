#include <GL/glut.h>
#include "figure.h"
#include <cmath>

// початок списку
Circle* head = NULL;

void display()
{
    // Очищення буфера кольору та глибини
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Матриця моделі
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Перебір кол у списку
    Circle* current = head;
    while (current != NULL) {
        glPushMatrix();
        glTranslatef(current->x, current->y, 0.0f);
        glRotatef(current->angle, 0.0f, 0.0f, 1.0f);
        glColor3f(current->x, current->y, 1.0f); // Колір залежить від позиції кола
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // Центр кола
        int numSegments = 100; // Кількість сегментів для наближення кола
        float angle;
        for (int i = 0; i <= numSegments; i++) {
            angle = 2.0f * 3.1415926f * i / numSegments;
            float x = current->radius * cos(angle);
            float y = current->radius * sin(angle);
            glVertex2f(x, y);
        }
        glEnd();
        glPopMatrix();

        current = current->next;
    }

    // Обмін буферів
    glutSwapBuffers();
}

void update(int value)
{
    // Оновлення кута обертання кол у списку
    Circle* current = head;
    while (current != NULL) {
        current->angle += 2.0f;
        current = current->next;
    }

    // Оновлення відображення
    glutPostRedisplay();

    // Відновлення функції зворотного виклику таймера
    glutTimerFunc(25, update, 0);
}

void addCircle(float x, float y, float radius)
{
    // Створення нового кола
    Circle* newCircle = (Circle*)malloc(sizeof(Circle));
    newCircle->x = x;
    newCircle->y = y;
    newCircle->radius = radius;
    newCircle->angle = 0.0f;
    newCircle->next = NULL;

    // Додавання кола до списку
    if (head == NULL) {
        newCircle->prev = NULL;
        head = newCircle;
    } else {
        Circle* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newCircle;
        newCircle->prev = current;
    }
}

void destroyList()
{
    // Видалення всього списку
    Circle* current = head;
    while (current != NULL) {
        Circle* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

}
