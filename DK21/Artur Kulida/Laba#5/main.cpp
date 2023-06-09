#include <GL/glut.h> 

char title[] = "lab 5 kulida arthur";
bool perspective = true;
bool moveScene = false;

float a_z = 0, a = 0.5f;
float zoom_param = -7.0;
float zoom_delta = 0.1;

void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | 
    GL_DEPTH_BUFFER_BIT); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param); 
    glRotatef(a_z, 0, 0, 1);  


    glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.95f, 0.0f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //грані
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.95f, 0.0f, 0.3f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(0.0f, 0.5f, 1.0f);
        glVertex3f(0.95f, 0.0f, 0.3f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 1.0f, 0.0f);
    glEnd();

    glutSwapBuffers(); 
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void specialKeyCallback(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT) {
		a_z += a;

	} else if (key == GLUT_KEY_RIGHT) {
		a_z -= a;
	}
	glutPostRedisplay();
}

void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow(title);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutSpecialFunc(specialKeyCallback);
    glutTimerFunc(0, Timer, 0);
    initGL();
    glutMainLoop();
    return 0;
}
