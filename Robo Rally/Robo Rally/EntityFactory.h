#pragma once

#include <SFML\System.hpp>

class Entity;
class Robot;

struct EntityFactory{

	static Robot* createTwitch_Robot(sf::Vector2i pos);
	
};

