#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// Розмір вікна та його назва
char title[] = "Фігури обертаються";
int width = 800, height = 800;

int t = 1000 / 24; // Період обертання фігури навколо початку координат
float theta_spd = 360.0f / t; // Швидкість оберту
float theta = 0.0f; // Кут оберту(змінна)
FigureList_s* figlist; // Наш список фігур

//Функція малювання
void display()
{
    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();
}

// Функція оновлення малюнку через обертання сцени за год. стрілкою
void timer_dis(int v)
{
    // Очищуємо буфер
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // Малювання фігур по одній
    drawFigList(figlist);

    // Запит на малювання сцени
    glFlush();

    // Повернення до початкових налаштувань виду сцени
    glPopMatrix();

    // Перезапуск таймера
    glutTimerFunc(t, timer_dis, 0);

    // Оновлення кута оберту
    theta -= theta_spd;
    if (theta <= (-360)) {
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3], * points2[3], * points3[3], * points4[3];
    Figure_s* figure1, * figure2, * figure3, * figure4;

    // Створимо список фігур
    figlist = createFigList();

    // Створення фігур і додавання до списку
    points1[0] = createPoint(0, 50);
    points1[1] = createPoint(0, 0);
    points1[2] = createPoint(30, 0);
    figure1 = createFigure(points1, createColor(0.36, 0.58, 0.19));

    addFigToFigList(figlist, figure1);

    points2[0] = createPoint(-70, 14);
    points2[1] = createPoint(-78, 59);
    points2[2] = createPoint(12, 45);
    figure2 = createFigure(points2, createColor(1.0, 0.58, 0.19));

    addFigToFigList(figlist, figure2);

    points3[0] = createPoint(-40, -40);
    points3[1] = createPoint(20, -40);
    points3[2] = createPoint(20, -80);
    figure3 = createFigure(points3, createColor(0.83, 0.36, 0.92));

    addFigToFigList(figlist, figure3);

    // Видалення другої фігруи зі списку
    removeFigFromFigListAtIndex(figlist, 1);

    points4[0] = createPoint(-40, 10);
    points4[1] = createPoint(-60, 10);
    points4[2] = createPoint(-40, 50);
    figure4 = createFigure(points4, createColor(0.07, 0.65, 0.75));
    //Вставка фігури на місце другої
    insertFigToFigListAtIndex(figlist, 1, figure4);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    // Створюємо вікно
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Реєструємо display як функцію малювання
    glutDisplayFunc(display);
    // Одразу запускаємо таймер для того, щоб фігури обертались одразу після запуску
    glutTimerFunc(0, timer_dis, 0);
    // Запускаємо головний цикл OpenGL
    glutMainLoop();

    return 0;
}
