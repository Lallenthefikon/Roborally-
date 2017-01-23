#pragma once

#include "SFML\Graphics.hpp"
#include "RoboResources.h"
#include <vector>

struct Animations{
	typedef std::vector<sf::Texture*> Textures; 
	static void loadTextures();
	static Textures* getTwicthRoboANI_IDLE();
};