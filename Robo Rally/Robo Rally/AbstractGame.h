#pragma once

#include <string>

class AbstractGame
{
public:
	enum Gamestate{MAINMENY, BATTLEFIELD, MAPEDITOR};
	
	AbstractGame();
	virtual ~AbstractGame();
	
	virtual void changeGamestate(Gamestate gamestate) = 0;
	virtual void changeGamestate(Gamestate gamestate, std::string filename) = 0;
	virtual void exitGame() = 0;
};

