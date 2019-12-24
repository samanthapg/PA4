#ifndef RIVAL_H
#define RIVAL_H
#include "Point2D.h"
#include "string.h"
#include "BattleArena.h"

enum RivalStates{
	ALIVE_RIVAL=0,
	FAINTED_RIVAL=1
};

class Rival: public GameObject
{
protected:
	string name;
	int speed; 
	double health;
	double physical_damage;
	double magical_damage;
	double defense;
	bool is_in_arena;
	BattleArena * current_arena;
public:
	Rival(string name, double speed, double hp, double phys_dmg, double magic_dmg, double def, int id, BattleArena * A1);
	~ Rival(); 
	void TakeHit(double physical_damage, double magical_damage, double defense);
	double get_phys_dmg();
	double get_magic_dmg();
	double get_defense();
	double get_health();
	bool Update();
	void ShowStatus(); 
	bool IsAlive();  
	bool ShouldBeVisible(); 
	int GetId(); 
};

#endif