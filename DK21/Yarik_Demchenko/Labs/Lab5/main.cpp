#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

// Глобальні змінні
char title[] = "Demchenko Lab 5 || Z Axis rotation";
float a_z = 0, a_x = 0;
float a_z_speed = 1, a_x_speed = 0;
float zoom_param = -7.0;


// Ініціалізація OpenGL
void initGL()
{
    glClearColor(0.f, 0.f, 0.f, 1.f); // Фон - чорний та прозорий
    glClearDepth(1.f); // Глибина фону - найбільш віддалена
    glEnable(GL_DEPTH_TEST); // Дозвіл тестування глибини
    glDepthFunc(GL_LEQUAL); // Тип функції тестування глибини
    glShadeModel(GL_SMOOTH); // Дозвіл гладкого зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Корекція перспективи
}


// Функція обробки запиту на перемалювання. Виконує малювання сцени.
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | // Очищення буферу кольору
    GL_DEPTH_BUFFER_BIT); // та буферу глибини
    glMatrixMode(GL_MODELVIEW); // Вибір матриці модель-вигляд
    glLoadIdentity(); // Скидання параметрів матриці шляхом
    // завантаження одиничної матриці

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


// Функція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height)
{
    // Обчислення відношення сторін вікна нового розміру
    if (height == 0) // Перевірка для уникнення ділення на 0
    height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    // Встановлення розміру поля огляду відповідно до нових розмірів вікна
    glViewport(0, 0, width, height);

    // Встановлення параметрів проекційної матриці
    glMatrixMode(GL_PROJECTION); // Вибір матриці проекції
    glLoadIdentity(); // Скидання матриці

    // Використання перспективної проекції з
    // параметрами fovy = 45, aspect, zNear = 0.1 та zFar = 100
    gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}


// Функція обробки події, що виникає при натисканні клавіш клавіатури
void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
        case 27: // Esc
            exit(0);
            break;
        case 32: // Space - change a_z rotation direction
            a_z_speed *= -1.0f;
            break;
        case 49: // 1 - start/stop a_x rotation
            a_x_speed = 1 - a_x_speed;
            break;
    }
}



// Функція обробки події, що виникає при спрацюванні таймеру
void Timer(int value)
{
    glutPostRedisplay(); // Генерування запиту на перемалювання
    // сцени викликає функцію display()
    a_z += a_z_speed; //зміна кута повороту по z
    a_x += a_x_speed; //зміна кута повороту по x
    if (a_z >= 360.0f) a_z -= 360.0f;
    if (a_x >= 360.0f) a_x -= 360.0f;

    glutTimerFunc(30, Timer, 0); // Новий запуск таймера на 30 мс
}


// Головна функція: програма GLUT виконується як консольний додаток
int main(int argc, char* argv[])
{
    glutInit(&argc, argv); // Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); // Ввімкнення подвійної буферизації
    glutInitWindowSize(640, 480); // Встановлення розміру вікна
    glutInitWindowPosition(50, 50); // Встановлення положення вікна
    glutCreateWindow(title); // Створення вікна із заданим ім'ям
    glutDisplayFunc(display); // Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape); // Реєстрація обробника запиту масштабування
    glutKeyboardFunc(keyboard); // Реєстрація обробника подій клавіатури

    glutTimerFunc(0, Timer, 0); // Запуск та реєстрація обробки таймера
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки
    // подій
return 0;
}