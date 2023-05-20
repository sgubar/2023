#include "FigurList.h"
#include <time.h>
#include <stdlib.h>
#include <gl/glut.h>
float SCALE = 0.1;// степінь масштабування
int t = 1000 / 30; // Період обертання фігури навколо початку координат (в даному прикладі робимо 1 оберт за 24 кадри/с)
float theta_spd = 360.0f / t; // Кут оберту між кадрами
float theta = 0.0f; // Кут оберту як глобальна змінна
ListOfRectangle* List = 0;// Наш список фігур
void display() {
   PrintListOfRectangle( List );// Малювання фігур по одній
   glFlush();// Запит на малювання сцени

}
void timer_dis( int v ) {
   glClear( GL_COLOR_BUFFER_BIT );// Очищуємо буфер щоб зображення не накладалися

   // параметри обертання буде покладено в стек перетворень
   glPushMatrix();
   glRotatef( theta, 0.0f, 0.0f, 1.0f );

   PrintListOfRectangle(List);// Малювання фігур по одній
   glFlush();// Запит на малювання сцени
   glPopMatrix();// Повернення до початкових налаштувань виду сцени
   glutTimerFunc( t, timer_dis, 0 );// Перезапуск таймера
   
   theta += theta_spd;// Оновлення кута оберту
   if( theta >= ( 360 ) ) {
      theta = 0;
   }
}
int main( int argc, char* argv[] ) {
   srand( time( 0 ) );// оновлення насіння псевдовипадкових чисел
   Rectangle* Rectangle = CreateRandomRectangle( -10, 10 );// створення псевдовипадкового прямокутника
   List = CreateListOfRectangle( Rectangle );

   Rectangle = CreateRandomRectangle( -10, 10 );// створення псевдовипадкового прямокутника
   AddToEndArray( List, Rectangle );// додати прямокутник у кінець списку

   Rectangle = CreateRandomRectangle( -10, 10 );// створення псевдовипадкового прямокутника
   AddAfterIndex( List, Rectangle, 1 );//додати за індексом. У цьому випадку заминити прямокутників

   Rectangle = CreateRandomRectangle( -10, 10 );// створення псевдовипадкового прямокутника
   AddAfterIndex( List, Rectangle, 2 );//додати за індексом. У цьому випадку додати новий елемент списку

   List = DeleteByIndex( List, 1 );//видалення за індексом

   glutInit( &argc, argv );// ініціалізація opengl
   glutCreateWindow( "DK-21 varint 9" );// створення окна
   glutDisplayFunc( display );// головна отрисовка окна
   glutFullScreen();// на весь екран
   glScaled( SCALE, SCALE, 0 ); // масштабування окна
   glutTimerFunc( 0, timer_dis, 0 );// постійно повторювати передану функцію після вказівок проміжуток часу (0сек.)
   glutMainLoop();// почати нескінченний цикл роботи
   FreeFiguresList( List );// після завершення роботи очистити пам'ять
   return 0;
}