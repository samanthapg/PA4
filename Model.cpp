#include "Model.h"
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include "BattleArena.h"
#include "Rival.h"
#include "Input_Handling.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>
#include <iterator>


Model::Model() {
    time = 0;
    //initializing all objects
    Pokemon * p1=new Pokemon("Pikachu",2, 23, 3, 6, 12, 1, 'P',Point2D(5, 1)); 
    Pokemon * p2=new Pokemon("Bulbasur",1,26, 4,3.7,16, 2, 'P', Point2D(10, 1));
    //pokemon_ptrs[0]=p1;
    //pokemon_ptrs[1]=p2;
    PokemonCenter * c1=new PokemonCenter(1, 1, 100, Point2D(1, 20));
    PokemonCenter * c2=new PokemonCenter(2, 2, 200, Point2D(10, 20));
    //center_ptrs[0]=c1;
    //center_ptrs[1]=c2;
    PokemonGym * g1=new PokemonGym(20, 1, 2.0, 3, 1, Point2D(0, 0));
    PokemonGym * g2=new PokemonGym(10, 5, 7.5, 8, 2, Point2D(5, 5));
   // gym_ptrs[0]=g1;
    //gym_ptrs[1]=g2;
    BattleArena * b1=new BattleArena(3,3,2.5,1,Point2D(15,12));
   // battle_ptrs[0]=b1;
    Rival * r1=new Rival("burhack", 2, 16,3, 7.2, 20, 1,b1);
    Rival * r2=new Rival("mmark9", 1, 29, 4, 5.2, 12, 2, b1);
    Rival * r3=new Rival("Densmore", 3 , 41, 6, 8.2,18, 3, b1);
    //adding objects to lists
    object_ptrs.push_back(p1);
    object_ptrs.push_back(p2);
    object_ptrs.push_back(c1);
    object_ptrs.push_back(c2);
    object_ptrs.push_back(g1);
    object_ptrs.push_back(g2);
    object_ptrs.push_back(r1);
    object_ptrs.push_back(r2);
    object_ptrs.push_back(r3);
    object_ptrs.push_back(b1);
    
    //initializing alive_ptrs list.. assign copies the second list into the first one 
    active_ptrs.assign(object_ptrs.begin(), object_ptrs.end());

    pokemon_ptrs.push_back(p1);
    pokemon_ptrs.push_back(p2);

    center_ptrs.push_back(c1);
    center_ptrs.push_back(c2);

    gym_ptrs.push_back(g1);
    gym_ptrs.push_back(g2);

    battle_ptrs.push_back(b1);

    rival_ptrs.push_back(r1);
    rival_ptrs.push_back(r2);
    rival_ptrs.push_back(r3);

    //Pikachu 1
    /*pokemon_ptrs[0] = new Pokemon("Pikachu", 1, 'P', 2.0, Point2D(5, 1));
    object_ptrs[0] = pokemon_ptrs[0];
    //Pikachu 2
    pokemon_ptrs[1] = new Pokemon("Bulbasaur", 2, 'P', 1.0, Point2D(10, 1));
    object_ptrs[1] = pokemon_ptrs[1];
    //PokemonCenter 1
    center_ptrs[0] = new PokemonCenter(1, 1, 100, Point2D(1, 20));
    object_ptrs[2] = center_ptrs[0];
    //PokemonCenter 2
    center_ptrs[1] = new PokemonCenter(2, 2, 200,  Point2D(10, 20));
    object_ptrs[3] = center_ptrs[1];
    //PokemonGym
    gym_ptrs[0] = new PokemonGym(10, 1.0,
                                 2.0, 3, 1, Point2D(0, 0));
    object_ptrs[4] = gym_ptrs[0];
    gym_ptrs[1] = new PokemonGym(20, 5,
                                 7.5, 8, 2, Point2D(5, 5));
    object_ptrs[5] = gym_ptrs[1];
   
    BattleArena * A1=new BattleArena(3,3,2.5,1,Point2D(15,12));
    battle_ptrs[0]=A1;
    object_ptrs[9]=battle_ptrs[0];

    rival_ptrs[0]=new Rival("burhack", 2, 16,3, 7.2, 20, 1,A1);
    rival_ptrs[1]=new Rival("mmark9", 1, 29, 4, 5.2, 12, 2, A1);
    rival_ptrs[2]=new Rival("Densmore", 3 , 41, 6, 8.2,18, 3, A1);
    object_ptrs[6]=rival_ptrs[0];
    object_ptrs[7]=rival_ptrs[1];
    object_ptrs[8]=rival_ptrs[2];
    num_objects = 10; */
   // num_pokemon = 2;
   // num_centers = 2;
   // num_gyms = 2;
   // num_rivals=3;
   // num_arena=1; 

    cout << "Model default constructed. " << endl;
}


Model::~Model() {
    for (i = object_ptrs.begin(); i!=object_ptrs.end();i++){
    //for (int j = 0; j < object_ptrs.size(); j++) {
       // object_ptrs.remove(*i);
        i = object_ptrs.erase(i); 
    }
    cout << "Model destructed. " << endl;
}

Pokemon *Model::GetPokemonPtr(int id) {
    for (j = pokemon_ptrs.begin(); j!=pokemon_ptrs.end(); j++) {
        if (id == (*j)->GetId()) {
            return *j;
        }
    }
    return 0;
}

PokemonCenter *Model::GetPokemonCenterPtr(int id) {
     for (k = center_ptrs.begin(); k!=center_ptrs.end(); k++) {
        if (id == (*k)->GetId()) {
            return *k;
        }
    }
    return 0;
}

PokemonGym *Model::GetPokemonGymPtr(int id) {
    for (l = gym_ptrs.begin(); l!=gym_ptrs.end(); l++) {
        if (id == (*l)->GetId()) {
            return *l;
        }
    } 
    return 0;
} 

Rival * Model::GetRivalPtr(int id){
	 for (n = rival_ptrs.begin(); n!=rival_ptrs.end(); n++) {
        if (id == (*n)->GetId()) {
            return *n;
        }
    }
    return 0;
}

BattleArena * Model::GetArenaPtr(int id){
 for (m = battle_ptrs.begin(); m!=battle_ptrs.end(); m++) {
        if (id == (*m)->GetId()) {
            return *m;
        }
    }
    return 0;
}

bool Model::Update() 
{
    time++;
    int gyms_beaten = 0;
    int pokemon_exhausted = 0;
    int pokemon_fainted = 0;
    int rivals_beaten=0;
    if (gyms_beaten != gym_ptrs.size()) 
    {
        for (l=gym_ptrs.begin(); l!=gym_ptrs.end(); l++) 
        {
            if((*l)->IsBeaten())
            {
                gyms_beaten++;
            }
        }
    }
    // Calculating number of pokemon that are tired
    if (pokemon_exhausted != pokemon_ptrs.size()) 
    {
        for (j=pokemon_ptrs.begin(); j!=pokemon_ptrs.end(); j++) 
        {
            if ((*j)->IsExhausted())
            { 
                pokemon_exhausted++; 
            }
        }
    }
     if (pokemon_fainted != pokemon_ptrs.size()) 
    {
        for (j=pokemon_ptrs.begin(); j!=pokemon_ptrs.end(); j++) 
        {
            if ((*j)->IsAlive()==false)
            { 
                pokemon_fainted++; 
            }
        }
    }
    if (rivals_beaten != rival_ptrs.size())
    {
        for (n=rival_ptrs.begin(); n!=rival_ptrs.end(); n++)
        {
            if ((*n)->IsAlive()==false)
            {
                rivals_beaten ++;
            }
        }
    }

    //updating active_ptrs list. //CHECK ORDER OF THESE TWO LOOPS

    // continue to update all
    if (gyms_beaten == gym_ptrs.size()) {
        cout << "GAME OVER: You win! All Pokemon Gyms beaten!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (pokemon_exhausted == pokemon_ptrs.size()) {
        cout << "GAME OVER: You lose! All of your Pokemon are exhausted!" << endl;
        exit(EXIT_SUCCESS);
    }
     if (pokemon_fainted == pokemon_ptrs.size()) {
        cout << "GAME OVER: You lose! All of your Pokemon are defeated!" << endl;
        exit(EXIT_SUCCESS);
    }
    if (rivals_beaten == rival_ptrs.size()) {
        cout << "GAME OVER: You win! All Rivals are defeated!" << endl;
        exit(EXIT_SUCCESS);
    }
    // update if winning condition is not met

 bool event=false; 
  for (i = active_ptrs.begin(); i!=active_ptrs.end();i++){
  //  for (int i = 0; i < object_ptrs.size(); i++) {
        bool temp = (*i)->Update();
        if (temp) 
        {
            event = temp; 
        }
    }
for (i=active_ptrs.begin(); i!=active_ptrs.end();i++)
{
{
    if ((*i)->IsAlive()==false)
    {
        i=active_ptrs.erase(i);
        cout<<"Dead Object Removed \n";
    }
}
}
    return event; 

}

void Model::Display(View &view) {
    view.Clear();
   // for (int i = 0; i < object_ptrs.size(); i++) {
for (i = active_ptrs.begin(); i!=active_ptrs.end();i++){
            view.Plot(*i);
    }
    view.Draw();
}

void Model::ShowStatus() {
    cout << "Time: " << time << endl;
   // for (int i = 0; i < object_ptrs.size(); i++) {
    for (i = object_ptrs.begin(); i!=object_ptrs.end();i++){
        (*i)->ShowStatus();
    
    }
}

void Model :: NewModelCommand(char type, int id, double x, double y)
{
    if (type=='g')
    {
        PokemonGym * np;
        np=new PokemonGym(10,1,1.0,2,id,Point2D(x,y));
        object_ptrs.push_back(np);
        gym_ptrs.push_back(np);
        active_ptrs.push_back(np);
    }
    else if(type=='c')
    {
        PokemonCenter * nc;
        nc=new PokemonCenter(id, 5, 100,Point2D(x,y));
        object_ptrs.push_back(nc);
        center_ptrs.push_back(nc);
        active_ptrs.push_back(nc);
        
    }
    else if(type=='p')
    {
        Pokemon * npo;
        npo=new Pokemon("New Pokemon", id, 'P', 5, Point2D(x,y));
        object_ptrs.push_back(npo);
        pokemon_ptrs.push_back(npo);
        active_ptrs.push_back(npo); 

    }
    else if(type=='r')
    {
        Rival * nr;
        BattleArena * nb;
        nb=battle_ptrs.front();
        nr=new Rival("New Rival", 5.0,4.3, 2, 3, 1, id,nb); 
        object_ptrs.push_back(nr);
        rival_ptrs.push_back(nr);
        active_ptrs.push_back(nr);
        nb->AddOneRival(); 


    }
    else
    {
        throw Invalid_Input("Invalid Parameters");
    }
}

/*catch(Invalid_Input& except)
{
    throw Invalid_Input("Invalid Parameters");
}*/
