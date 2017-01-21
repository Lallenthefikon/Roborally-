#pragma once

#include "Entity.h"

class Robot : public Entity
{
public:
	Robot();
	virtual ~Robot();

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void dragSprite(sf::Vector2i pos) = 0;
	virtual void returnSprite() = 0;

	virtual void setPos(sf::Vector2i newPos) = 0;
};

