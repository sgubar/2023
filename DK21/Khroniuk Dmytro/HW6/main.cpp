#include <GL/glut.h>
#include <math.h>
/// 21(6) ������
///////////////////////////////////////////// �������
GLfloat blue[] = {0.0, 0.0, 1.0, 1.0}; /// ����
GLfloat red[] = {1.0, 0.0, 0.0, 1.0}; /// ��������
GLfloat white[] = {1.0, 1.0, 1.0, 1.0}; /// �����

///////////////////////////////////////////// ������� ��� ��������� �� �����
void display() {
    ///////////////////////////////////////////// ��������
    glClear(GL_COLOR_BUFFER_BIT);

    ///////////////////////////////////////////// ������������ ������ ��� ����
    glColor4fv(red);

    ///////////////////////////////////////////// ��������� ������������ ����
    glBegin(GL_LINES);
    glVertex2f(-3.0, 0.0);
    glVertex2f(3.0, 0.0);
    glVertex2f(0.0, -3.0);
    glVertex2f(0.0, 3.0);
    glEnd();

    ///////////////////////////////////////////// ������ �� ������������ ����
    glBegin(GL_LINES);
    for (float i = -3.0; i <= 3.0; i += 0.1) {
        glVertex2f(i, -0.1);
        glVertex2f(i, 0.1);
        glVertex2f(-0.1, i);
        glVertex2f(0.1, i);
    }
    glEnd();

    ///////////////////////////////////////////// ���� ��� �������
    glColor4fv(blue);

    ///////////////////////////////////////////// ����������� �������
    glBegin(GL_LINE_STRIP);
    for (float t = -3.14; t <= 3.14; t += 0.01) { /// �����
        float x = (2 * sqrt(2) * cos(t) ) / (1 + sin(t) * sin(t)); ///a=2
        float y = (2 * sqrt(2) * cos(t) * sin(t) ) / (1 + sin(t) * sin(t));
        glVertex2f(x, y);
    }
    glEnd();

    ///////////////////////////////////////////// ���������
    glFlush();
}

int main(int argc, char** argv) {
    ///////////////////////////////////////////// ����������� GLUT �� ��������� ����
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graph of the given function");

    ///////////////////////////////////////////// ���� ����
    glClearColor(1.0, 1.0, 1.0, 1.0);

    ///////////////////////////////////////////// ������� ���������
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-3.0, 3.0, -3.0, 3.0);

    ///////////////////////////////////////////// ������� ���������
    glutDisplayFunc(display);

    /////////////////////////////////////////////
    glutMainLoop();

    return 0;
}
