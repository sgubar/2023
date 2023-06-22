#include <GL/glut.h>
#include "figure.h"
#include <cmath>

int main(int argc, char** argv)
{
    // Ініціалізація GLUT та створення вікна
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotating Circles");

    // Встановлення функцій зворотного виклику
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // Встановлення кольору очищення та глибини
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    // Додавання колів до списку
    addCircle(-0.5f, 0.5f, 0.2f);  // Приклад додавання кола до списку
    addCircle(0.5f, 0.5f, 0.3f);
    addCircle(0.0f, -0.5f, 0.4f);

    // Вхід до головного циклу GLUT
    glutMainLoop();

    // Видалення списку після закриття програми
    destroyList();

    return 0;
}
