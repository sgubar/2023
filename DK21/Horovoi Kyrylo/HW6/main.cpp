#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float a = 0.06f; //параметр рівнняня а
float b = 0.25f; //параметр рівняння b

// Функція, що викликатиметься для малювання сцени
void display()
{
    glClearColor(0.4f, 0.3f, 0.13f, 1.0f); // Фон коричневий 
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
    glColor3f(1.0f, 0.0f, 0.0f); // Колір графіка(Червоний)
    for (float t = 0; t <= 5 * M_PI; t += 0.1) {
        float x = a * exp(b*t) * cos(t);
        float y = a * exp(b*t) * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    // Малювання координатних осей
    glBegin(GL_LINE_STRIP);//Малювання Осі Y
    glColor3f(0.0f, 1.0f, 0.0f);//Зелений колір
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);//Малювання осі X
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    // Малювання позначок на координатних осях
    for (float x = -1.0; x <= 1.0; x += 0.05) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(x, -0.03);
        glVertex2f(x, 0.03);
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += 0.05) {
        glBegin(GL_LINE_STRIP);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex2f(-0.03, y);
        glVertex2f(0.03, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(500, 500); // Ширина та висота вікна
    glutInitWindowPosition(0, 0); // Положення вікна
    glutCreateWindow("HW 6 - Горовой Кирило"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного
    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
    return 0;
}