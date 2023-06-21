#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>

// Глобальні змінні
char title[] = "Cube";
bool perspective = true;
bool moveScene = false;
int mouse_x,
mouse_y;
float a_z = 0;
float zoom_param = -7.0;
float angle = 0.0f;


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
	    glClear(GL_COLOR_BUFFER_BIT |
    GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0.f, 0.f, zoom_param);
    glRotatef(a_z, 0, 0, 1);


    glBegin(GL_POLYGON);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f( 0.0f, 0.0f, 1.0f);
        glVertex3f(-0.95f, 0.0f, 0.3f);
        glVertex3f(-0.58f, 0.0f, -0.8f);
        glVertex3f(0.58f, 0.0f, -0.8f);
        glVertex3f(0.95f, 0.0f, 0.3f);
    glEnd();
    /*

    glBegin(GL_TRIANGLES); 
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
    */

    glutSwapBuffers();

		
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

void Update(int)
{
	angle += 1.0f;
	if (angle > 360) {
		angle -= 360;
	}
	glutPostRedisplay();
        glutTimerFunc(25, Update, 0);
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
    initGL(); // Ініціалізація OpenGL
    glutMainLoop(); // Вхід у головний нескінченний цикл обробки
    // подій
return 0;
}
