#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

#include "MapEditorRescorces.h"

class World
{
public:
	typedef std::vector<sf::IntRect> Rects;
	typedef std::vector<sf::Sprite*> Sprites;

	World(Rects rects, MapEditorRescorces* reascoursces);
	~World();

	void render(sf::RenderWindow& window);


private:

	MapEditorRescorces* mReascorses;

	void loadSprites(Rects rects);
	Sprites mGridSprites;
};

