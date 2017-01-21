#pragma once
#include <SFML\Graphics.hpp>

class variablesAndConstants
{
public:
	~variablesAndConstants();
	static variablesAndConstants* getInstance();

	sf::Vector2i windowSize = sf::Vector2i(1900, 1000);
	bool cameraMoved = false;

	int tileSize = 100;

	sf::Vector2i mousePos;
	sf::Vector2f worldMousePos;

private:
	variablesAndConstants();

};

