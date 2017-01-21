#pragma once

#include "variablesAndConstants.h"
#include "AbstractGame.h"
#include "GameState.h"
#include "MapGenerator.h"
#include "GamestateFactory.h"
#include "Camera.h"


class RoboRally : public AbstractGame
{
public:
	RoboRally();
	virtual ~RoboRally();

	virtual void changeGamestate(AbstractGame::Gamestate gamestate);
	virtual void changeGamestate(AbstractGame::Gamestate gamestate, std::string filename);
	virtual void exitGame();
	
	void runGame();
private:

	void changeGameStateEXE();

	void checkEvents(sf::RenderWindow& window);

	AbstractGame::Gamestate mGamestate;
	GameState* mCurrentGamestate;
	
	bool mExitGame;
	bool mGamestateChanged;

	std::string mMapFilename;
};

