#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float a = 0.5; //значення параметра
// Функція, що викликатиметься для малювання сцени
void display()
{
    glColor3ub(0,0,0); // Фон чорний 
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
        glColor3f(0, 0, 1); // Синій колір
        for (float t = -M_PI; t <= M_PI; t += 0.1) {
            float x = 2 * a * cos(t) * (1 - cos(t));
	    float y = 2 * a * sin(t) * (1 - cos(t));
            glVertex2f(x, y);
        }
    glEnd();

    // Малювання жовтих координатних осей
    glBegin(GL_LINE_STRIP);
    	glColor3ub(255,255,0);    
    	glVertex2f(0.0, -1.0);
        glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
        glColor3ub(255,255,0); 
        glVertex2f(-1.0, 0.0);
        glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання жовтих позначок на координатних осях
    for( float x = -1.0; x <= 1.0; x += 0.1){
        glBegin(GL_LINE_STRIP);
        	glColor3ub(255,255,0);    
		glVertex2f(x, -0.05);
            	glVertex2f(x, 0.05);
        glEnd();
    }
    for( float y = -1.0; y <= 1.0; y += 0.1){
        glBegin(GL_LINE_STRIP);
            	glColor3ub(255,255,0);
            	glVertex2f(-0.05, y);
            	glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}

/* Program entry point */

int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(400, 400); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("графік-мафік"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного
    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
return 0;
}
