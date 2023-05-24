#include <GL/glut.h>
#include <stdlib.h>
#include "figure.h"

// ������� ������
Square* list_head = NULL;

int main(int argc, char** argv)
{
    // ��������� ����
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Rotating Squares");

    // ������������ ������� ���������� �������
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // ������������ ������� �������� �� �������
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    // ��������� ��������
    list_head = addSquare(0.5f, 0.5f);
    addSquare(0.5f, -0.5f);
    addSquare(-0.0f, -0.5f);
    addSquare(-0.0f, 0.5f);

    // �������

    Square* secondSquare = list_head->next;
    if (secondSquare != NULL) {
        insertSquareAfter(secondSquare, 0.3f, 0.3f);
    }

    // ��������� ������� ��������
    if (list_head != NULL) {
        removeSquare(list_head);
    }

    // ��������� � �������� ���� GLUT
    glutMainLoop();

    // ��������� ������
    destroyList();

    return 0;
}
