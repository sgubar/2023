#include <windows.h>
#include <GL/glut.h>
#define _USE_MATH_DEFINES 
#include <math.h>

#include "point.h"
#include "Square.h"


char title[] = "Rotating Square";
int curr_width = 600, curr_height = 600;

const int t = 1000 / 24;
float theta_spd = 360.0f / t;
float theta = 0.0f;
SquareList_s* rectlist;

void display()
{

    drawSquareList(rectlist);


    glFlush();
}


void timer_dis(int v)
{

    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
    glRotatef(theta, 0.0f, 0.0f, 1.0f);


    drawSquareList(rectlist);

   
    glFlush();

   
    glPopMatrix();

    glutTimerFunc(t, timer_dis, 0);

   
    theta += theta_spd;
    if (theta >= (360)) {
        theta = 0;
    }
}


int main(int argc, char* argv[])
{
    Point* points1[2];
    Point* points2[2];
    Point* points3[2];
    Point* points4[2];
  
    Square_s* figure1;

   
    rectlist = createSquareList();

   
    points1[0] = createPoint(60, 60);
    points1[1] = createPoint(30, 30);
    figure1 = createSquare(points1, createColor(1.0, 1.0, 0.0));
    addSquareToSquareList(rectlist, figure1);

   
    glutInit(&argc, argv);
  
    glutInitWindowSize(curr_width, curr_height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(title);
    
    glutDisplayFunc(display);
  
    glutTimerFunc(0, timer_dis, 0);
  
    glutMainLoop();

    return 0;
}
