#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float a = 1.3f; 
float b = 2.3f;

// Функція, що викликатиметься для малювання сцени
void display()
{
    glClearColor(1.0f, 1.0f, 1.0, 1.0f); // Фон білий
    glClear(GL_COLOR_BUFFER_BIT); // Очищення буферу кольору

    // Малювання серії відрізків, що є графіком функції
    glBegin(GL_LINE_STRIP); // Кожна пара вершини задає відрізок
    glColor3f(0.0f, 1.0f, 0.0f); 
    for (float t = -M_PI; t <= M_PI; t += 0.1) {
        float x = a * pow(cos(t), 2) - b * cos(t);
        float y = a * sin(t) * cos(t) - b * cos(t);
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
    for (float x = -1.0; x <= 1.0; x += 0.1) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(x, -0.05);
        glVertex2f(x, 0.05);
        glEnd();
    }
    for (float y = -1.0; y <= 1.0; y += 0.1) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2f(-0.05, y);
        glVertex2f(0.05, y);
        glEnd();
    }
    glFlush(); // Виконати малювання
}



int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitWindowSize(400, 400); // Ширина та висота вікна
    glutInitWindowPosition(50, 50); // Положення вікна
    glutCreateWindow("HW 6 - Voloskyi DK-21"); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація функції зворотного
    // виклику для малювання вікна
    glutMainLoop(); // Вхід у цикл обробки подій GLUT
    return 0;
}
