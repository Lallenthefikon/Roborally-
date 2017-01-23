#pragma once

#include "Robot.h"
#include "Animations.h"

class Twitch_Robot : public Robot
{
public:

	enum states {IDLE};

	Twitch_Robot(sf::Vector2i pos);
	virtual ~Twitch_Robot();

	virtual void update();
	virtual void render(sf::RenderWindow& window);

	virtual void dragSprite(sf::Vector2i pos);
	virtual void returnSprite();

	virtual void setPos(sf::Vector2i newPos);

private:

	void setAnimation();
	states mCurrentState;
	sf::Sprite mTwitchRobo;

	sf::Vector2i mGridPos;
	Animations::Textures* mCurrentAnimations;
};

