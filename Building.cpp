#include <iostream>
#include "GameObject.h"
#include "Building.h"
#include "Point2D.h"
using namespace std; 

Building :: Building(): GameObject(Point2D(0.0,0.0),0,'B')
{
	display_code='B';
	cout <<"Building default constructed.\n";
	pokemon_count=0;
}
Building :: Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code)
{
	id_num=in_Id;
	location=in_loc; 
	display_code=in_code;
	pokemon_count=0; 
	cout <<"Building constructed.\n";
}

Building :: ~Building()
{
	cout<<"Building destructed.\n"; 
}

void Building :: AddOnePokemon()
{
	pokemon_count=pokemon_count+1;
}
void Building :: RemoveOnePokemon()
{
	pokemon_count=pokemon_count-1;
}
void Building :: ShowStatus()
{
	cout<<display_code<<id_num<<" located at "<<location<<"\n";
	if (pokemon_count==1)
	{
		cout <<"\t"<<pokemon_count<<" pokemon is in this building\n";
	}
	else
	{
		cout <<"\t"<<pokemon_count<<" pokemon are in this building\n";
	}
}
bool Building :: ShouldBeVisible()
{
	return true; 
}
