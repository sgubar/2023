#ifdef _SHAPE_H
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

char title[] = "Parallelepiped Zooming in/out keys W, S";
bool perspective = true;
bool moveScene = false;

float a_x = 0, a_y = 0;
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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.f, 0.f, zoom_param);
	glRotatef(a_x, 1, 0, 0); // Обертання навколо осі x
	glRotatef(a_y, 0, 1, 0); // Обертання навколо осі y


	glBegin(GL_QUADS);

	// Front face (Red)
	glColor3f(1.0f, 0.0f, 0.0f); // Red
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);

	    // Back face (Green)
	glColor3f(0.0f, 1.0f, 0.0f); // Green
	glVertex3f(2.0f, -1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);

	// Top face (Blue)
	glColor3f(0.0f, 0.0f, 1.0f); // Blue
	glVertex3f(2.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);

	// Bottom face (Yellow)
	glColor3f(1.0f, 1.0f, 0.0f); // Yellow
	glVertex3f(1.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(1.0f, 1.0f, -1.0f);

	// Right face (Pink)
	glColor3f(1.0f, 0.0f, 1.0f); // Pink
	glVertex3f(-1.0f, 1.0f, 1.0f);
	glVertex3f(-2.0f, 1.0f, -1.0f);
	glVertex3f(-2.0f, -1.0f, -1.0f);
	glVertex3f(-1.0f, -1.0f, 1.0f);

	// Left face (Olive)
	glColor3f(0.5f, 0.5f, 0.0f); // Olive
	glVertex3f(1.0f, 1.0f, -1.0f);
	glVertex3f(2.0f, 1.0f, 1.0f);
	glVertex3f(2.0f, -1.0f, 1.0f);
	glVertex3f(1.0f, -1.0f, -1.0f);


	glEnd();
	glFlush();
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

void MyKeyBoardFunc(unsigned char key, int, int)
{
	if (key == 'w') {
		zoom_param += zoom_delta;
	} else if (key == 's') {
		zoom_param -= zoom_delta;
	}
	glutPostRedisplay(); // Викликаємо функцію display() для оновлення вікна
}

void Timer(int)
{
    glutPostRedisplay(); 
    glutTimerFunc(30, Timer, 0); // Новий запуск таймера на 30 мс
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutKeyboardFunc(MyKeyBoardFunc);
    glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
    initGL(); 
    glutMainLoop();
    return 0;

}
