#pragma once
#include <SFML\Graphics.hpp>

class GraphicFunctions
{
public:

	~GraphicFunctions();
	static GraphicFunctions* getInstance();
	static bool isSpriteClicked(const sf::IntRect* rect, sf::Vector2f rectPos, sf::Vector2i mousePos);
private:
	GraphicFunctions();
};

