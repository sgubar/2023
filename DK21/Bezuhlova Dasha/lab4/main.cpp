// ������ � 

#include <GL/glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
double zoom = 10; // �������
double lr, ud;

void shutdown(unsigned char key, int x, int y) {
    switch (key) {
    case 27: // Escape
        exit(0);
        break;
    }
}

void keys(int key, int x, int y)
{ // ����������� ��������(���, �����, �����, ����)
    switch (key)
    {
    case GLUT_KEY_LEFT: // ������ ������� ����
        lr = lr - 0.05;
        break;
    case GLUT_KEY_RIGHT: // ������ ������� ������
        lr = lr + 0.05;
        break;
    case GLUT_KEY_UP: // ������ ������� �����
        ud = ud + 0.05;
        break;
    case GLUT_KEY_DOWN: // ������ ������� ����
        ud = ud - 0.05;
        break;
    }
}

void Graf()
{
    int a = 1;
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (double t = -3 * M_PI; t <= 3 * M_PI; t += 0.01)
    { // ��� �������
        float x = (t - sin(t));
        float y = (1 - cos(t));
        glVertex2f(x / zoom + lr, y / zoom + ud);
    }
    glEnd();
}

void LineX()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glEnd();
}

void LineXY(double x)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(x, 0.025);
    glVertex2f(x, -0.025);
    glEnd();
}

void LineY()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0, -1);
    glVertex2f(0, 1);
    glEnd();
}

void LineYX(double y)
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.025, y);
    glVertex2f(-0.025, y);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Graf();
    LineX();
    for (double x = -1; x <= 1; x += 0.05)
    {
        LineXY(x);
    }
    LineY();
    for (double y = -1; y <= 1; y += 0.05)
    {
        LineYX(y);
    }
    glutSwapBuffers();
}

void timer(int value) {
    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // ����������� GLUT
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowPosition(50, 50); // ��������� ����
    glutInitWindowSize(600, 600);   // ������ �� ������ ����
    glutCreateWindow("Grafik");     // ���� �� ������� ��'��
    glutSpecialFunc(keys);
    glutDisplayFunc(display); // ��������� ������� ����������
    glutKeyboardFunc(shutdown);
    glutTimerFunc(0, timer, 0);
    glFlush();                // ������ ��� ��������� ����
    glutMainLoop();           // ���� � ���� ������� ���� GLUT
    return 0;
}