#include <GL/glut.h> 

char title[] = "Lab 5 Bezuhlova Dasha";

//Глобальні змінні
float a_z = 0, zdelta = 1.2f;
float zoom_param = -7.0;

//Ініціалізація OpenGL
void initGL(void)
{
    glClearColor(0.f, 0.f, 0.f, 0.f);//Чорний фон
    glClearDepth(1.f);//Глибина фону
    glEnable(GL_DEPTH_TEST);//Дозвіл на тестування глибини
    glDepthFunc(GL_LEQUAL);//Тип функції тестування глибини
    glShadeModel(GL_SMOOTH);//Дозвіл гладкого зафарбовування
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);//Корекція перспективи
}

//Малювання сцени
void display()
{
    glClear(GL_COLOR_BUFFER_BIT |//Очищення буферу кольору та буферу глибини
        GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);//Вибір матриці модель-вигляд
    glLoadIdentity();//Скидання параметрів матриці шляхом завантаження одиничної матриці

    glTranslatef(0.f, 0.f, zoom_param);//Зміщення об'єкта у глибину екрану
    glRotatef(a_z, 0, 0, 1);//Обертання навколо осі Z (31 строка удалена)

    glBegin(GL_QUADS); // Куб складається з 6 квадратів (чотирикутників)

    // Верхня грань (y = 1.0f)
    glColor3f(0.0f, 1.0f, 0.0f); // Зелена
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);

    // Нижня грань (y = -1.0f)
    glColor3f(1.0f, 0.5f, 0.0f); // Помаранчева
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Передня грань (z = 1.0f)
    glColor3f(1.0f, 0.0f, 0.0f); // Червона
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    // Задня грань (z = -1.0f)
    glColor3f(1.0f, 1.0f, 0.0f); // Жовта
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Ліва грань (x = -1.0f)
    glColor3f(0.0f, 0.0f, 1.0f); // Синя
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Права грань (x = 1.0f)
    glColor3f(1.0f, 0.0f, 1.0f); // Пурпурова
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd(); // Завершення малювання кубу

    glutSwapBuffers(); // Обмін буферів кадру
    // (використовується подвійна буферизація)
}

//Фкнкція обробки події, що виникає при масштабуванні вікна
void reshape(int width, int height)
{
    //Обчислення відношення сторін вікна нового розміру
    if (height == 0)//Щоб не було ділення на 0
        height = 1;
    GLfloat aspect = (GLfloat)width / (GLfloat)height;

    glViewport(0, 0, width, height);//Встановлення розміру поля огляду відповідно до нових розмірів

    //Встановалення параметрів проекційної матриці
    glMatrixMode(GL_PROJECTION);//Вибір матриці проекції
    glLoadIdentity();//Скидання матриці

    gluPerspective(45.0f, aspect, 0.1f, 100.0f);//Використання перспективи проекції
}

void specialKeyCallback(int key, int x, int y)//Функція обробки події, що виникає при натисканні клавіш на клавіатурі
{
    if (key == GLUT_KEY_LEFT) {//Ліва стрілочка - обертання  відносно осі Z проти годинникової стрілки 
        a_z += zdelta;

    }
    else if (key == GLUT_KEY_RIGHT) {//Права стілочка - обертання відносно осі Z за годинниковою стрілкою
        a_z -= zdelta;
    }

}

void Timer(int value)
{
    glutPostRedisplay();// Генерування запиту на перемалювання 
    glutTimerFunc(30, Timer, 0);// Новий запуск таймера
}

//Головна функція
int main(int argc, char* argv[])
{
    glutInit(&argc, argv);//Ініціалізація GLUT
    glutInitDisplayMode(GLUT_DOUBLE); //Увімкнення подвійної буферизації
    glutInitWindowSize(640, 480);//Встановлення розміру вікна   
    glutInitWindowPosition(50, 50);//Встановлення положення вікна
    glutCreateWindow(title);//Створення вікна з ім'ям
    glutDisplayFunc(display);//Реєстрація обробника запиту перемалювання
    glutReshapeFunc(reshape);//Реєстрація обробника запиту на масштабування
    glutSpecialFunc(specialKeyCallback);//Реєстрація обробника подій клавіатури
    glutTimerFunc(0, Timer, 0);//Запуск таймера
    initGL();//Ініціалізація OpenGL
    glutMainLoop();//Вхід у цикл обробки подій
    return 0;
}