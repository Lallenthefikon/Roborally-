#pragma once

class AbstractGame;

#include <SFML\Graphics.hpp>

class GameState
{
public:
	GameState();
	virtual ~GameState();
	virtual void update() = 0;
	virtual void render(sf::RenderWindow& window) = 0;
	virtual void initialize(sf::RenderWindow& window) = 0;
	virtual void inputEvent(sf::Event& input, AbstractGame* roborally) = 0;

};

