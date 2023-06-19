#include <windows.h>
#include <GL/glut.h> //
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>

#include "point.h"
#include "figure.h"

// ����� �� ������ ����
char title[] = "Rotating Graph";
int curr_width = 600, curr_height = 600;

int t = 1000 / 24; // ����� ��������� ������ ������� ������� ��������� (� ������ ������� ������ 1 ����� �� 24 �����/�)
float theta_spd = 90.0f / t; // ��� ������ �� �������
float theta = 0.0f; // ��� ������ �� ��������� �����
FigureList_s* figlist; // ��� ������ �����

// � ����� ������� ������������� display() ���� ���� ��� �� ������ ������ ��������
// ��� ��������� ����� �� ���������� ��������
void display()
{
    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();
}

// �� ������� ����������� ����� t �� ���� ��������� ������� � ����������� ������
void timer_dis(int v)
{
    // ������� ����� ��� ���������� �� �����������
    glClear(GL_COLOR_BUFFER_BIT);

    // � ������ ������� ���������� ��������� �����,
    // ��������� ��������� ���� ��������� � ���� �����������
    glPushMatrix();
    glRotatef(theta, 0.5f, 1.0f, 1.0f);

    // ��������� ����� �� ����
    drawFigList(figlist);

    // ����� �� ��������� �����
    glFlush();

    // ���������� �� ���������� ����������� ���� �����
    glPopMatrix();

    // ���������� �������
    glutTimerFunc(t, timer_dis, 0);

    // ��������� ���� ������
    theta += theta_spd;
    if (theta >= (360)) {
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[4];
    Point* points2[4];
    Point* points3[4];
    Point* points4[4];
    Figure_s* figure1, * figure2, * figure3, * figure4;

    // �������� ������ �����
    figlist = createFigList();

    // �������� ������ � ������ �� �� ������
    points1[0] = createPoint(-20, -20);
    points1[1] = createPoint(20, -20);
    points1[2] = createPoint(60, 0);
    points1[3] = createPoint(-60, 0);
    figure1 = createFigure(points1, createColor(1.0, 0.0, 0.0));

    addFigToFigList(figlist, figure1);

    points2[0] = createPoint( 0, 0);
    points2[1] = createPoint(-10, 0);
    points2[2] = createPoint(-10, -10);
    points2[3] = createPoint(-0, -10);
    figure2 = createFigure(points2, createColor(1.0, 1.0, 0.0));

    addFigToFigList(figlist, figure2);

    points3[0] = createPoint(10, 10);
    points3[1] = createPoint(20, 10);
    points3[2] = createPoint(30, 40);
    points3[3] = createPoint(0, 40);
    figure3 = createFigure(points3, createColor(0.5, 0.5, 0.5));

    addFigToFigList(figlist, figure3);

    // ������� 2 ������ � ������ �� ����
    removeFigFromFigListAtIndex(figlist, 1);

    points4[0] = createPoint(-60, 50);
    points4[1] = createPoint(-30, 50);
    points4[2] = createPoint(-30, 10);
    points4[3] = createPoint(-80, 10);
    figure4 = createFigure(points4, createColor(0.0, 0.0, 1.0));

    insertFigToFigListAtIndex(figlist, 1, figure4);

    // ���������� ���������� OpenGL
    glutInit(&argc, argv);
    // ��������� ����
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    // �������� display �� ������� ��������� (� ������ ������� �����������)
    glutDisplayFunc(display);
    // ������ ��������� ������ ��� ����, ��� ������ ���������� ������ ���� �������
    glutTimerFunc(0, timer_dis, 0);
    // ��������� �������� ���� OpenGL
    glutMainLoop();

    return 0;
}