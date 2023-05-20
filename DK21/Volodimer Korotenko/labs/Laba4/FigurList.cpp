#include "FigurList.h"
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <gl/glut.h>
Rectangle* CreateRectangle( Rectangle* Figure, Point2d* FirstCorner, Point2d* SecondCorner ) {// створення прямокутника
	Rectangle* NewRectangle = (Rectangle*) malloc( sizeof( Rectangle ) );
	if( NewRectangle == 0 ) {
		exit( -2 );
	}
	NewRectangle->Coordinates[0] = *FirstCorner;
	NewRectangle->Coordinates[1].x = FirstCorner->x;
	NewRectangle->Coordinates[1].y = SecondCorner->y;
	NewRectangle->Coordinates[2] = *SecondCorner;
	NewRectangle->Coordinates[3].x = SecondCorner->x;
	NewRectangle->Coordinates[3].y = FirstCorner->y;
	NewRectangle->Color = (RGB*) malloc( sizeof( RGB ) );
	NewRectangle->Color->R = (float) rand() / RAND_MAX;
	NewRectangle->Color->G = (float) rand() / RAND_MAX;
	NewRectangle->Color->B = (float) rand() / RAND_MAX;
	return NewRectangle;
}
Rectangle* CreateRandomRectangle( int rangeMax ,int rangeMin ) {// створення випадкового прямокутника
	Rectangle* Rectangle = 0;
	Point2d* FP = (Point2d*) malloc( sizeof( Point2d ) );
	Point2d* SP = (Point2d*) malloc( sizeof( Point2d ) );
	SP->x = 0;
	SP->y = 0;
	FP->x = ( (double) rand() / RAND_MAX ) * ( rangeMax - rangeMin ) + rangeMin;
	FP->y = ( (double) rand() / RAND_MAX ) * ( rangeMax - rangeMin ) + rangeMin;
	do {
		SP->x = ( (double) rand() / RAND_MAX ) * ( rangeMax - rangeMin ) + rangeMin;
	} while( SP->x == FP->x );
	do {
		SP->y = ( (double) rand() / RAND_MAX ) * ( rangeMax - rangeMin ) + rangeMin;
	} while( SP->y == FP->y );
	Rectangle = CreateRectangle( Rectangle, FP, SP );
	return Rectangle;
}
Point2d* CreatePoint2d(int x, int y) {// створення точки
	Point2d* Point = (Point2d*)malloc(sizeof( Point2d ));
	Point->x = x;
	Point->y = y;
	return Point;
}
ListOfRectangle* GetForIndex( ListOfRectangle* Figures, unsigned int Index ) {// посилання на список за індексом
	ListOfRectangle* Part = Figures;
	if( Part ) {
		for( size_t i = 0; i < Index; i++ ) {
			if( Part->Next ) {
				Part = Part->Next;
			}
		}
		return Part;
	}
	return NULL;
}
ListOfRectangle* CreateListOfRectangle( Rectangle* Rectangle) {// створення списка прямокутників
	ListOfRectangle* Temp = (ListOfRectangle*) malloc( sizeof( ListOfRectangle ) );
	if( Temp == 0 ) {
		exit( -2 );
	}
	Temp->Rectangle = Rectangle;
	Temp->Next = NULL;
	return Temp;
}
ListOfRectangle* GetLastNode( ListOfRectangle* Head ) {// отримання останнього елементу списка
	ListOfRectangle* Temp = Head;
	if( Temp != 0 ) {
		while( Temp->Next != 0 ) {
			Temp = Temp->Next;
		}
	}
	return Temp;
}
ListOfRectangle* AddToEndArray( ListOfRectangle* Figures, Rectangle* Figure ) {// додавання у кінець списку
	ListOfRectangle* Temp = CreateListOfRectangle( Figure );
	GetLastNode( Figures )->Next = Temp;
	return Temp;
}
ListOfRectangle* DeleteByIndex( ListOfRectangle* Figures, unsigned int Index ) {// видалення за індексом
	ListOfRectangle* Part = Figures;
	ListOfRectangle* t = 0;
	if( Part ) {
		if( Index == 0 ) {
			if( Part->Next ) {
				t = Part->Next;
				FreeRectangle( Part ->Rectangle);
				free( Part );
				return t;
			} else FreeFiguresList( Part );
			return NULL;
		}
		for( size_t i = 1; i < Index; i++ ) {
			if( Part->Next ) {
				Part = Part->Next;
			}
		}
		if( Part->Next ) {
			t = Part->Next;
			Part->Next = Part->Next->Next;
			FreeRectangle( t->Rectangle );
			free(t);
			return Part;
		} else FreeFiguresList( Part );
	}
	return NULL;
}
int AddAfterIndex( ListOfRectangle* Figures, Rectangle* Figure, int Index ) {// зміна списка за індексом
	if( Figures && Figure ) {
		if( GetSizeList( Figures ) == Index ) {
			AddToEndArray( Figures, Figure );
		} else {
			GetForIndex( Figures, Index )->Rectangle = Figure;
		}
		return Index;
	}
	return -1;
}
int GetSizeList( ListOfRectangle *Figures ) {// розмір списока
	int Size = 0;
	if( Figures ) {
		Size++;
		ListOfRectangle* Part = Figures->Next;
		while( Part )
		{
			Size++;
			Part = Part->Next;
		} 
	}
	return Size;
}
void PrintRectangle( Rectangle *Rectangle) {// відобразити прямокутників
	glBegin( GL_TRIANGLE_FAN );
	glColor3f( Rectangle->Color->R,
				  Rectangle->Color->G,
				  Rectangle->Color->B );
	for( size_t i = 0; i < 4; i++ ) {
		glVertex2f( Rectangle->Coordinates[i].x, Rectangle->Coordinates[i].y );
	}
	glEnd();
}
void PrintListOfRectangle( ListOfRectangle* Rectangles ) {// відобразити список прямокутників
	if( Rectangles ) {
		PrintRectangle( Rectangles ->Rectangle);
		ListOfRectangle* Part = Rectangles->Next;
		while( Part ) {
			PrintRectangle( Part->Rectangle );
			Part = Part->Next;
		}
	}
}
void FreeRectangle( Rectangle* Rectangle ) {// видаленя прямокутника
	if( Rectangle ) {
		free( Rectangle->Color );
		free( Rectangle );
	}
}
void FreeFiguresList( ListOfRectangle* figures ) {// видаленя списка
	if( figures ) {
		ListOfRectangle* Part = figures->Next;
		ListOfRectangle* Temp = NULL;
		while( Part->Next ) {
			FreeRectangle( Part->Rectangle );
			Temp = Part->Next;
			free( Part );
			Part = Temp;
		}
		free( Part );
	}
}