#include "Animations.h"

static sf::Image& mTwitchRoboIMG(RoboResources::getTexture(RoboResources::ROBOIDLETEXTURE));

Animations::Textures mTwitchRoboANI;

void Animations::loadTextures(){
	int x = 0;
	int y = 0;

	if (mTwitchRoboANI.size() == 0){
		for (int i = 0; i < 16; i++){
			mTwitchRoboANI.push_back(new sf::Texture);
			mTwitchRoboANI[i]->loadFromImage(mTwitchRoboIMG, sf::IntRect((75 * x), (100 * y), 75, 100));
			mTwitchRoboANI[i]->setSmooth(true);
			x++;
			if (x == 4){
				x = 0;
				y++;
			}
		}
		x = 0;
		y = 0;
	}
}

Animations::Textures* Animations::getTwicthRoboANI_IDLE(){
	return &mTwitchRoboANI;
}