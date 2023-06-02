#ifdef FIGURE_H
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

char title[] = "parallelepiped";
float angle = 0.0f;
float zoom_p = -5.0;

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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, zoom_p);
	glRotatef(angle, 1, 0, 0);

	// Грань 1
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f); // Red
	glVertex3f(0.0f, 2.0f, -1.0f);
	glVertex3f(-1.732f, 1.0f, -1.0f);
	glVertex3f(-1.732f, -1.0f, -1.0f);
	glVertex3f(0.0f, -2.0f, -1.0f);
	glVertex3f(1.732f, -1.0f, -1.0f);
	glVertex3f(1.732f, 1.0f, -1.0f);
	glEnd();

	// Грань 2
	glBegin(GL_POLYGON);
glColor3f(0.0f, 1.0f, 0.0f); // Green
glVertex3f(0.0f, 2.0f, -1.0f);
glVertex3f(-1.732f, 1.0f, -1.0f);
glVertex3f(-1.732f, 1.0f, 1.0f);
glVertex3f(0.0f, 2.0f, 1.0f);
glEnd();

	// Грань 3
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(-1.732f, 1.0f, -1.0f);
	glVertex3f(-1.732f, -1.0f, -1.0f);
	glVertex3f(-1.732f, -1.0f, 1.0f);
	glVertex3f(-1.732f, 1.0f, 1.0f);
	glEnd();

	// Грань 4
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(-1.732f, -1.0f, -1.0f);
	glVertex3f(0.0f, -2.0f, -1.0f);
	glVertex3f(0.0f, -2.0f, 1.0f);
	glVertex3f(-1.732f, -1.0f, 1.0f);
	glEnd();

	// Грань 5
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 1.0f); // Magenta
	glVertex3f(0.0f, -2.0f, -1.0f);
	glVertex3f(1.732f, -1.0f, -1.0f);
	glVertex3f(1.732f, -1.0f, 1.0f);
	glVertex3f(0.0f, -2.0f, 1.0f);
	glEnd();

	// Грань 6
	glBegin(GL_POLYGON);
	glColor3f(0.0f, 1.0f, 1.0f); // Cyan
	glVertex3f(1.732f, 1.0f, -1.0f);
	glVertex3f(1.732f, -1.0f, -1.0f);
	glVertex3f(1.732f, -1.0f, 1.0f);
	glVertex3f(1.732f, 1.0f, 1.0f);
	glEnd();

	// Грань 7
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(1.732f, 1.0f, -1.0f);
	glVertex3f(0.0f, 2.0f, -1.0f);
	glVertex3f(0.0f, 2.0f, 1.0f);
	glVertex3f(1.732f, 1.0f, 1.0f);
	glEnd();

	// Грань 8
	glBegin(GL_POLYGON);
	glVertex3f(0.0f, 2.0f, 1.0f);
	glColor3f(0.5f, 1.0f, 0.0f);
	glVertex3f(1.732f, 1.0f, 1.0f);
	glVertex3f(1.732f, -1.0f, 1.0f);
	glVertex3f(0.0f, -2.0f, 1.0f);
	glVertex3f(-1.732f, -1.0f, 1.0f);
	glVertex3f(-1.732f, 1.0f, 1.0f);
	glEnd();

	glFlush();
	glutSwapBuffers();
}



void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)width / (float)height, 0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
}

void MyKeyBoardFunc(unsigned char key, int, int)
{
	if (key == 'a') {
		angle += 2.0f;
	} else if (key == 'd') {
		angle -= 2.0f;
	}
	glutPostRedisplay();
}

void Timer(int)
{
	glutPostRedisplay();
	glutTimerFunc(30, Timer, 0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
        glutKeyboardFunc(MyKeyBoardFunc);
	initGL();
	glutTimerFunc(0, Timer, 0);
	glutMainLoop();
	return 0;
}
