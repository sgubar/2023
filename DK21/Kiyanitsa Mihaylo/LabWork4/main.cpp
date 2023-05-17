#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#include "point.h"
#include "rectangle.h"

// Назва та розміри вікна
char title[] = "Rotating Rectangle";
int curr_width = 600, curr_height = 600;

const int t = 1000 / 24; // Період обертання фігури навколо початку координат (в даному прикладі робимо 1 оберт за 24 кадри/с)
float theta_spd = 360.0f / t; // Кут оберту між кадрами
float theta = 0.0f; // Кут оберту як глобальна змінна
RectangleList_s* rectlist; // Наш список фігур

// В цьому прикладі викликатимемо display() лише один раз на почаку роботи програми
// для малювання фігур на початкових позиціях
void display()
{
    // Малювання фігур по одній
    drawRectangleList(rectlist);

    // Запит на малювання сцени
    glFlush();
}

// Ця функція викликається через t мс після увімкнення таймеру і перемальовує фігури
void timer_dis(int v)
{
    // Очищуємо буфер щоб зображення не накладалися
    glClear(GL_COLOR_BUFFER_BIT);

    // В нашому прикладі виконується обертання сцени,
    // параметри обертання буде покладено в стек перетворень
    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // Малювання фігур по одній
    drawRectangleList(rectlist);

    // Запит на малювання сцени
    glFlush();

    // Повернення до початкових налаштувань виду сцени
    glPopMatrix();

    // Перезапуск таймера
    glutTimerFunc(t, timer_dis, 0);

    // Оновлення кута оберту
    theta += theta_spd;
    if (theta >= (360)){
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[2];
    Point* points2[2];
    Point* points3[2];
    Point* points4[2];
    Point* points5[2];
    Point* points6[2];
    Point* points7[2];
    Point* points8[2];
    Point* points9[2];
    Point* points10[2];
    Rectangle_s *figure1, *figure2, *figure3, *figure4, *figure5, *figure6, *figure7, *figure8, *figure9, *figure10;

    // Створимо список фігур
    rectlist = createRectangleList();

    // Створимо фігури і додамо їх до списку
    points1[0] = createPoint(-20, 100);
    points1[1] = createPoint(20, 60);
    figure1 = createRectangle(points1, createColor(1.0, 1.0, 0.0));
    addRectangleToRectangleList(rectlist, figure1);

    points2[0] = createPoint(-50, -50);
    points2[1] = createPoint(0, 0);
    figure2 = createRectangle(points2, createColor(1.0, 1.0, 0.0));
    addRectangleToRectangleList(rectlist, figure2);

    points3[0] = createPoint(-20, 60);
    points3[1] = createPoint(20, -10);
    figure3 = createRectangle(points3, createColor(0.0, 1.0, 1.0));
    addRectangleToRectangleList(rectlist, figure3);

    points5[0] = createPoint(20, 60);
    points5[1] = createPoint(80, 40);
    figure5 = createRectangle(points5, createColor(1.0, 1.0, 0.0));
    addRectangleToRectangleList(rectlist, figure5);

    points6[0] = createPoint(-20, -10);
    points6[1] = createPoint(0, -80);
    figure6 = createRectangle(points6, createColor(0.0, 0.3, 1.0));
    addRectangleToRectangleList(rectlist, figure6);

    points7[0] = createPoint(0, -10);
    points7[1] = createPoint(20, -80);
    figure7 = createRectangle(points7, createColor(0.0, 0.0, 1.0));
    addRectangleToRectangleList(rectlist, figure7);

    points8[0] = createPoint(5, 90);
    points8[1] = createPoint(15, 80);
    figure8 = createRectangle(points8, createColor(0.07, 0.03, 0.14));
    addRectangleToRectangleList(rectlist, figure8);

    points9[0] = createPoint(-15, 90);
    points9[1] = createPoint(-5, 80);
    figure9 = createRectangle(points9, createColor(0.07, 0.03, 0.14));
    addRectangleToRectangleList(rectlist, figure9);

    points10[0] = createPoint(-15, 75);
    points10[1] = createPoint(15, 70);
    figure10 = createRectangle(points10, createColor(0.07, 0.03, 0.14));
    addRectangleToRectangleList(rectlist, figure10);

    // Замінимо 2 фігуру в списку на іншу
    removeRectangleFromRectangleListAtIndex(rectlist, 1);

    points4[0] = createPoint(-80, 60);
    points4[1] = createPoint(-20, 40);
    figure4 = createRectangle(points4, createColor(1.0, 1.0, 0.0));
    insertRectangleToRectangleListAtIndex(rectlist, 1, figure4);

    // Ініціалізуємо середовище OpenGL
    glutInit(&argc, argv);
    // Створюємо вікно
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // Реєструємо display як функцію малювання (в нашому прикладі початкового)
    glutDisplayFunc(display);
    // Одразу запускаємо таймер для того, щоб фігури обертались одразу після запуску
    glutTimerFunc(0, timer_dis, 0);
    // Запускаємо головний цикл OpenGL
    glutMainLoop();

    return 0;
}