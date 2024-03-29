1. Які функції для роботи безпосередньо з OpenGL ви імплементували? Коротко опишіть їхнє призначення.
void display() -- малювання фігур на початку програми на початковій позиції

void timer_dis(int v) -- перемалюває фігури кожний інтервал часу

drawFigList( FigureList_s* figlist) -- малює фігуру
2. Яке призначення двозв’язного списку в цій лабораторній роботі? Імплементація якої функції роботи зі складовими списку дозволяє «поєднати» функціонал двозв’язного списку з OpenGL?
Список потрібен для того, щоб не треба було малювати кожну фігуру окремо, адже програма малює одразу всі фігури з цього списку, в не залежності від того, скільки фігур в ньому збережено. Функція void drawRectangleList малює всі елементи списку.

3. За допомогою якого функціоналу OpenGL (очікування, обробка подій від таймера) у Вашій роботі реалізовано анімацію обертання?
glutTimerFunc(0, timer_dis, 0) -- запускає таймер

void timer_dis(int v) -- функція, в якій реалізовано перемалювання зображення

 glutTimerFunc(t, timer_dis, 0) -- перезапуск таймера зі значенням затримки 't' (яка розраховувалася за формулою 1000 / 24, завдяки чому зображення буде оновлюватися 24 рази на секунду)
 
4. Якими функціями OpenGL і як саме Ви користувались для безпосередньо обертання фігур?
glPushMatrix() -- додає значення до стеку матриць

glRotatef(theta, 0.0f, 0.0f, 1.0f) -- безпосередньо обертає фігури на кут theta, три інші аргументи - вектор осі відносно якої здійснюється поворот

glPopMatrix() -- видаляє елемент з стеку матриць

5. Які існують команди роботи з матрицями трансформації в OpenGL?
glTranslate -- зміщення

glScale -- масштабування

glRotate -- поворот

glLoadIdentity -- завантаження одиничної матриці

glPushMatrix, glPopMatrix -- збереження та відновлення матриць

glLoadMatrix -- завантаження довільної матриці

glGet -- отримання заданої поточної матриці

6. Які функції реєстрації зворотних викликів OpenGL зазвичай використовуються для анімацій?
glutDisplayFunc(display) -- задає функцію малювання (початкового) display

glutTimerFunc(t, timer_dis, 0) -- задає функцію timer_dis, яка спрацює через t мілісекунд; саме у функції timer_dis малюється кожен кадр анімації
