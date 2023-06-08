#ifdef _HW_6_ 
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float k = 3.8f; // 19 / 5
float zoom_p = -20.0;

void initGL(void)
{
	glClearDepth(1.f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}
// Функція, що викликатиметься для малювання сцени
void display()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Фон чорний
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.f, 0.f, zoom_p);



    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(1.0f, 1.0f, 1.0f); //Білий колір
        for (float t = - (5 * M_PI); t <= 5 * M_PI; t += 0.1) {
            float x = (k + 1) * (cos(t) - (cos((k + 1) * t)) / k + 1);
            float y = (k + 1) * (sin(t) - (sin((k + 1) * t)) / k + 1);
            glVertex2f(x, y);
        }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(x, -0.05);
            glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f);
            glVertex2f(-0.05, y);
            glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
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

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv); // Ініціалізація GLUT
	glutInitWindowSize(1366, 768); // Ширина та висота вікна
	glutInitWindowPosition(0, 0); // Положення вікна
	glutCreateWindow("Kulida Arthur 6 hw"); // Створення вікна із заданим ім'ям
	glutDisplayFunc(display); // Реєстрація функції зворотного
	glutReshapeFunc(reshape);
	//initGL();
	glutMainLoop(); // Вхід у цикл обробки подій GLUT
	return 0;
}
