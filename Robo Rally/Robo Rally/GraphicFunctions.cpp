#include "GraphicFunctions.h"




GraphicFunctions::~GraphicFunctions()
{
}

GraphicFunctions* GraphicFunctions::getInstance(){
	static GraphicFunctions graphicfunctions;
	return &graphicfunctions;
}

bool GraphicFunctions::isSpriteClicked(const sf::IntRect* rect, sf::Vector2f rectPos, sf::Vector2i mousePos){
	if (
		mousePos.y > rectPos.y &&
		mousePos.y < rectPos.y + rect->height &&
		mousePos.x > rectPos.x &&
		mousePos.x < rectPos.x + rect->width
		){
		return true;
	}
	else{
		return false;
	}
}


// Privates
GraphicFunctions::GraphicFunctions()
{
}