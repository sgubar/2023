#include <GL/glut.h>
#include <math.h>

void display() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // задаємо білий колір фону
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0); // червоний колір графіка
    glBegin(GL_LINE_STRIP);
    for (float t = -3 * M_PI; t <= 3 * M_PI; t += 0.01) {
        float x = t - sin(t);
        float y = 1 - cos(t);
        glVertex2f(x, y);
    }
          glEnd();

     // Drawing the coordinate axes
     glColor3f(0.0f, 0.0f, 1.0f); // Green color
     glPushMatrix();
     glBegin(GL_LINES);
     glVertex2f(-1.0, 0.0);
     glVertex2f(1.0, 0.0);
     glEnd();
     glBegin(GL_LINES);
     glVertex2f(0.0, -1.0);
     glVertex2f(0.0, 1.0);
     glEnd();
     glPopMatrix();

     // Drawing the tick marks on the coordinate axes
     glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glPushMatrix();
     for (float x = -1.0; x <= 1.0; x += 0.1) {
         glBegin(GL_LINES);
         glVertex2f(x, -0.05);
         glVertex2f(x, 0.05);
         glEnd();
     }
     for (float y = -1.0; y <= 1.0; y += 0.1) {
         glBegin(GL_LINES);
         glVertex2f(-0.05, y);
         glVertex2f(0.05, y);
         glEnd();
    }
     glPopMatrix();

     glFlush(); // Perform drawing
     glutSwapBuffers();

}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("OpenGL Curve");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
