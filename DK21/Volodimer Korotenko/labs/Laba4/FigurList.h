#pragma once
typedef struct Point2d {// структура двовимірної точки
	int x;
	int y;
} Point2d;
typedef struct RGB {// структура кольору
	float R;
	float B;
	float G;
} RGB;
typedef struct Rectangle {// структура прямокутника
	RGB* Color;
	Point2d Coordinates[4];
} Rectangle;
typedef struct ListOfRectangle {// структура списка прямокутників
	Rectangle* Rectangle;
	ListOfRectangle* Next;
} ListOfRectangle;

Rectangle* CreateRectangle( Rectangle* Figure, Point2d* FirstCorner, Point2d* SecondCorner );
Rectangle* CreateRandomRectangle( int rangeMax, int rangeMin );
Point2d* CreatePoint2d( int x, int y );
ListOfRectangle* CreateListOfRectangle( Rectangle* Rectangle );
ListOfRectangle* GetLastNode( ListOfRectangle* Head );
ListOfRectangle* AddToEndArray( ListOfRectangle* Figures, Rectangle* Figure );
ListOfRectangle* DeleteByIndex( ListOfRectangle* Figures, unsigned int Index );
int AddAfterIndex( ListOfRectangle* Figures, Rectangle* Figure, int Index );
ListOfRectangle* GetForIndex( ListOfRectangle* Figures, unsigned int Index );
int GetSizeList( ListOfRectangle* Figures );
void FreePoint( Point2d* Point );
void FreeRectangle( Rectangle* Rectangle );
void FreeFiguresList( ListOfRectangle* figures );
void PrintRectangle( Rectangle* Rectangle );
void PrintListOfRectangle( ListOfRectangle* Rectangles );