#include "Twitch_Robot.h"


Twitch_Robot::Twitch_Robot(sf::Vector2i pos):
mGridPos(pos),
mCurrentState(IDLE),
mCurrentAnimations(Animations::getTwicthRoboANI_IDLE()),
mTwitchRobo()
{
	sf::Vector2f temp(pos);
	mTwitchRobo.setPosition(temp);
}


Twitch_Robot::~Twitch_Robot()
{
}

void Twitch_Robot::update(){

}

void Twitch_Robot::render(sf::RenderWindow& window){
	window.draw(mTwitchRobo);
}

void Twitch_Robot::dragSprite(sf::Vector2i pos){

}

void Twitch_Robot::returnSprite(){

}

void Twitch_Robot::setPos(sf::Vector2i pos){

}

void Twitch_Robot::setAnimation(){
	switch (mCurrentState){
	case IDLE:
		Animations::getTwicthRoboANI_IDLE();
		break;
	}
}