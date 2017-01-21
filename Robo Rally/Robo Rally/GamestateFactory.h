#pragma once


#include <SFML\System.hpp>

class GameState;
class Map;

struct GamestateFactory{
	static GameState* createMapEditor(Map* map);
	static GameState* createBattlefield(Map* map);
	static GameState* createMainMeny();
};

