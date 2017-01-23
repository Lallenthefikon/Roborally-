#include "RoboResources.h"

static sf::Image mRoboSheet;

RoboResources& RoboResources::getInstance(){
	static RoboResources roboresources;
	return roboresources;
}

void RoboResources::loadTextures(){
	if (mRoboSheet.getSize().x <= 0)
		mRoboSheet.loadFromFile("Resources\Images\Robo Images\Heart spritesheet");
}

sf::Image& RoboResources::getTexture(TEXTUREKEY texturekey){
	switch (texturekey){

	case ROBOIDLETEXTURE:
		return mRoboSheet;
		break;

	}
}