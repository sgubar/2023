#include <GL/glut.h> 

char title[] = "Lab 5 Bezuhlova Dasha";

//�������� ����
float a_z = 0, zdelta = 1.2f;
float zoom_param = -7.0;

//����������� OpenGL
void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 0.f);//������ ���
    glClearDepth(1.f);//������� ����
    glEnable(GL_DEPTH_TEST);//����� �� ���������� �������
    glDepthFunc(GL_LEQUAL);//��� ������� ���������� �������
    glShadeModel(GL_SMOOTH);//����� �������� ��������������
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//�������� �����������
}

//��������� �����
void display()
{
    glClear(GL_COLOR_BUFFER_BIT |//�������� ������ ������� �� ������ �������
        GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);//���� ������� ������-������
    glLoadIdentity();//�������� ��������� ������� ������ ������������ �������� �������

    glTranslatef(0.f, 0.f, zoom_param);//������� ��'���� � ������� ������
    glRotatef(a_z, 0, 0, 1);//��������� ������� �� Z (31 ������ �������)

    glBegin(GL_QUADS); // ��� ���������� � 6 �������� (�������������)

    // ������ ����� (y = 1.0f)
    glColor3f(0.0f, 1.0f, 0.0f); // ������
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // ����� ����� (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // �����������
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // ������� ����� (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // �������
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // ����� ����� (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // �����
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // ˳�� ����� (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // ����
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // ����� ����� (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); // ���������
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd(); // ���������� ��������� ����

    glutSwapBuffers(); // ���� ������ �����
    // (��������������� ������� �����������)
}

//������� ������� ��䳿, �� ������ ��� ������������ ����
void reshape(int width, int height)
{
    //���������� ��������� ����� ���� ������ ������
    if (height == 0)//��� �� ���� ������ �� 0
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);//������������ ������ ���� ������ �������� �� ����� ������

    //������������� ��������� ���������� �������
    glMatrixMode(GL_PROJECTION);//���� ������� ��������
    glLoadIdentity();//�������� �������

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);//������������ ����������� ��������
}

void specialKeyCallback(int key, int x, int y)//������� ������� ��䳿, �� ������ ��� ��������� ����� �� ��������
{
    if (key == GLUT_KEY_LEFT) {//˳�� �������� - ���������  ������� �� Z ����� ����������� ������ 
        a_z += zdelta;

    }
    else if (key == GLUT_KEY_RIGHT) {//����� ������� - ��������� ������� �� Z �� ������������ �������
        a_z -= zdelta;
    }

}

void Timer(int value)
{
    glutPostRedisplay();// ����������� ������ �� ������������� 
    glutTimerFunc(30, Timer, 0);// ����� ������ �������
}

//������� �������
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//����������� GLUT
    glutInitDisplayMode(GLUT_DOUBLE); //��������� ������� �����������
    glutInitWindowSize(640, 480);//������������ ������ ����   
    glutInitWindowPosition(50, 50);//������������ ��������� ����
    glutCreateWindow(title);//��������� ���� � ��'��
    glutDisplayFunc(display);//��������� ��������� ������ �������������
    glutReshapeFunc(reshape);//��������� ��������� ������ �� �������������
    glutSpecialFunc(specialKeyCallback);//��������� ��������� ���� ���������
    glutTimerFunc(0, Timer, 0);//������ �������
    initGL();//����������� OpenGL
    glutMainLoop();//���� � ���� ������� ����
    return 0;
}