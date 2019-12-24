#include "PokemonGym.h"
#include "Point2D.h"
#include <iostream>
using namespace std; 

PokemonGym :: PokemonGym() : Building('G', 0, Point2D(0.0,0.0))
{
	display_code='G';
	state=NOT_BEATEN;
	max_number_of_training_units=10;
	num_training_units_remaining=max_number_of_training_units;
	stamina_cost_per_training_unit=1;
	dollar_cost_per_training_unit=1.0;
	experience_points_per_training_unit=2;
	cout <<"PokemonGym default constructed.\n";

}
PokemonGym :: PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', 0, Point2D(0.0,0.0))
{	
	id_num=in_id;
	max_number_of_training_units=max_training_units;
	stamina_cost_per_training_unit=stamina_cost;
	experience_points_per_training_unit=exp_points_per_unit;
	dollar_cost_per_training_unit=dollar_cost;
	location=in_loc;
	num_training_units_remaining=max_number_of_training_units; 
	cout<<"PokemonGym constructed.\n";
	

}

PokemonGym :: ~PokemonGym()
{
	cout<<"PokemonGym destructed"<<endl; 
}


	double PokemonGym :: GetDollarCost(unsigned int unit_qty)
	{
		return (dollar_cost_per_training_unit * unit_qty);
	}
	unsigned int PokemonGym :: GetStaminaCost(unsigned int unit_qty)
	{
		return (stamina_cost_per_training_unit * unit_qty);
	}
	unsigned int PokemonGym :: GetNumTrainingUnitsRemaining()
	{
		return num_training_units_remaining;
	}
	bool PokemonGym :: IsAbleToTrain(unsigned int unit_qty, double budget, unsigned int stamina)
	{
		if ((dollar_cost_per_training_unit * unit_qty)<=budget && (stamina_cost_per_training_unit * unit_qty)<=stamina)
		{
			return true; 
			
		}
		else 
		{
			return false;
		}
	}
	unsigned int PokemonGym :: TrainPokemon(unsigned int training_units)
	{
		if (training_units>num_training_units_remaining)
		{
			training_units=num_training_units_remaining;
			num_training_units_remaining=0; 
		}
		else 
		{
			num_training_units_remaining=num_training_units_remaining-training_units; 
		}
		return (training_units*experience_points_per_training_unit); 
	}
	bool PokemonGym :: Update()
	{
		bool flag2;

		if (num_training_units_remaining==0 && flag2==false)
		{
			state=BEATEN;
			display_code='g';
			flag2=true;
			cout<<display_code<<id_num<<" has been beaten\n"; 
		return true;
		}
		else
		{
			return false; 
		}
	}
	bool PokemonGym :: IsBeaten()
	{
		if (num_training_units_remaining==0)
		{
			return true;
		}
		else 
		{
			return false;
		}
	}
	void PokemonGym :: ShowStatus()
	{
		cout<<"Pokemon Gym Status: "; 
		Building::ShowStatus(); 
		cout<<"\t"<<"Max number of training units: "<<max_number_of_training_units<<"\n";
		cout<<"\t"<<"Stamina cost per training unit: "<<stamina_cost_per_training_unit<<"\n";
		cout<<"\t"<<"Pokemon dollar cost per training unit: "<<dollar_cost_per_training_unit<<"\n";
		cout<<"\t"<<"Experience points per training: "<<experience_points_per_training_unit<<"\n";
		cout <<"\t"<<num_training_units_remaining<<" training unit(s) are remaining for this gym\n";

	}
	
	
