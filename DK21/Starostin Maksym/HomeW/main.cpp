#include <GL/glut.h> //������ 17
#include <math.h>

float a = 1.0f; //�������� ������� �
float b = 1.0f; //�������� ������� b

// �������, �� ��������������� ��� ��������� �����
void display()
{
   glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT); // �������� ������ �������

    // ��������� ��� ������, �� � �������� �������
    glBegin(GL_LINE_STRIP); // ����� ���� ������� ���� ������
        glColor3f(1.0f, 1.0f, 0.0f);
        for (float t = -M_PI; t <= M_PI; t += 0.1) {
            float x = a * pow(cos(t), 2) - b * cos(t);
            float y = a*sin(t)*cos(t)-b*cos(t);
            glVertex2f(x, y);
        }
    glEnd();


    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 0.0f, 0.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // ��������� �������� �� ������������ ����
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(0.0f, 0.0f, 0.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // �������� ���������
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // ����������� GLUT
    glutInitWindowSize(400, 400); // ����� ����
    glutInitWindowPosition(0, 0); // ��������� ����
    glutCreateWindow("Starostin Maxsym"); // ��'� ����
    glutDisplayFunc(display); // ��������� ������� ��� ���������� ����
    glutMainLoop(); // ���� � ���� ������� ���� GLUT
return 0;
}
