#include <GL/glut.h>
#include <stdlib.h>
#include "figure.h"

// початок списку
Square* list_head = NULL;

int main(int argc, char** argv)
{
    // створення вікна
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Rotating Squares");

    // Встановлення функцій зворотного виклику
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0);

    // Встановлення кольору очищення та глибини
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearDepth(1.0f);

    // Додавання квадратів
    list_head = addSquare(0.5f, 0.5f);
    addSquare(0.5f, -0.5f);
    addSquare(-0.0f, -0.5f);
    addSquare(-0.0f, 0.5f);

    // Вставка

    Square* secondSquare = list_head->next;
    if (secondSquare != NULL) {
        insertSquareAfter(secondSquare, 0.3f, 0.3f);
    }

    // Видалення першого квадрата
    if (list_head != NULL) {
        removeSquare(list_head);
    }

    // Входження у головний цикл GLUT
    glutMainLoop();

    // Видалення списку
    destroyList();

    return 0;
}
