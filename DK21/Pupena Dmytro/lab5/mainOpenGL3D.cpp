#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>

// ��������� �����
char title[] = "Cube";
bool perspective = true;
bool moveScene = false;
int mouse_x,
mouse_y;
float a_x = 0, a_y = 0;
float zoom_param = -7.0;
float zoom_delta = 0.1;



// ������������ OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f); // ��� - ������ �� ��������
    glClearDepth(1.f); // ������� ���� - ������� ��������
    glEnable(GL_DEPTH_TEST); // ����� ���������� �������
    glDepthFunc(GL_LEQUAL); // ��� ������� ���������� �������
    glShadeModel(GL_SMOOTH); // ����� �������� ��������������
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // �������� �����������
}


// ������� ������� ������ �� �������������. ������ ��������� �����.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // �������� ������ �������
        GL_DEPTH_BUFFER_BIT); // �� ������ �������
    glMatrixMode(GL_MODELVIEW); // ���� ������� ������-������
    glLoadIdentity(); // �������� ��������� ������� ������
    // ������������ �������� �������
    glTranslatef(0.f, 0.f, zoom_param); // ������� ��'���� � ������� ������
    glRotatef(a_x, 1, 0, 0); // ��������� ������� �� x
    glRotatef(a_y, 0, 1, 0); // ��������� ������� �� y
    // ��������� ��'���� � ���� � ������� ������ �������
    glBegin(GL_QUADS); // ��� ���������� � 6 �������� (�������������)

    // ��������� ������ ������������
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.25f, 1.0f, 0.5f);
    glVertex3f(-0.25f, 0.0f, 0.5f);
    glVertex3f(-0.5f, 0.0f, 0.0f);

    // ����� ����� (y = -1.0f)
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(-0.25f, 1.0f, 0.5f);
    glVertex3f(0.25f, 1.0f, 0.5f);
    glVertex3f(0.25f, 0.0f, 0.5f);
    glVertex3f(-0.25f, 0.0f, 0.5f);

    // ������� ����� (z = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(0.25f, 1.0f, 0.5f);
    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.25f, 0.0f, 0.5f);

    // ����� ����� (z = -1.0f)
    glColor3f(1.0f, 1.0f,1.0f); 
    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(0.25f, 1.0f, -0.5f);
    glVertex3f(0.25f, 0.0f, -0.5f);
    glVertex3f(0.5f, 0.0f, 0.0f);
   

    // ˳�� ����� (x = -1.0f)
    glColor3f(0.5f, 0.5f, 1.0f); 
    glVertex3f(0.25f, 1.0f, -0.5f);
    glVertex3f(-0.25f, 1.0f, -0.5f);
    glVertex3f(-0.25f, 0.0f, -0.5f);
    glVertex3f(0.25f, 0.0f, -0.5f);
    

    // ����� ����� (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); 
    glVertex3f(-0.25f, 1.0f, -0.5f);
    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(-0.25f, 0.0f, -0.5f);

    glEnd(); // ���������� ��������� ����
    //��������� ����� ������
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);

    glVertex3f(-0.5f, 1.0f, 0.0f);
    glVertex3f(-0.25f, 1.0f, 0.5f);
    glVertex3f(0.25f, 1.0f, 0.5f);
    glVertex3f(0.5f, 1.0f, 0.0f);
    glVertex3f(0.25f, 1.0f, -0.5f);
    glVertex3f(-0.25f, 1.0f, -0.5f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 1.0f);

    glVertex3f(-0.5f, 0.0f, 0.0f);
    glVertex3f(-0.25f, 0.0f, 0.5f);
    glVertex3f(0.25f, 0.0f, 0.5f);
    glVertex3f(0.5f, 0.0f, 0.0f);
    glVertex3f(0.25f, 0.0f, -0.5f);
    glVertex3f(-0.25f, 0.0f, -0.5f);
    glEnd();

    glutSwapBuffers(); // ���� ������ �����
    // (��������������� ������� �����������)
}


// ������� ������� ��䳿, �� ������ ��� ������������� ����
void reshape(int width, int height)
{
    // ���������� ��������� ����� ���� ������ ������
    if (height == 0) // �������� ��� ��������� ������ �� 0
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // ������������ ������ ���� ������ �������� �� ����� ������ ����
    glViewport(0, 0, width, height);

    // ������������ ��������� ���������� �������
    glMatrixMode(GL_PROJECTION); // ���� ������� ��������
    glLoadIdentity(); // �������� �������

    // ������������ ������������ �������� �
    // ����������� fovy = 45, aspect, zNear = 0.1 �� zFar = 100
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


// ������� ������� ��䳿, �� ������ ��� ���������� ����� ���������
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27: // Esc
        exit(0);
        break;
    }
}


// ������� ������� ��䳿, �� ������ ��� ���������� ����� �����
void mouseClick(int button, int state, int x, int y)
{
    if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN) {
        moveScene = true;
        mouse_x = x;
        mouse_y = y;
    }

    if (GLUT_LEFT_BUTTON == button && state == GLUT_UP) {
        moveScene = false;
    }
}


// ������� ������� ��䳿, �� ������ ��� ������������ ������
void mouse(int button, int state, int x, int y)
{
    // ���� ������� ��������� ���� ������ �� ���������� �����������, �����, ����������
    if (button == 3) {
        zoom_param += zoom_delta;
    }
    else if (button == 4) {
        zoom_param -= zoom_delta;
    }
}

// ������� ������� ��䳿, �� ������ ��� ���������� ���� �����
void mouseMove(int x, int y)
{
    int dx = mouse_x - x,
        dy = mouse_y - y;
    a_x -= 0.250f * dy;
    a_y -= 0.250f * dx;
    mouse_x = x;
    mouse_y = y;
}


// ������� ������� ��䳿, �� ������ ��� ����������� �������
void Timer(int value)
{
    glutPostRedisplay(); // ����������� ������ �� �������������
    // ����� ������� ������� display()

    glutTimerFunc(30, Timer, 0); // ����� ������ ������� �� 30 ��
}


// ������� �������: �������� GLUT ���������� �� ���������� �������
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // ������������ GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // ��������� ������� �����������
    glutInitWindowSize(640, 480); // ������������ ������ ����
    glutInitWindowPosition(50, 50); // ������������ ��������� ����
    glutCreateWindow(title); // ��������� ���� �� ������� ��'��
    glutDisplayFunc(display); // ��������� ��������� ������ �������������
    glutReshapeFunc(reshape); // ��������� ��������� ������ �������������
    glutKeyboardFunc(keyboard); // ��������� ��������� ���� ���������
    glutMouseFunc(mouseClick);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove); // ��������� ��������� ���� ����
    glutTimerFunc(0, Timer, 0); // ������ �� ��������� ������� �������
    initGL(); // ������������ OpenGL
    glutMainLoop(); // ���� � �������� ����������� ���� �������
    // ����
    return 0;
}