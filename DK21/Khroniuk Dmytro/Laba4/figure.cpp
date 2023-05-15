#include <GL/glut.h>
#include "figure.h"
#include <cmath>

// ������� ������
Circle* head = NULL;

void display()
{
    // �������� ������ ������� �� �������
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // ������� �����
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // ������ ��� � ������
    Circle* current = head;
    while (current != NULL) {
        glPushMatrix();
        glTranslatef(current->x, current->y, 0.0f);
        glRotatef(current->angle, 0.0f, 0.0f, 1.0f);
        glColor3f(current->x, current->y, 1.0f); // ���� �������� �� ������� ����
        glBegin(GL_TRIANGLE_FAN);
        glVertex2f(0.0f, 0.0f); // ����� ����
        int numSegments = 100; // ʳ������ �������� ��� ���������� ����
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

    // ���� ������
    glutSwapBuffers();
}

void update(int value)
{
    // ��������� ���� ��������� ��� � ������
    Circle* current = head;
    while (current != NULL) {
        current->angle += 2.0f;
        current = current->next;
    }

    // ��������� �����������
    glutPostRedisplay();

    // ³��������� ������� ���������� ������� �������
    glutTimerFunc(25, update, 0);
}

void addCircle(float x, float y, float radius)
{
    // ��������� ������ ����
    Circle* newCircle = (Circle*)malloc(sizeof(Circle));
    newCircle->x = x;
    newCircle->y = y;
    newCircle->radius = radius;
    newCircle->angle = 0.0f;
    newCircle->next = NULL;

    // ��������� ���� �� ������
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
    // ��������� ������ ������
    Circle* current = head;
    while (current != NULL) {
        Circle* next = current->next;
        free(current);
        current = next;
    }
    head = NULL;

}
