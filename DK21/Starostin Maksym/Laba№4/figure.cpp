#include <GL/glut.h>
#include <stdlib.h>
#include "figure.h"

// ������� ������
Square* head = NULL;

void display()
{
    // �������� ������ ������� �� �������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ������� ������
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ���������� �������� � ������
    Square* current = head;
    while (current != NULL) {
        glPushMatrix();
        glTranslatef(current->x, current->y, 0.0f);
        glRotatef(current->angle, 0.0f, 0.0f, 1.0f);
        glColor3f(current->x, current->y, 1.0f); // ���� �������� �� ������� ��������
        glBegin(GL_QUADS);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.3f, -0.3f);
        glVertex2f(-0.3f, -0.3f);
        glVertex2f(-0.3f, 0.3f);
        glEnd();
        glPopMatrix();

        current = current->next;
    }

    // ���� ������
    glutSwapBuffers();
}

void update(int value)
{
    // ��� ����������
    Square* current = head;
    while (current != NULL) {
            current->angle += 4.0f;
        current = current->next;
    }

    // ��������� �������
    glutPostRedisplay();

    // ³��������� ������� ���������� ������� �������
    glutTimerFunc(25, update, 0);
}

Square *addSquare(float x, float y)
{
    // ����� �������
    Square* newSquare = (Square*)malloc(sizeof(Square));
    newSquare->x = x;
    newSquare->y = y;
    newSquare->angle = 0.0f;
    newSquare->next = NULL;

    // ��������� �������� �� ������
    if (head == NULL) {
        newSquare->prev = NULL;
        head = newSquare;
    } else {
        Square* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newSquare;
        newSquare->prev = current;
    }

    return newSquare;
}

void removeSquare(Square* square)
{
    if (square == NULL) {
        return;
    }

    // ��������� �������� � ������
    if (square->prev != NULL) {
        square->prev->next = square->next;
    }
    if (square->next != NULL) {
        square->next->prev = square->prev;
    }
    if (square == head) {
        head = square->next;
    }

    free(square);
}

void destroyList()
{
    // ��������� ������
    Square* current = head;
    while (current != NULL) {
        Square* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

void insertSquareAfter(Square* currentSquare, float x, float y)
{
    if (currentSquare == NULL) {
        return;
    }

    // ����� �������
    Square* newSquare = (Square*)malloc(sizeof(Square));
    newSquare->x = x;
    newSquare->y = y;
    newSquare->angle = 0.0f;

    // ����� ������� ���� ������������
    newSquare->prev = currentSquare;
    newSquare->next = currentSquare->next;
    if (currentSquare->next != NULL) {
        currentSquare->next->prev = newSquare;
    }
    currentSquare->next = newSquare;
}
