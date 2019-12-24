#include <iostream>
#include "PokemonCenter.h"
#include "Building.h"
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
using namespace std; 


PokemonCenter :: PokemonCenter():Building('C',0,Point2D(0.0,0.0))
{
	display_code='C';
	stamina_capacity=100; 
	num_stamina_points_remaining=stamina_capacity;
	dollar_cost_per_stamina_point=5;
	state=STAMINA_POINTS_AVAILABLE;
	cout <<"PokemonCenter default constructed. \n";
}
PokemonCenter :: PokemonCenter(int in_Id, double stamina_cost, unsigned int stamina_cap, Point2D in_loc):Building('C', in_Id,in_loc)
{
 	id_num=in_Id;
 	stamina_capacity=100;
 	location=in_loc;
 	dollar_cost_per_stamina_point=stamina_cost;
 	stamina_capacity=stamina_cap;
	//num_stamina_points_remaining=stamina_capacity;
	state=STAMINA_POINTS_AVAILABLE;
	num_stamina_points_remaining=stamina_capacity;
	cout <<"PokemonCenter constructed. \n";

}
PokemonCenter :: ~PokemonCenter()
{
	cout<<"PokemonCenter destructed."<<endl; 
}

bool PokemonCenter :: HasStaminaPoints()
{
	if (num_stamina_points_remaining>=1)
	{
		return true; 
	}
	else 
	{
		return false; 
	}

}
unsigned int PokemonCenter :: GetNumStaminaPointsRemaining()
{
	return num_stamina_points_remaining;
}
bool PokemonCenter :: CanAffordStaminaPoints(unsigned int stamina_points, double budget)
{
	if (budget >= dollar_cost_per_stamina_point * stamina_points)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
double PokemonCenter :: GetDollarCost(unsigned int stamina_points)
{
	return (dollar_cost_per_stamina_point * stamina_points);
}
unsigned int PokemonCenter :: DistributeStamina(unsigned int points_needed)
{
	if (num_stamina_points_remaining>=points_needed)
	{
	 num_stamina_points_remaining=num_stamina_points_remaining-(points_needed);
	 return points_needed;
	
	}
	else 
	{
		return num_stamina_points_remaining;
		num_stamina_points_remaining=0; 
	}

}
bool PokemonCenter :: Update()
{
	bool flag; 
	if (num_stamina_points_remaining==0 && flag==false)
	{
		state=NO_STAMINA_POINTS_AVAILABLE;
		display_code='c';
		cout <<"PokemonCenter "<<id_num<<" has ran out of stamina points. \n";
		flag=true; 
		return true;
	}
	else 
	{
		return false; 
	}

}
void PokemonCenter :: ShowStatus()
{
	cout<<"Pokemon Center Status: ";
	Building::ShowStatus(); 
	cout<<"\t"<<"Pokemon dollar cost per stamina point: " <<dollar_cost_per_stamina_point<<"\n";
	cout <<"\t"<<"has "<<num_stamina_points_remaining<<" stamina point(s) remaining \n";
}