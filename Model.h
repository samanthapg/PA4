#ifndef MODEL_H
#define MODEL_H
#include "GameObject.h"
#include "Pokemon.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "View.h"
#include <list>
#include <iterator>

class Model {
    
public:
    //simulation time
    int time;
    list<GameObject *> object_ptrs; 
    list<GameObject *> :: iterator i; 
    //list for alive objects
    list<GameObject *> active_ptrs;
    //GameObject * object_ptrs[10];
    //int num_objects;
    //Pokemon * pokemon_ptrs[10];
    list<Pokemon *> pokemon_ptrs;
    list<Pokemon *> :: iterator j;
    //int num_pokemon;
    list<PokemonCenter *> center_ptrs;
    list<PokemonCenter *> :: iterator k;
    //PokemonCenter * center_ptrs[10];
    //int num_centers;
    list<PokemonGym *> gym_ptrs;
    list<PokemonGym *> :: iterator l;
    //PokemonGym * gym_ptrs[10];
    //int num_gyms;
    //int num_arena;
    list<BattleArena *> battle_ptrs;
    list<BattleArena *> :: iterator m;
    //BattleArena * battle_ptrs[10];
    //int num_rivals;
    list<Rival *> rival_ptrs;
    list<Rival *> :: iterator n; 
    //Rival * rival_ptrs[10];
    
public:
    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    void Display(View &view);
    void ShowStatus();
    BattleArena * GetArenaPtr(int id);
    Rival * GetRivalPtr(int id);
    void NewModelCommand(char type, int id, double x, double y);
};


#endif
