#ifndef VECTOR2D_H
#define VECTOR2D_H
#include <iostream>
using namespace std; 


class Vector2D
{
	public:
//member variables
	double x;
	double y;

	Vector2D();//Default

	Vector2D(double in_x, double in_y);

};
//multiplication operator
Vector2D operator *(Vector2D v1, double d);
//Division operator 
Vector2D operator /(Vector2D v1, double d);
//output operator
ostream& operator <<(ostream& out, Vector2D v1);


#endif 
