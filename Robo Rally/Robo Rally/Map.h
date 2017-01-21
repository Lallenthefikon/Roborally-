#pragma once

#include "Entity.h"

#include <vector>
#include <set>
class Map
{
public:
	Map();
	~Map();

	void addGridRect(sf::Vector2i startingPoint, sf::Vector2i size);

	void moveEntity(Entity* entity, sf::Vector2i newPos);

	std::vector<sf::IntRect> getRects();
	int getTileSize();

	Entity* getEntity(sf::Vector2i index);
private:

	bool checkIndexInBounds(sf::Vector2i index);

	void clearMap();

	typedef std::set<Entity*> Entities;
	typedef std::vector<Entities*> yGrid;
	typedef std::vector<yGrid*> xGrid;
	xGrid* mGrid;

	std::vector<sf::IntRect> mGridRects;
};

