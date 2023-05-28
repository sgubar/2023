#include <GL/glut.h> // варіант завдання 17

char title[] = "Parallelepiped Zooming in/out keys KEY_DOWN, KEY_UP";
bool perspective = true;
bool moveScene = false;

float a_x = 45, a_z = 0;
float zoom_param = -7.0;
float zoom_delta = 0.1;

void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 0.f);
    glClearDepth(1.f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glShadeModel(GL_SMOOTH);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // Очищення буферу кольору
    GL_DEPTH_BUFFER_BIT); // Очищення буферу глибини
    glMatrixMode(GL_MODELVIEW); // Вибір матриці
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param); // Зміщення об'єкта у глибину екрану
    glRotatef(a_z, 0, 0, 1); // Обертання навколо осі z
    glRotatef(a_x, 1, 0, 0); // Обертання навколо осі x


    glBegin(GL_POLYGON); //основа піраміди
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.95f, 0.0f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //грані
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(1.0f, 0.5f, 0.0f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.95f, 0.0f, 0.3f);
        glVertex3f(0.0, 1.0f, 0.0f);

        glColor3f(0.0f, 0.5f, 1.0f);
        glVertex3f(0.95f, 0.0f, 0.3f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(0.0, 1.0f, 0.0f);
    glEnd();

    glutSwapBuffers(); // Обмін буферів кадру
    // (використовується подвійна буферизація)
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void specialKeyCallback(int key, int x, int y)
{
    switch (key) {
        case GLUT_KEY_UP:
            zoom_param += zoom_delta;
            break;
        case GLUT_KEY_DOWN:
            zoom_param -= zoom_delta;
            break;
        default:
            return;
    }

    glutPostRedisplay();
}

void Timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(30, Timer, 0);
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);// Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE);// Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480);// Встановлення розміру вікна
    glutInitWindowPosition(50, 50);// Встановлення положення вікна
    glutCreateWindow(title);// Створення вікна із заданим ім'ям
    glutDisplayFunc(display);// Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape);// Реєстрація обробника запиту масштабування
    glutSpecialFunc(specialKeyCallback);// Реєстрація обробника подій клавіатури
    glutTimerFunc(0, Timer, 0);// Запуск та реєстрація обробки таймера
    initGL();
    glutMainLoop();//нескінченний цикл обробки
    glutMainLoop();//нескінченний цикл обробки
    return 0;
}
