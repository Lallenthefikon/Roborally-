#include "EntityFactory.h"

#include "Twitch_Robot.h"

Robot* EntityFactory::createTwitch_Robot(sf::Vector2i pos){
	return new Twitch_Robot(pos);
}