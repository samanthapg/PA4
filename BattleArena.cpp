#include "BattleArena.h"
#include "Point2D.h"
#include "Building.h"

BattleArena :: BattleArena():Building('A',0,Point2D(0.0,0.0))
{
	display_code='A';
	pokemon_count=0;
	max_num_rivals=3;
	num_rivals_remaining=max_num_rivals;
	dollar_cost_per_fight=4;
	stamina_cost_per_fight=3;
	state=RIVALS_AVAILABLE;
	norivals=false;
	cout<<"BattleArena default constructed\n"; 
}
BattleArena :: BattleArena(unsigned int max_rivals, unsigned stamina_cost, double dollar_cost, int in_Id, Point2D in_loc):Building('A', in_Id, in_loc)
{
	id_num=in_Id;
	location=in_loc;
	display_code='A';
	pokemon_count=0;
	max_num_rivals=max_rivals;
	num_rivals_remaining=max_num_rivals; 
	stamina_cost_per_fight=stamina_cost;
	dollar_cost_per_fight=dollar_cost;
	norivals=false; 
	state=RIVALS_AVAILABLE;
	cout<<"BattleArena constructed\n"; 
}
 unsigned int BattleArena ::GetNumRivalsRemaining()
{
	return num_rivals_remaining;
}
bool BattleArena:: HasEnoughRivals()
{
	if (state==RIVALS_AVAILABLE)
	{
		return true;
	}
	else
	{
		return false;
	}
}
double BattleArena:: GetDollarCost()
{
	return dollar_cost_per_fight;
}
unsigned int BattleArena :: GetStaminaCost()
{
	return stamina_cost_per_fight;

}
bool BattleArena:: IsAbleToFight(double budget, unsigned int stamina)
{
	if (budget>=dollar_cost_per_fight && stamina>=stamina_cost_per_fight)
	{
		return true;
	}
	else 
	{
		return false; 
	}
}
bool BattleArena:: Update()
{
	if (state==RIVALS_AVAILABLE && GetNumRivalsRemaining()!=0)
	{
		return false;
	}
	else if (GetNumRivalsRemaining()==0 && norivals==false)
	{
		norivals=true; 
		return true;
	}
	else
	{
		return false; 
	}
}
bool BattleArena :: IsBeaten()
{
	if (num_rivals_remaining==0)
	{
		return true;
	}
	else
	{
		return false; 
	}
}
int BattleArena:: GetId()
{
	return id_num; 
}

void BattleArena :: RemoveOneRival()
{
	num_rivals_remaining=num_rivals_remaining-1;
}

void BattleArena::ShowStatus()
{
	cout<<"Battle Arena: "; 
	Building::ShowStatus();
	//cout<<"\tMax number of rivals: "<<max_num_rivals<<endl;
	cout<<"\tStamina cost per fight: "<<stamina_cost_per_fight<<endl;
	cout<<"\tPokemon dollar cost per fight: "<<dollar_cost_per_fight<<endl;
	cout<<"\t"<<num_rivals_remaining<<" rival(s) are remaining for this arena\n"; 
}

void BattleArena::AddOneRival()
{
	num_rivals_remaining++; 
}
