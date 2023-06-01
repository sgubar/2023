#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#define _USE_MATH_DEFINES
#include <math.h>

float scaleX = 1.0f; // Масштабування по осі X
float scaleY = 1.0f; // Масштабування по осі Y
float translateX = 0.0f; // Переміщення по осі X
float translateY = 0.0f; // Переміщення по осі Y

void display()
{
    glClearColor(0.6f, 0.4f, 0.2f, 1.0f); // Фон коричневий
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(translateX, translateY, 0.0f);
    glScalef(scaleX, scaleY, 1.0f);

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f); // Зелений колір
    for (float t = 0.01f; t <= M_PI; t += 0.01f) {
        float x = sin(3 * t) * cos(t);
        float y = sin(3 * t) * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // Синій колір
    glVertex2f(-10.0f, 0.0f);
    glVertex2f(10.0f, 0.0f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glColor3f(0.0f, 0.0f, 1.0f); // Синій колір
    glVertex2f(0.0f, -10.0f);
    glVertex2f(0.0f, 10.0f);
    glEnd();

    for (float x = -10.0f; x <= 10.0f; x += 1.0f) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f); // Білий колір
        glVertex2f(x, -0.1f);
        glVertex2f(x, 0.1f);
        glEnd();
    }

    for (float y = -10.0f; y <= 10.0f; y += 1.0f) {
        glBegin(GL_LINE_STRIP);
        glColor3f(1.0f, 1.0f, 1.0f); // Білий колір
        glVertex2f(-0.1f, y);
        glVertex2f(0.1f, y);
        glEnd();
    }

    glFlush();
}

void specialKeys(int key, int x, int y)
{
    const float translationSpeed = 0.1f;
    const float scaleSpeed = 0.1f;

    switch (key) {
    case GLUT_KEY_LEFT:
        translateX -= translationSpeed;
        break;
    case GLUT_KEY_RIGHT:
        translateX += translationSpeed;
        break;
    case GLUT_KEY_DOWN:
        translateY -= translationSpeed;
        break;
    case GLUT_KEY_UP:
        translateY += translationSpeed;
        break;
    case GLUT_KEY_PAGE_UP:
        scaleX += scaleSpeed;
        scaleY += scaleSpeed;
        break;
    case GLUT_KEY_PAGE_DOWN:
        scaleX -= scaleSpeed;
        scaleY -= scaleSpeed;
        break;
    }

    glutPostRedisplay();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Graph");
    glutDisplayFunc(display);
    glutSpecialFunc(specialKeys); // Додано обробник спеціальних клавіш
    glutMainLoop();

    return 0;
}
