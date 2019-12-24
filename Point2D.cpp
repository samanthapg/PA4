#include "Point2D.h"
#include <cmath>
#include <iostream>
#include "Vector2D.h"
using namespace std; 


Point2D :: Point2D()
{
	x=0.0;
	y=0.0;
}

Point2D :: Point2D(double in_x, double in_y)
{
	x=in_x; 
	y=in_y; 
}	
//do we need to include Point2D :: every time??
double GetDistanceBetween(Point2D p1, Point2D p2)
{
	double distance; 
	distance=sqrt(pow((p2.y - p1.y),2) + pow((p2.x - p1.x),2)); 
	return distance; 
}
//stream output operator
ostream& operator <<(ostream& out, Point2D p)
{
	out<<"("<<p.x<<","<<p.y<<")"; 
	return out; 
}
//addition operator 
Point2D operator +(Point2D p1, Vector2D v1)
{
	Point2D newp;
	newp.x=p1.x+v1.x;
	newp.y=p1.y+v1.y; 
	return newp;
}
//substraction operator
Vector2D operator -(Point2D p1, Point2D p2)
{
	Vector2D newv;
	newv.x=p1.x-p2.x;
	newv.y=p1.y-p2.y;
	return newv; 
}