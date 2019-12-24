#include "Pokemon.h"
#include "PokemonGym.h"
#include "PokemonCenter.h"
#include "GameObject.h"
#include "Vector2D.h"
#include "Building.h"
#include "Point2D.h"
#include "BattleArena.h"
#include "Rival.h"
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <string.h>
#include <ctime>
using namespace std;

Pokemon :: Pokemon(): GameObject('B')
{
	speed=5;
	name="Default"; 
	stamina=20;
	experience_points=0;
	pokemon_dollars=0;
	training_units_to_buy=0;
	current_center=NULL;
	current_gym=NULL;
	state=STOPPED;
	health=20;
	store_health=health;
	physical_damage=5;
	magical_damage=4;
	defense=15;
	is_in_gym = false;
    is_in_center = false;
    is_in_arena=false; 
   	is_fainted=false;
	cout<<"Pokemon default constructed.\n";

}

Pokemon :: Pokemon(char in_code): GameObject('B')
{
	speed=5;
	state=STOPPED;
	name="Default";
	stamina=20;
	display_code=in_code;
	experience_points=0;
	pokemon_dollars=0;
	training_units_to_buy=0;
	current_center=NULL;
	current_gym=NULL;
	state=STOPPED;
	health=20;
	store_health=health;
	physical_damage=5;
	magical_damage=4;
	is_in_gym = false;
    is_in_center = false;
    is_in_arena=false; ;
	defense=15;
	is_fainted=false;
	cout<<"Pokemon constructed.\n";
	
}
Pokemon :: Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc): GameObject('B')
{
	speed=in_speed;
	name=in_name;
	id_num=in_id; 
	display_code=in_code;
	location=in_loc; 
	stamina=20;
	experience_points=0;
	pokemon_dollars=0;
	training_units_to_buy=0;
	current_center=NULL;
	current_gym=NULL;
	current_arena=NULL; 
	state=STOPPED;
	health=20; 
	store_health=health;
	physical_damage=5;
	magical_damage=4;
	defense=15; 
	is_in_gym = false;
    is_in_center = false;
    is_in_arena=false; 
    is_fainted=false;
	cout<<"Pokemon constructed.\n";
}

Pokemon :: Pokemon(string in_name, double in_speed, double hp, double phys_dmg, double magic_dmg, double def, int in_id, char in_code, Point2D in_loc): GameObject(in_loc,in_id,'P')
{
	speed=in_speed;
	id_num=in_id;
	health=20; 
	store_health=health;
	physical_damage=phys_dmg;
	magical_damage=magic_dmg;
	defense=def;
	name=in_name;
	display_code=in_code;
	location=in_loc;
	current_gym=NULL;
	current_center=NULL;
	current_arena=NULL; 
	stamina=20;
	experience_points=0;
	pokemon_dollars=0;
	training_units_to_buy=0;
	state=STOPPED;
	health=hp;
	store_health=health;
	is_in_gym = false;
    is_in_center = false;
    is_in_arena=false; 
    is_fainted=false;

    cout<<"Pokemon constructed.\n";

}

Pokemon :: ~Pokemon()
{
	cout<<"Pokemon destructed."<<endl; 
}

void Pokemon :: StartMoving(Point2D dest) //tells the pokemon to start moving
{
	if (IsExhausted())
	{
		cout<<display_code<<id_num<<": I am exhausted. I may move but you cannot see me.\n";
	}
	else if (!IsAlive())
	{
		cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
	}
	else
	{
		SetupDestination(dest);

		if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
		{
			cout<<display_code<<id_num<<": I am already there. See?\n";
		}
		else 
		{
					cout<<display_code<<id_num<<": On my way.\n"; 
			/*if (is_in_gym==true)
			{
				current_gym->RemoveOnePokemon();
				is_in_gym=false;
			}
			if (is_in_center==true)
			{
				current_center->RemoveOnePokemon();
				is_in_center=false; 
			}
			if (is_in_arena==true)
			{
				current_arena->RemoveOnePokemon();
				is_in_arena=false;
			}*/
			state=MOVING;
		}
	}

}
void Pokemon :: StartMovingToCenter(PokemonCenter* center) //Tells the pokemon to move to a center
{
	if (IsExhausted())
	{
		cout<<display_code<<id_num<<": I am exhausted, so I can't move to recover stamina...\n";
	}
	else if (!IsAlive())
	{
		cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
	}
	else
	{
		SetupDestination(center->GetLocation());
		if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
		{
			cout<<display_code<<id_num<<": I am already at the Pokemon Center!\n";
			//state=IN_CENTER;
			//is_in_center=true;
			//current_center=center;
		}
		else
		{
			if (is_in_center) {
                current_center->RemoveOnePokemon(); // handles corner case
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if(is_in_arena){
            	current_arena->RemoveOnePokemon();
            	is_in_arena=false;
            }
            state = MOVING_TO_CENTER;
            current_center = center;
            SetupDestination(center->GetLocation());
            cout << display_code << GetId() << ": On my way to center " << center->GetId() << endl;
		}
	}

}
void Pokemon :: StartMovingToGym(PokemonGym* gym)
{
	if (IsExhausted())
	{
	cout<<display_code<<id_num<<": I am exhausted, so I shouldn't be going to the gym...\n";
	}
	else if (!IsAlive())
	{
		cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
	}
	else
	{
		SetupDestination(gym->GetLocation());
		if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
		{
			cout<<display_code<<id_num<<": I am already at the Pokemon Gym!\n";
			//state=IN_GYM; 
			//is_in_gym=true;
			//current_gym=gym;
		}
		else
		{
			 if (is_in_gym) {
                current_gym->RemoveOnePokemon(); // handles corner case
                is_in_gym = false;
            } else if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            }
            else if(is_in_arena){
            	current_arena->RemoveOnePokemon();
            	is_in_arena=false;
            }
            state = MOVING_TO_GYM;
            current_gym = gym;
            SetupDestination(gym->GetLocation());
            cout << display_code << GetId() << ": On my way to gym " << gym->GetId() << endl;
		
		}
	}
}

void Pokemon :: StartTraining(unsigned int num_training_units)
{
	if ((!IsExhausted()) && (is_in_gym==true) && ((current_gym->IsBeaten())==false) && (current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina)==true) && IsAlive())
	{
		cout <<display_code<<id_num<<": Started to train at Pokemon Gym "<<(current_gym->GetId())<<" with "<<num_training_units<<" training units \n";
		if ((current_gym->GetNumTrainingUnitsRemaining()) >= num_training_units)
		{
			training_units_to_buy=num_training_units;
		}
		else 
		{
			training_units_to_buy=current_gym->GetNumTrainingUnitsRemaining(); 
		}
		state=TRAINING_IN_GYM;
	}
	else if (IsExhausted())
	{
		cout <<display_code<<id_num<<": I am exhausted so no more training for me...."<<endl;
	}
	else if (is_in_gym==false)
	{
		cout <<display_code<<id_num<<": I can only train in a Pokemon Gym!"<<endl;
	}
	else if (current_gym->IsBeaten()==true)
	{
		cout <<display_code<<id_num<<": Cannot train! This Pokemon Gym is already beaten! "<<endl;
	}
	else if ((current_gym->IsAbleToTrain(num_training_units, pokemon_dollars, stamina))==false)
	{
		cout <<display_code<<id_num<<": Not enough Stamina and/or money for training "<<endl;
	}
	else if (!IsAlive())
	{
		cout<<display_code<<id_num<<": I am not alive, so I cannot train.\n"; 
	}
}

void Pokemon :: StartRecoveringStamina(unsigned int num_stamina_points)
{
	if (is_in_center==true)
	{
		if ((current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars)) && (current_center->GetNumStaminaPointsRemaining()>0) && IsAlive())
		{
			cout<<display_code<<id_num<<": Started recovering "<<num_stamina_points<<" stamina point(s) at Pokemon Center "<<(current_center->GetId())<<endl;
			if ((num_stamina_points)<(current_center->GetNumStaminaPointsRemaining()))
			{
				stamina_points_to_buy=num_stamina_points;
			}
			else
			{
				stamina_points_to_buy=current_center->GetNumStaminaPointsRemaining(); 
			}
			state=RECOVERING_STAMINA;
		}
		else if (current_center->CanAffordStaminaPoints(num_stamina_points, pokemon_dollars)==false)
		{
			cout <<display_code<<id_num<<": Not enough money to recover stamina."<<endl;
		}	
		else if (current_center->GetNumStaminaPointsRemaining()==0)
		{
			cout<<display_code<<id_num<<": Cannot recover! No stamina points remaining in this Pokemon Center"<<endl; 
		}
		else if (!IsAlive())
		{
		cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
		}
	}
	else
	{
		cout<<display_code<<id_num<<": I can only recover stamina at a Pokemon Center!"<<endl;
	}
}
	
void Pokemon :: Stop()
{
	state=STOPPED;
	cout<<display_code<<id_num<<": Stopping"<<endl;
}

bool Pokemon :: IsExhausted()
{
	if (stamina==0)
	{
		//state=EXHAUSTED; 
		return true;
	}
	else
	{
		return false;
	}
}

bool Pokemon :: ShouldBeVisible()
{
	if (IsExhausted())
	{
		return false;
	}
	else 
	{
		return true; 
	}
}

void Pokemon :: ShowStatus()
{
	cout<<name<<" status: ";
	GameObject::ShowStatus();
	//switch(state)
	//{
		if(state==STOPPED)
		{
			cout<<" stopped.";
		//	break; 
		}
		else if(state==MOVING)
		{
			cout<<" moving at a speed of "<<speed<< " to destination "<<destination<<" at each step of"<<delta;
		//	break;
		}
		else if(state==MOVING_TO_CENTER)
		{
			cout<<" heading to Pokemon Center "<<current_center->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta;
		//	break;
		}
		else if (state==MOVING_TO_GYM)
		{
			cout<<" heading to Pokemon Gym "<<current_gym->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta;
		//	break;
		}
		else if (state==IN_CENTER)
		{
			cout<<" inside Pokemon Center "<<current_center->GetId();
			//break; 
		}
		else if (state==IN_GYM)
		{
			cout<<" inside PokemonGym "<<current_gym->GetId();
		//	break; 
		}
		else if (state==TRAINING_IN_GYM)
		{
			cout<<" training in PokemonGym "<<current_gym->GetId();
		//	break; 
		}
		else if (state==RECOVERING_STAMINA)
		{
			cout<<" recovering stamina in Pokemon Center "<<GetId();
		}
		else if (state==MOVING_TO_ARENA)
		{
			cout<<" heading to Battle Arena "<<current_arena->GetId()<<" at a speed of "<<speed<<" at each step of "<<delta; 
		}
		else if (state==IN_ARENA)
		{
			cout<<" inside Battle Arena "<<current_arena->GetId(); 
		}
		else if (state==BATTLE)
		{
			//cout<<"Damage: "<<damage<<endl;
			//cout<<"Health: "<<health<<endl; 
		}
		else if(state==FAINTED)
		{
			cout<<" dead, RIP...";
		}
		//default:
	//	{
	//	}

	//}
		cout << endl;
	cout <<"\tStamina: "<<stamina<<endl;
	cout<<"\tPokemon Dollars: "<<pokemon_dollars<<endl;
	cout<<"\tExperience Points: "<<experience_points<<endl;
	cout<<"\tHealth: "<<health<<endl;
	cout<<"\tPhysical Damage: "<<physical_damage<<endl;
	cout<<"\tMagical Damage: "<<magical_damage<<endl;
	cout<<"\tDefense: "<<defense<<endl; 

}

bool Pokemon :: Update()
{
	switch(state)
	{
		case STOPPED:
		{
			return false;
//			if (is_in_gym==true)
//			{
//				cout<<"stopped and true\n"; 
//			}
		}
		case MOVING:
		{
			if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena){
            	current_arena->RemoveOnePokemon(); 
            	is_in_arena=false; 
            }
			if (IsExhausted())
				{
					state=EXHAUSTED;
					cout<<name<<" is out of stamina and can't move\n"; 
					return true; 
				}
			else if (!IsAlive())
			{
				cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
			}
			else 
			{
				UpdateLocation();
				if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
				{
					state=STOPPED;
					return true; 
				}
				else 
				{
					state=MOVING;
					stamina=stamina-1;
					pokemon_dollars=pokemon_dollars+GetRandomAmountOfPokemonDollars(); 
					return false;
				}
			}
		}
		case MOVING_TO_CENTER:
		{
			if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena){
            	current_arena->RemoveOnePokemon(); 
            	is_in_arena=false; 
            }
			if(IsExhausted())
			{
					cout<<name<<" is out of stamina and can't move\n"; 
					state=EXHAUSTED;
					return true; 
			}
			else if (!IsAlive())
			{
				cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
			}
			else 
			{
				UpdateLocation();
				if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
				{
					state=IN_CENTER;
					//is_in_center=true;
					//if (is_in_center==false)
					//{
						current_center->AddOnePokemon();
						is_in_center=true; 
				//	} 
					return true; 
				}
				else 
				{
					state=MOVING_TO_CENTER;
					stamina=stamina-1;
					pokemon_dollars=pokemon_dollars+GetRandomAmountOfPokemonDollars(); 
					return false;
				}
			}
		}
		case MOVING_TO_GYM:
		{
			if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena){
            	current_arena->RemoveOnePokemon(); 
            	is_in_arena=false; 
            }
			if(IsExhausted())
			{
				cout<<name<<" is out of stamina and can't move\n"; 
				state=EXHAUSTED;
				return true; 
				break;
			}
			else if (!IsAlive())
			{	
				cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
			}
			else 
			{
				UpdateLocation();
				if (((location.x)==(destination.x)) && ((location.y)==(destination.y)))
				{
					state=IN_GYM;
					//is_in_gym=true; 
					//if (is_in_gym==false)
					//{
						is_in_gym=true;
						current_gym->AddOnePokemon();
					//}
					return true; 
				}
				else
				{
					state=MOVING_TO_GYM;
					stamina=stamina-1;
					pokemon_dollars=pokemon_dollars+GetRandomAmountOfPokemonDollars();
					return false;
				}
			}
		}
		case IN_CENTER:
		{
			return false; 
		}
		case IN_GYM:
		{
			return false;
		}
		case TRAINING_IN_GYM:
		{
			if(IsExhausted()==false)
			{
				stamina=stamina-(current_gym->GetStaminaCost(training_units_to_buy));
				pokemon_dollars=pokemon_dollars-(current_gym->GetDollarCost(training_units_to_buy));
				experience_points_gained=current_gym->TrainPokemon(training_units_to_buy);
				experience_points=experience_points_gained+experience_points; 
				//experience_points+(current_gym->TrainPokemon(training_units_to_buy));
				cout <<"** "<<name<<" completed "<<training_units_to_buy<<" training unit(s)!**"<<endl;
				cout <<"** "<<name<<" gained "<<experience_points_gained<<" experience point(s)!**"<<endl; 
				state=IN_GYM;
				return true;
			}
		}
		case RECOVERING_STAMINA:
		{
				unsigned int stamina_recovered; 
				stamina_recovered=(current_center->DistributeStamina(stamina_points_to_buy));
				stamina=stamina+stamina_recovered;
				//cout<<current_center->GetDollarCost(stamina); 
				pokemon_dollars=pokemon_dollars-(current_center->GetDollarCost(stamina_points_to_buy));
				cout <<"** "<<name<<" recovered "<<current_center->DistributeStamina(stamina_points_to_buy)<<" stamina point(s)!**\n";
				state=IN_CENTER;
				return true; 
		}
		case FAINTED:
		{
			return false;
		}
		case MOVING_TO_ARENA:
		{
			if (is_in_center) {
                current_center->RemoveOnePokemon();
                is_in_center = false;
            } else if (is_in_gym) {
                current_gym->RemoveOnePokemon();
                is_in_gym = false;
            }
            else if (is_in_arena){
            	current_arena->RemoveOnePokemon(); 
            	is_in_arena=false;
            }
			if(IsExhausted())
			{
				cout<<name<<" is out of stamina and can't move\n"; 
				state=EXHAUSTED;
				return true; 
				break;
			}
			else if (!IsAlive())
			{
				cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
			}
			else 
			{

				UpdateLocation();
				if (((location.x)==(destination.x)) && ((location.y)==(destination.y)))
				{
					state=IN_ARENA;
					//is_in_gym=true; 
					//if (is_in_arena==false) ////check
					//{
						is_in_arena=true;
						current_arena->AddOnePokemon();
					//}
					return true; 
				}
				else
				{
					state=MOVING_TO_ARENA;
					stamina=stamina-1;
					pokemon_dollars=pokemon_dollars+GetRandomAmountOfPokemonDollars();
					return false;
				}
			}

		}
		case BATTLE:
		{
			stamina=stamina-current_arena->GetStaminaCost();
			pokemon_dollars=pokemon_dollars+current_arena->GetDollarCost();
			if (StartBattle())
			{
				//cout<<"start battle is true \n";
				health=store_health;
				state=IN_ARENA;
				target->IsAlive();
				cout<<"Congrats Master, you defeated one rival!\n";	

			}
			else
			{
				state=FAINTED;
				target->IsAlive();
				//cout<<"start battle is not true \n";
				cout<<"Master, you were defeated...\n"; 
				current_arena->RemoveOnePokemon(); 
			}
		}
		case IN_ARENA:
		{
			return false; 
		}
		default:
		{
			return false; 
		}
	}
}

bool Pokemon :: UpdateLocation() //updates the object's location while it is moving 
{ 
	if ((fabs(destination.x-location.x)<=(fabs(delta.x))) && (fabs(destination.y - location.y)<=fabs(delta.y)))
	{
		location=destination; 
		cout <<display_code<<id_num<<": I'm there!"<<endl;
		return true;
	}
	else
	{
		cout <<display_code<<id_num<<": step..."<<endl;
		location=location+delta;
		return false;
	}

}

void Pokemon :: SetupDestination(Point2D dest)
{
	destination=dest;
	location=GetLocation();
	delta=(destination-(location))*(speed/GetDistanceBetween(destination,location));
}

string Pokemon :: GetName()
{
	return name; 
}

static double GetRandomAmountOfPokemonDollars()
{
	srand(time(NULL));
	double random;
	double low=0.0;
	double high=2.0;
	random=(double)rand() * (high -low)/((double)RAND_MAX)+low;
	return random; 
}

bool Pokemon :: IsAlive()
{
	if (health<=0)
	{
		state=FAINTED; 
		return false;
	}
	else 
	{
		return true; 
	}
}

void Pokemon:: TakeHit(double physical_damage, double magical_damage, double defense)
{
	int random=rand()%3;
	double damage;
	if (random==1)
	{
		damage=(100.0 - defense)/100 * physical_damage;
		health=health-damage;
		cout<<"Physical damage hurts, Master!\n";
		cout<<"Damage: "<<damage<<endl;
		cout<<"Health: "<<health<<endl;
		cout<<"******"<<endl;

	}
	else
	{
		damage=(100.0 - defense)/100 * magical_damage;
		health=health-damage;
		cout<<"It is magic, Master!\n";
		cout<<"Damage: "<<damage<<endl;
		cout<<"Health: "<<health<<endl;
		cout<<"******"<<endl;
	}
}

void Pokemon :: ReadyBattle(Rival * in_target)
{
if (!is_in_arena)
{
	cout<<display_code<<id_num<<": I can only fight in a Battle Arena!\n"; 
}
else if (current_arena->IsAbleToFight(pokemon_dollars, stamina)==false)
{
	cout<<display_code<<id_num<<": Not enough Stamina and/or money for a battle\n";
}
else if (current_arena->IsBeaten())
{
	cout<<display_code<<id_num<<": Cannot battle! This pokemon is already beaten\n";
}
else if(in_target->IsAlive()==false)
{
	cout<<display_code<<id_num<<": Cannot battle! Rival is not alive\n";
}
else
{	
	if (state==IN_ARENA && current_arena->IsAbleToFight(pokemon_dollars, stamina)==true && current_arena->IsBeaten()==false && in_target->IsAlive()==true)
	{
		target=in_target;
		state=BATTLE;
		cout<<display_code<<id_num<<": Getting Ready to battle \n"; 
	}
	else
	{
		state=IN_ARENA; 
	}
}
}

bool Pokemon :: StartBattle()
{
	//one time step?? 
	while (health > 0 && target->get_health() > 0) 
	{ 	
		TakeHit(target->get_phys_dmg(), target->get_magic_dmg(), this->defense);
		target->TakeHit(this->physical_damage, this->magical_damage, target->get_defense());

	}
	if (health>0)
	{
		return true;
	}
	else
	{
		return false; 
	}
}

void Pokemon :: StartMovingToArena(BattleArena* arena)
{

	SetupDestination(arena->GetLocation());
	if (IsExhausted())
	{
	cout<<display_code<<id_num<<": I am exhausted, so I shouldn't be going to the battle arena...\n";
	}
	else if (!IsAlive())
	{
		cout<<display_code<<id_num<<": I am not alive, so I cannot move.\n"; 
	}
	else if (((location.x)==(destination.x)) && ((location.y)==(destination.y))) 
	{
		cout<<display_code<<id_num<<": I am already at the battle arena!\n";
		//state=IN_GYM; 
		is_in_arena=true;
		current_arena=arena;
	}
	else
	{
		current_arena=arena; 
		cout<<display_code<<id_num<<": On my way to battle arena " <<(current_arena->GetId())<<"\n"; 
		state=MOVING_TO_ARENA; 
		//is_in_gym=false;
		if (is_in_center==true)
		{
			current_center->RemoveOnePokemon();
			is_in_center=false; 
		}
		if (is_in_gym==true)
		{
			current_gym->RemoveOnePokemon();
			is_in_gym=false; 
		}
	}

}
