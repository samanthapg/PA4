#include <iostream>
#include "Rival.h"
#include "Point2D.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "string.h"
#include "BattleArena.h"
#include <stdlib.h>
using namespace std;

Rival :: Rival (string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, BattleArena * arenaptr):GameObject((arenaptr->GetLocation()), id, 'R')
{
	this->name=name; //check this pointer
	this->speed=speed;
	health=hp;
	physical_damage=phys_dmg;
	magical_damage=magic_dmg;
	defense=def;
	id_num=id;
	//location=in_loc;
	location=arenaptr->GetLocation();
	current_arena=arenaptr; 
	is_in_arena=false;
	state=ALIVE_RIVAL; 
	cout<<"Rival constructed\n";
}

Rival :: ~Rival(){
	cout<<"Rival destructed.\n"; 
}

void Rival :: TakeHit(double physical_damage, double magical_damage, double defense)
{
	int random=rand()%2;
	int damage;
	if (random==1)
	{
		damage=(100.0 - defense)/100 * physical_damage;
		health=health-damage;
		cout<<"Aaagh, no physical pain no gain!\n";
		cout<<"Damage: "<<damage<<endl;
		cout<<"Health: "<<health<<endl;
		cout<<"******"<<endl;
	}
	else
	{
		damage=(100.0 - defense)/100 * magical_damage;
		health=health-damage;
		cout<<"Ouch, I don't believe magic!\n";
		cout<<"Damage: "<<damage<<endl;
		cout<<"Health: "<<health<<endl;
		cout<<"******"<<endl;
	}
}

double Rival :: get_phys_dmg()
{
	return physical_damage;
}

double Rival:: get_magic_dmg()
{
	return magical_damage;
}
double Rival::get_defense()
{
	return defense;
}
double Rival::get_health()
{
	return health; 
}
bool Rival :: IsAlive()
{
	if (health <=0)
	{
		state=FAINTED_RIVAL;
		return false; 

	}
	else
	{
		state=ALIVE_RIVAL; 
		return true; 
	}
}
bool Rival :: Update()
{
	if (state==ALIVE_RIVAL)
	{
		return false;
	}
	else if (state==FAINTED_RIVAL)
	{
		if (is_in_arena==false)
		{
			current_arena->RemoveOneRival(); //check where to put it. 
			is_in_arena=true; 
		}
		return true;
		//finish
	}
return false; 
}

bool Rival::ShouldBeVisible()
{
	return true; 
}

int Rival::GetId()
{
	return id_num; 
}

void Rival :: ShowStatus()
{
	cout<<name<< " status:";
	GameObject::ShowStatus();
	if (state==ALIVE_RIVAL)
	{
		cout<<" alive\n";
	}
	else if(state==FAINTED_RIVAL)
	{
		cout<<" dead, RIP... \n"; 
	}
	cout<<"\t"<<"Health: "<<health<<endl;
	cout<<"\t"<<"Physical Damage: "<<physical_damage<<endl;
	cout<<"\t"<<"Magical Damage: "<<magical_damage<<endl; 
	cout<<"\t"<<"Defense: "<<defense<<endl; 
}