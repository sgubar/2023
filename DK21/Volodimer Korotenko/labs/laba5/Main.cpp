// ВАРІАНТ 9
#include <math.h>
#include<stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <gl/glut.h>
#define M_PI_2_90     1.57079632679489661923/90// один градус
float step = 0.3;// крок переміщення
float ZM = -3.0f;// фронтальні координати камери
float YM = 0.0f;// висота координати камери
float XM = 0.0f;// бокові координати камери
float AngleX = 0.0f;// кут камери відносно X
float AngleZ = 0.0f;// кут камери відносно Z
int X = 0,Y = 0;// попередні координати миші
unsigned int ScreenX = 0;// координати миши
unsigned int Screeny = 0;// координати миши
float Cube[][12] = { {1,1,1, -1,1,1, -1,-1,1, 1,-1,1},
                   {1,1,1, 1,1,-1, 1,-1,-1, 1,-1,1},
                   {1,1,1, 1,1,-1, -1,1,-1, -1,1,1},
                   {-1,-1,-1, -1,-1,1, -1,1,1 ,-1,1,-1},
                   {-1,-1,-1, -1,-1,1, 1,-1,1,1,-1,-1},
                   {-1,-1,-1, 1,-1,-1, 1,1,-1,-1,1,-1}
};// координати точок куба
float RandomClr[6][3];// масив кольорів граней

void RandomColor( float ArrayOfColor[][3], unsigned int Size ) {// наповнення масиву кольорів спатковимі значеннями від 0 до 1
   for( size_t i = 0; i < Size; i++ ) {
      for( size_t k = 0; k < 3; k++ ) {
         ArrayOfColor[i][k] = rand() / static_cast<float>( RAND_MAX );
      }
   }
}
void RenderCube() {
   glEnableClientState(GL_VERTEX_ARRAY);
      for( size_t i = 0; i < 6; i++ ) {// малювати окремо кожну грань
         glVertexPointer( 3, GL_FLOAT, 0, &Cube[i]);// передаю масив точок
         glColor3f( RandomClr[i][0], RandomClr[i][1], RandomClr[i][2] );// задаю кольор
         glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );// намалювати грань з отриманого масиву точок
      }
   glDisableClientState( GL_VERTEX_ARRAY );
}
void MoveCamera() {
   glRotatef(AngleX,1,0,0);// повернути камеру відносно X
   glRotatef( AngleZ, 0, 1, 0 );// повернути камеру відносно Z
   glTranslatef( XM, YM, ZM );// переміщення камери
}
void RenderScene() {
   // рендерінг
   glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
   glClear( GL_COLOR_BUFFER_BIT );
   glPushMatrix();
      MoveCamera();
      RenderCube();
   glPopMatrix();
   glFlush();
}
void Init() {
   ScreenX = GetSystemMetrics( SM_CXFULLSCREEN );// Ширина екрану по Х
   Screeny = GetSystemMetrics( SM_CYFULLSCREEN );// Ширина екрану по у
   RenderScene();
}
void KeyEvents(unsigned char Key, int x, int y) {
   // функція переміщення вперед/назад
   switch( Key ) {
      case'w':
         ZM += cos( AngleZ * M_PI_2_90 )*cos( AngleX* M_PI_2_90 )  * step;
         YM += sin( AngleX * M_PI_2_90 ) * step;;
         XM -= sin( AngleZ * M_PI_2_90 ) * step;
         break;
      case's':
         ZM -= cos( AngleZ * M_PI_2_90 ) * cos( AngleX * M_PI_2_90 ) * step;
         YM -= sin( AngleX * M_PI_2_90 ) * step;;
         XM += sin( AngleZ * M_PI_2_90 )*step;
         break;
      default:
         break;
   }
   RenderScene();
}
void MauseEvents(int x, int y) {

   // якщо курсор досягає краю екрану перемістити його до центру монітора
   if( x > ScreenX -10 || x < 10 ) {
      glutWarpPointer( ScreenX/2, Screeny/2 );
   }
   if( y > Screeny-10 || y < 10 ) {
      glutWarpPointer( ScreenX/2, Screeny/2 );
   }

   if( Y != y ) {// обмежите кут вертикальну виду
      if( AngleX < 80.0f && Y - y > 0 ) AngleX += 1;// повернути камеру вверх
      if( AngleX > -80.0f && Y - y < 0 ) AngleX -= 1;// повернути камеру вниз
   }

   if( X != x ) {
      if( X - x < 0 ) AngleZ += 1;// повернути камеру направо
      else AngleZ -= 1;// повернути камеру наліво
   }

   // інвертувати кут повороту вліво/вправо щоб не збільшувався нескінченно
   if( AngleZ >= 180.f ) {
      AngleZ = -AngleZ;
   } else if( AngleZ <= -180.0f ) {
      AngleZ = -AngleZ;
   }

   Y = y;
   X = x;
   RenderScene();
}

int main( int argc, char* argv[] ) {
   RandomColor( RandomClr,6 );// створити випадкові кольори

   glutInit( &argc, argv ); // Ініціалізація GLUT
   glutCreateWindow( "DK-21 varint 9" ); // Створення вікна із заданим ім'ям

   glFrustum( -1, 1, 1, -1, 1, 80 );// перехід із ортогонально до перспективного виду

   // Реєстрації функції зворотного виклику
   glutDisplayFunc( Init ); 
   glutKeyboardFunc( KeyEvents );
   glutPassiveMotionFunc( MauseEvents );

   glutSetCursor( GLUT_CURSOR_NONE );// сховати курсор
   glutFullScreen(); // на весь екран
   glutMainLoop(); // Вхід у цикл обробки подій GLUT
   return 1;
}