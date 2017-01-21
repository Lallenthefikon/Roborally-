#pragma once

#include <SFML\Graphics.hpp>



class Entity
{
public:
	Entity();
	virtual ~Entity();

	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	virtual void dragSprite(sf::Vector2i pos) = 0;
	virtual void returnSprite() = 0;

	virtual void setPos(sf::Vector2i newPos) = 0;

	
};

