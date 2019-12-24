#include "GameCommand.h"
#include "Input_Handling.h"
#include <iostream>

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to " << p1 << endl;
        model.GetPokemonPtr(pokemon_id)->StartMoving(p1);
    } 
    else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonCenterPtr(center_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to center " << center_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToCenter(model.GetPokemonCenterPtr(center_id));
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetPokemonGymPtr(gym_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to gym " << gym_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToGym(model.GetPokemonGymPtr(gym_id));
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoStopCommand(Model& model, int pokemon_id) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Stopping " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
        model.GetPokemonPtr(pokemon_id)->Stop();
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Training " << model.GetPokemonPtr(pokemon_id)->GetName() << endl;
        model.GetPokemonPtr(pokemon_id)->StartTraining(training_units);
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points) {
    if (model.GetPokemonPtr(pokemon_id) != 0) {
        cout << "Recovering " << model.GetPokemonPtr(pokemon_id)->GetName() << "'s stamina" << endl;
        model.GetPokemonPtr(pokemon_id)->StartRecoveringStamina(stamina_points);
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoMoveToArenaCommand(Model & model, int pokemon_id, int arena_id)
{ if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetArenaPtr(arena_id) != 0) {
        cout << "Moving " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " to arena " << arena_id << endl;
        model.GetPokemonPtr(pokemon_id)->StartMovingToArena(model.GetArenaPtr(arena_id));
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }
}

void DoReadyToBattleCommand(Model & model, int pokemon_id, int rival_id)
{ if (model.GetPokemonPtr(pokemon_id) != 0 && model.GetRivalPtr(rival_id) != 0) {
        cout << "Battling " << model.GetPokemonPtr(pokemon_id)->GetName()
             << " with Rival  " << rival_id << endl;
        model.GetPokemonPtr(pokemon_id)->ReadyBattle(model.GetRivalPtr(rival_id));
    } else
       {
        throw Invalid_Input("Invalid Parameters");
       // cout << "ERROR: Please enter a valid command!" << endl;
       }

}


void DoGoCommand(Model& model, View& view) {
    cout << "Advancing one tick." << endl;
    model.Update();
    model.ShowStatus();
    model.Display(view);
}

void DoRunCommand(Model& model, View& view) {
    cout << "Advancing to next event." << endl;
    int count = 0;
    bool event = false;
    while (count < 5 && event==false) {
        event = model.Update();
        count++;
    }
    model.ShowStatus();
    model.Display(view);
}

void NewCommand(Model& model, char type, int id, double x, double y)
{
    if (type=='g')
    {
        if (model.GetPokemonGymPtr(id)==0)
        {
            model.NewModelCommand(type, id, x, y); 
        }
        else
        {
           // "it exists\n";
            throw Invalid_Input("ID already exists");
        }
    }
    else if(type =='c')
    {
        if (model.GetPokemonCenterPtr(id)==0)
        {
            model.NewModelCommand(type, id, x, y); 
        }
        else
        {
            throw Invalid_Input("ID already exists");
            //exception check
        }
    }
    else if(type =='p')
    {
        if (model.GetPokemonPtr(id)==0)
        {
            model.NewModelCommand(type, id, x, y); 
        }
        else
        {
          throw Invalid_Input("ID already exists");

        }
    }
    else if(type =='r')
    {
        if (model.GetRivalPtr(id)==0)
        {
            model.NewModelCommand(type, id, x, y); 
        }
        else
        {
            throw Invalid_Input("ID already exists");
        }
    }
}


