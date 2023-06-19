#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

void display()
{
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  
    glClear(GL_COLOR_BUFFER_BIT); 

    
    glBegin(GL_LINE_STRIP); 
    glColor3f(1.0f, 0.0f, 0.0f); 
    for (float t = -3 M_PI; t <= 3 M_PI; t += 0.1) {
        float x = t - sin(t);
        float y = 1 - cos(t);
        glVertex2f(x, y);
    }
    glEnd();

    
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0, -1.0);
    glVertex2f(0.0, 1.0);
    glEnd();
    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glEnd();

    
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
    glFlush(); 
}



int int main(int argc, char* argv[])
{
    glutInit(&argc, argv); 
    glutInitWindowSize(500, 500); 
    glutInitWindowPosition(0, 0); 
    glutCreateWindow("HW 6 - Bezuhlova Dasha"); 
    glutDisplayFunc(display);
    glutMainLoop(); 
    return 0;
}