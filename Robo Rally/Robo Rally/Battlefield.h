#pragma once

#include "Map.h"
#include "GameState.h"
#include "EntityHandler.h"
#include "Camera.h"
#include "AbstractGame.h"


class Battlefield : public GameState
{
public:
	Battlefield(Map* map);
	virtual ~Battlefield();

	virtual void update();
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);
	virtual void inputEvent(sf::Event& input, AbstractGame* roborally);

private:

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);

	Map* mMap;
	Camera mCamera;

};

