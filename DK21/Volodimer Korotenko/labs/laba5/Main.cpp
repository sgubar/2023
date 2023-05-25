// ��в��� 9
#include <math.h>
#include<stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <gl/glut.h>
#define M_PI_2_90     1.57079632679489661923/90// ���� ������
float step = 0.3;// ���� ����������
float ZM = -3.0f;// ��������� ���������� ������
float YM = 0.0f;// ������ ���������� ������
float XM = 0.0f;// ����� ���������� ������
float AngleX = 0.0f;// ��� ������ ������� X
float AngleZ = 0.0f;// ��� ������ ������� Z
int X = 0,Y = 0;// �������� ���������� ����
unsigned int ScreenX = 0;// ���������� ����
unsigned int Screeny = 0;// ���������� ����
float Cube[][12] = { {1,1,1, -1,1,1, -1,-1,1, 1,-1,1},
                   {1,1,1, 1,1,-1, 1,-1,-1, 1,-1,1},
                   {1,1,1, 1,1,-1, -1,1,-1, -1,1,1},
                   {-1,-1,-1, -1,-1,1, -1,1,1 ,-1,1,-1},
                   {-1,-1,-1, -1,-1,1, 1,-1,1,1,-1,-1},
                   {-1,-1,-1, 1,-1,-1, 1,1,-1,-1,1,-1}
};// ���������� ����� ����
float RandomClr[6][3];// ����� ������� ������

void RandomColor( float ArrayOfColor[][3], unsigned int Size ) {// ���������� ������ ������� ��������� ���������� �� 0 �� 1
   for( size_t i = 0; i < Size; i++ ) {
      for( size_t k = 0; k < 3; k++ ) {
         ArrayOfColor[i][k] = rand() / static_cast<float>( RAND_MAX );
      }
   }
}
void RenderCube() {
   glEnableClientState(GL_VERTEX_ARRAY);
      for( size_t i = 0; i < 6; i++ ) {// �������� ������ ����� �����
         glVertexPointer( 3, GL_FLOAT, 0, &Cube[i]);// ������� ����� �����
         glColor3f( RandomClr[i][0], RandomClr[i][1], RandomClr[i][2] );// ����� ������
         glDrawArrays( GL_TRIANGLE_FAN, 0, 4 );// ���������� ����� � ���������� ������ �����
      }
   glDisableClientState( GL_VERTEX_ARRAY );
}
void MoveCamera() {
   glRotatef(AngleX,1,0,0);// ��������� ������ ������� X
   glRotatef( AngleZ, 0, 1, 0 );// ��������� ������ ������� Z
   glTranslatef( XM, YM, ZM );// ���������� ������
}
void RenderScene() {
   // ��������
   glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
   glClear( GL_COLOR_BUFFER_BIT );
   glPushMatrix();
      MoveCamera();
      RenderCube();
   glPopMatrix();
   glFlush();
}
void Init() {
   ScreenX = GetSystemMetrics( SM_CXFULLSCREEN );// ������ ������ �� �
   Screeny = GetSystemMetrics( SM_CYFULLSCREEN );// ������ ������ �� �
   RenderScene();
}
void KeyEvents(unsigned char Key, int x, int y) {
   // ������� ���������� ������/�����
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

   // ���� ������ ������ ���� ������ ���������� ���� �� ������ �������
   if( x > ScreenX -10 || x < 10 ) {
      glutWarpPointer( ScreenX/2, Screeny/2 );
   }
   if( y > Screeny-10 || y < 10 ) {
      glutWarpPointer( ScreenX/2, Screeny/2 );
   }

   if( Y != y ) {// �������� ��� ����������� ����
      if( AngleX < 80.0f && Y - y > 0 ) AngleX += 1;// ��������� ������ �����
      if( AngleX > -80.0f && Y - y < 0 ) AngleX -= 1;// ��������� ������ ����
   }

   if( X != x ) {
      if( X - x < 0 ) AngleZ += 1;// ��������� ������ �������
      else AngleZ -= 1;// ��������� ������ �����
   }

   // ����������� ��� �������� ����/������ ��� �� ����������� ����������
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
   RandomColor( RandomClr,6 );// �������� �������� �������

   glutInit( &argc, argv ); // ����������� GLUT
   glutCreateWindow( "DK-21 varint 9" ); // ��������� ���� �� ������� ��'��

   glFrustum( -1, 1, 1, -1, 1, 80 );// ������� �� ������������ �� �������������� ����

   // ��������� ������� ���������� �������
   glutDisplayFunc( Init ); 
   glutKeyboardFunc( KeyEvents );
   glutPassiveMotionFunc( MauseEvents );

   glutSetCursor( GLUT_CURSOR_NONE );// ������� ������
   glutFullScreen(); // �� ���� �����
   glutMainLoop(); // ���� � ���� ������� ���� GLUT
   return 1;
}