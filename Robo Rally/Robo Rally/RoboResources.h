#pragma once  

#include <SFML\Graphics.hpp>

struct RoboResources{
	
	enum TEXTUREKEY{
		// Robo´s
		ROBOIDLETEXTURE
	};

	static RoboResources& getInstance();
	static void loadTextures();

	static sf::Image& getTexture(TEXTUREKEY texturekey);

};