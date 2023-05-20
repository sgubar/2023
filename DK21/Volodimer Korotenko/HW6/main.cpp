#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
// ���� ������� ���� �������
float Tmax = M_PI;
float Tmin = 0.0;

float scale = 0.25;// ������ �������������

// ������� ���������� ��������� �
float parameterX( float t ) {
   return sin( 3 * t ) * cos( t );
}

// // ������� ���������� ��������� �
float parameterY( float t ) {
   return sin( 3 * t ) * sin( t );
}
 //�������, �� ��������������� ��� ��������� �����
void display() {
   glClearColor( 1.0f, 0.5f, 0.0f, 1.0f ); // ��� ����������
   glClear( GL_COLOR_BUFFER_BIT ); // �������� ������ �������

   glBegin( GL_LINE_STRIP );
   glColor3f( 0.0f, 1.0f, 0.0f );// ������� ����
   for( float t = Tmin; t <= Tmax; t += 0.01 ) {
      float x = parameterX( t);
      float y = parameterY( t );
      glVertex2f( t, y );
   }
   glEnd();

   // ��������� ������������ ����
   glBegin( GL_LINES );
   glColor3f( 0.0f, 0.0f, 1.0f );
   glVertex2f( 0.0, -1.0/ scale );
   glVertex2f( 0.0, 1.0/ scale );
   glEnd();
   glBegin( GL_LINES );
   glColor3f( 0.0f, 0.0f, 1.0f );
   glVertex2f( -1.0/ scale, 0.0 );
   glVertex2f( 1.0/ scale, 0.0 );
   glEnd();

   // ��������� �������� �� ������������ ����
   for( float x = 0; x <= 1.0 / scale; x += 0.5 ) {
      glBegin( GL_LINES );
      glColor3f( 0.0f, 0.0f, 1.0f );
      glVertex2f( x, -0.1 );
      glVertex2f( x, 0.1 );
      glVertex2f( -x, -0.1 );
      glVertex2f( -x, 0.1 );
      glEnd();
   }
   for( float y = 0; y <= 1.0/ scale; y += 0.5 ) {
      glBegin( GL_LINES );
      glColor3f( 0.0f, 0.0f, 1.0f );
      glVertex2f( -0.05, -y );
      glVertex2f( 0.05, -y );
      glVertex2f( -0.05, y );
      glVertex2f( 0.05, y );
      glEnd();
   }
   glFlush(); // �������� ��������
}

/* Program entry point */

int main( int argc, char* argv[] ) {
   glutInit( &argc, argv ); // ����������� GLUT
   glutCreateWindow( "DK-21 varint 9" ); // ��������� ���� �� ������� ��'��
   glutDisplayFunc( display ); // ��������� ������� ����������
   glScaled( scale, scale,0); // ������������� ����
   glutFullScreen(); // �� ���� �����
   glutMainLoop(); // ���� � ���� ������� ���� GLUT
   return 0;
}