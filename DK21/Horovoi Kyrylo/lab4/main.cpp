#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// ����� ���� �� ���� �����
char title[] = "Գ���� �����������";
int width = 800, height = 800;

int t = 1000 / 24; // ����� ��������� ������ ������� ������� ���������
float theta_spd = 360.0f / t; // �������� ������
float theta = 0.0f; // ��� ������(�����)
FigureList_s* figlist; // ��� ������ �����

//������� ���������
void display()
{
    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();
}

// ������� ��������� ������� ����� ��������� ����� �� ���. �������
void timer_dis(int v)
{
    // ������� �����
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);

    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();

    // ���������� �� ���������� ����������� ���� �����
    glPopMatrix();

    // ���������� �������
    glutTimerFunc(t, timer_dis, 0);

    // ��������� ���� ������
    theta -= theta_spd;
    if (theta <= (-360)) {
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[3], * points2[3], * points3[3], * points4[3];
    Figure_s* figure1, * figure2, * figure3, * figure4;

    // �������� ������ �����
    figlist = createFigList();

    // ��������� ����� � ��������� �� ������
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

    // ��������� ����� ������ � ������
    removeFigFromFigListAtIndex(figlist, 1);

    points4[0] = createPoint(-40, 10);
    points4[1] = createPoint(-60, 10);
    points4[2] = createPoint(-40, 50);
    figure4 = createFigure(points4, createColor(0.07, 0.65, 0.75));
    //������� ������ �� ���� �����
    insertFigToFigListAtIndex(figlist, 1, figure4);

    // ���������� ���������� OpenGL
    glutInit(&argc, argv);
    // ��������� ����
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // �������� display �� ������� ���������
    glutDisplayFunc(display);
    // ������ ��������� ������ ��� ����, ��� ������ ���������� ������ ���� �������
    glutTimerFunc(0, timer_dis, 0);
    // ��������� �������� ���� OpenGL
    glutMainLoop();

    return 0;
}
