#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H
#include "Point2D.h"
#include "Model.h"
#include "View.h"

	void DoMoveCommand(Model & model, int pokemon_id, Point2D p1);
	void DoMoveToCenterCommand(Model & model, int pokemon_id, int center_id);
	void DoMoveToGymCommand(Model & model, int pokemon_id, int gym_id);
	void DoStopCommand(Model & model, int pokemon_id);
	void DoTrainInGymCommand(Model & model, int pokemon_id, unsigned int training_units);
	void DoRecoverInCenterCommand(Model & model, int pokemon_id, unsigned int stamina_points);
	void DoGoCommand(Model & model, View & view);
	void DoRunCommand(Model & model, View & view);
	void DoReadyToBattleCommand(Model & model, int pokemon_id, int rival_id); 
	void DoMoveToArenaCommand(Model & model, int pokemon_id, int arena_id);
	void NewCommand(Model & model, char type, int id, double x, double y);
	


#endif 