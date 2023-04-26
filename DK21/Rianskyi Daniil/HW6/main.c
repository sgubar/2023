#include <GL/glut.h>
#include <math.h>

///////////////////////////////////////////// Кольори 
GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 }; /// Чорний 
GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 }; /// Білий
GLfloat green[] = { 0.0, 1.0, 0.0, 1.0 }; /// Зелений 

///////////////////////////////////////////// Функція дял виведення на екран 
void display() {
    ///////////////////////////////////////////// Очищення 
    glClear(GL_COLOR_BUFFER_BIT);

    ///////////////////////////////////////////// Встановлення колюру для осей
    glColor4fv(white);

    ///////////////////////////////////////////// Креслення координатних осей 
    glBegin(GL_LINES);
    glVertex2f(-10.0, 0.0);
    glVertex2f(10.0, 0.0);
    glVertex2f(0.0, -10.0);
    glVertex2f(0.0, 10.0);
    glEnd();

    ///////////////////////////////////////////// Поділки на координатних осях
    glBegin(GL_LINES);
    for (float i = -10.0; i <= 10.0; i += 1.0) {
        glVertex2f(i, -0.2);
        glVertex2f(i, 0.2);
        glVertex2f(-0.2, i);
        glVertex2f(0.2, i);
    }
    glEnd();

    ///////////////////////////////////////////// Колір для графіка
    glColor4fv(green);

    ///////////////////////////////////////////// Побудування графіків 
    glBegin(GL_LINE_STRIP);
    for (float t = -4 * M_PI; t <= 4 * M_PI; t += 0.01) { /// Умова 
        float x = exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 4), 3) * cos(t);
        float y = exp(cos(t)) - 2 * cos(4 * t) + pow(sin(t / 4), 3) * sin(t);
        glVertex2f(x, y);
    }
    glEnd();

    ///////////////////////////////////////////// Видалення 
    glFlush();
}

int main(int argc, char** argv) {
    ///////////////////////////////////////////// Ініціалізація GLUT та створення вікна 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Graph of the given function");

    ///////////////////////////////////////////// Колір фону 
    glClearColor(0.0, 0.0, 0.0, 0.0);

    ///////////////////////////////////////////// Область перегляду 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10.0, 10.0, -10.0, 10.0);

    ///////////////////////////////////////////// Функція малювання 
    glutDisplayFunc(display);

    ///////////////////////////////////////////// 
    glutMainLoop();

    return 0;
}
