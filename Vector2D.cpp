#include "Vector2D.h"
#include <iostream>
#include <cmath>
using namespace std; 

Vector2D :: Vector2D()
{
	x=0.0;
	y=0.0;
}


Vector2D :: Vector2D(double in_x, double in_y)
{
	x=in_x;
	y=in_y;
}


Vector2D operator *(Vector2D v1, double d)
{
	Vector2D mult;
	mult.x=(v1.x)*d;
	mult.y=(v1.y)*d;
	return mult;
}
//Division operator 
Vector2D operator /(Vector2D v1, double d)
{
	Vector2D div;
	if (d==0)
	{
		div.x=v1.x;
		div.y=v1.y;
	}
	else 
	{
		div.x=(v1.x)/d;
		div.y=(v1.y)/d;
	}
	return div;  
}
ostream& operator <<(ostream& out, Vector2D v1)
{
	out<<"<"<<v1.x<<","<<v1.y<<">";
	return out; 
}
