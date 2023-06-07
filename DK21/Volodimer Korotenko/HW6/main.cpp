#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#include <gl/glut.h>
// Çì³íí³ ïðîì³æêó ÷àñó ãðàô³êà
float Tmax = M_PI;
float Tmin = 0.0;

float scale = 0.25;// ñòåï³íü ìàñøòàáóâàííÿ

// Ôóíêö³ÿ îá÷èñëåííÿ ïàðàìåòðà õ
float parameterX( float t ) {
   return sin( 3 * t ) * cos( t );
}

// // Ôóíêö³ÿ îá÷èñëåííÿ ïàðàìåòðà ó
float parameterY( float t ) {
   return sin( 3 * t ) * sin( t );
}
 //Ôóíêö³ÿ, ùî âèêëèêàòèìåòüñÿ äëÿ ìàëþâàííÿ ñöåíè
void display() {
   glClearColor( 1.0f, 0.5f, 0.0f, 1.0f ); // Ôîí êîðè÷íåâèé
   glClear( GL_COLOR_BUFFER_BIT ); // Î÷èùåííÿ áóôåðó êîëüîðó

   glBegin( GL_LINE_STRIP );
   glColor3f( 0.0f, 1.0f, 0.0f );// çåëåíèé êîë³ð
   for( float t = Tmin; t <= Tmax; t += 0.01 ) {
      float x = parameterX( t);
      float y = parameterY( t );
      glVertex2f( x, y );
   }
   glEnd();

   // Ìàëþâàííÿ êîîðäèíàòíèõ îñåé
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

   // Ìàëþâàííÿ ïîçíà÷îê íà êîîðäèíàòíèõ îñÿõ
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
   glFlush(); // Âèêîíàòè ìàëþâàíí
}

/* Program entry point */

int main( int argc, char* argv[] ) {
   glutInit( &argc, argv ); // ²í³ö³àë³çàö³ÿ GLUT
   glutCreateWindow( "DK-21 varint 9" ); // Ñòâîðåííÿ â³êíà ³ç çàäàíèì ³ì'ÿì
   glutDisplayFunc( display ); // Ðåºñòðàö³ÿ ôóíêö³¿ çâîðîòíîãî
   glScaled( scale, scale,0); // ìàñøòàáóâàííÿ îêíà
   glutFullScreen(); // íà âåñü åêðàí
   glutMainLoop(); // Âõ³ä ó öèêë îáðîáêè ïîä³é GLUT
   return 0;
}
