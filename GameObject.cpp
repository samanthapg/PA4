#include <iostream>
#include "GameObject.h"
#include "Point2D.h"
using namespace std; 

GameObject :: GameObject(char in_code)
{
	display_code=in_code; 
	id_num=1;
	state=0;
	cout <<"GameObject Constructed. \n";
}

GameObject :: GameObject(Point2D in_loc, int in_id, char in_code)
{
	display_code=in_code;
	id_num=in_id;
	location=in_loc; 
	cout <<"GameObject Constructed. \n";
}
GameObject :: ~GameObject()
{
	cout<<"GameObject destructed."<<endl;
}
Point2D GameObject::GetLocation()
{
	return location;
}
int GameObject :: GetId()
{
	return id_num;
}
char GameObject :: GetState()
{
	return state;
}
void GameObject :: ShowStatus()
{
	cout<<display_code<<id_num<<" at "<<location;
}

bool GameObject :: Update()
{
	return true; 
} 

bool GameObject:: ShouldBeVisible()
{
	return true; 
}

void GameObject:: DrawSelf(char * ptr)
{
	*ptr=display_code; 
	*(ptr+1)=char(id_num+48); 
}

bool GameObject :: IsAlive()
{
	return true; 
}
