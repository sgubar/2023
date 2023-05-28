#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float a = 0.06f; //�������� ������� �
float b = 0.25f; //�������� ������� b

// �������, �� ��������������� ��� ��������� �����
void display()
{
    glClearColor(0.4f, 0.3f, 0.13f, 1.0f); // ��� ���������� 
    glClear(GL_COLOR_BUFFER_BIT); // �������� ������ �������

    // ��������� ��� ������, �� � �������� �������
    glBegin(GL_LINE_STRIP); // ����� ���� ������� ���� ������
    glColor3f(1.0f, 0.0f, 0.0f); // ���� �������(��������)
    for (float t = 0; t <= 5 * M_PI; t += 0.1) {
        float x = a * exp(b*t) * cos(t);
        float y = a * exp(b*t) * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    // ��������� ������������ ����
    glBegin(GL_LINE_STRIP);//��������� �� Y
    glColor3f(0.0f, 1.0f, 0.0f);//������� ����
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);//��������� �� X
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    // ��������� �������� �� ������������ ����
    for (float x = -1.0; x <= 1.0; x += 0.05) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x, -0.03);
        glVertex2f(x, 0.03);
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += 0.05) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.03, y);
        glVertex2f(0.03, y);
        glEnd();
    }
    glFlush(); // �������� ���������
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // ����������� GLUT
    glutInitWindowSize(500, 500); // ������ �� ������ ����
    glutInitWindowPosition(0, 0); // ��������� ����
    glutCreateWindow("HW 6 - ������� ������"); // ��������� ���� �� ������� ��'��
    glutDisplayFunc(display); // ��������� ������� ����������
    // ������� ��� ��������� ����
    glutMainLoop(); // ���� � ���� ������� ���� GLUT
    return 0;
}