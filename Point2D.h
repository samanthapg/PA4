#ifndef POINT2D_H
#define POINT2D_H
#include <iostream>
#include "Vector2D.h"
using namespace std; 

class Point2D
{
public:
//member variables
	double x;
	double y;
	
	Point2D();//Default constructor
	Point2D(double in_x, double in_y);
};

double GetDistanceBetween(Point2D p1, Point2D p2);
//stream output operator
ostream& operator <<(ostream& out, Point2D p);
//addition operator

Point2D operator +(Point2D p1, Vector2D v1);
//substraction operator
Vector2D operator -(Point2D p1, Point2D p2);


#endif
