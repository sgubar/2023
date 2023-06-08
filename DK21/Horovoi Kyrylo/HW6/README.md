Домашня Робота 6

Варіант 4:

Колір графіка: Червоний

Колір координатних осей та поділок: Зелений

Колір фону: Коричневий

Рівняння:

![изображение](https://github.com/sgubar/2023/assets/114906131/3d466767-8eb0-4ba7-882e-2903f9374b36)


Значення а дорівнює 0.06, але може бути змінено.

Контрольні запитання

   Напишіть, які функції Ви імплементували та коротко опишіть їхнє призначення.

    Я імплементував функцію display() яка відповідає за відображення - вона встановлює колір фону, малює графік, координатні осі та їх поділки.

   Які функції OpenGL Ви застосовували для ініціалізації роботи з графікою (початок роботи з OpenGL, налаштування вікна)? Яке їхнє призначення?

    glutInit(&argc, argv) -- ініціалізує Glut

    glutInitWindowSize(500, 500) -- задає розміри вікна, де аргументи - ширина та висота (у пікселях)

    glutInitWindowPosition(0, 0) -- задає початкову позицію вікна, де параметри -- значення x та y лівого верхнього кута вікна

    glutCreateWindow("HW 6 - Горовой Кирило") -- задає назву вікна, яка буде відображатися згори; аргумент - назва вікна

   Які функції OpenGL Ви застосовували для створення графічних примітивів? Які параметри примітивів налаштовуються через ці функції?

    glBegin(GL_LINE_STRIP) -- початок малювання ліній

    glEnd() -- кінець малювання ліній

    glColor3f(1.0f, 1.0f, 1.0f) -- встановлення кольору малювання, аргументи - значення red, green та blue відповідно (значення від 0.0 до 1.0)

    glVertex2f(x, y) -- задає точку (вершину). При малюванні в режимі GL_LINE_STRIP точки будуть послідовно з'єднуватися

    glFlush() -- виконує малювання

   Які функції OpenGL Ви застосовували для налаштування фону? Які параметри фону налаштовуються через ці функції?

    glClearColor(0.4f, 0.3f, 0.13f, 1.0f) -- задає колір фону, аргументи - значення red, green, blue та прозорість відповідно (значення від 0.0 до 1.0)

   Які ще існують типи графічних примітивів OpenGL?

    GL_POINTS -- просто точки

    GL_LINES -- лінії

    GL_LINE_STRIP -- ламана лінії (використовувалася під час виконання цієї роботи)

    GL_LINE_LOOP -- замкнена ламана лінія

    GL_TRIANGLES -- трикутник

    GL_TRIANGLE_STRIP -- 'массив' трикутників з'єднаних послідовно

    GL_TRIANGLE_FAN -- трикутники, які мають спільну вершину; кожен наступний трикутник має спільну сторону з попереднім трикутником

    GL_QUADS -- чотирикутники

    GL_QUAD_STRIP -- послідовно з'єднанні чотирикутники

    GL_POLYGON -- багатокутник
