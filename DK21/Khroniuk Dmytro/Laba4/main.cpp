#include <GL/glut.h>
#include "figure.h"
#include <cmath>

int main(int argc, char** argv)
{
    // ����������� GLUT �� ��������� ����
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Circles");

    // ������������ ������� ���������� �������
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // ������������ ������� �������� �� �������
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    // ��������� ���� �� ������
    addCircle(-0.5f, 0.5f, 0.2f);  // ������� ��������� ���� �� ������
    addCircle(0.5f, 0.5f, 0.3f);
    addCircle(0.0f, -0.5f, 0.4f);

    // ���� �� ��������� ����� GLUT
    glutMainLoop();

    // ��������� ������ ���� �������� ��������
    destroyList();

    return 0;
}
