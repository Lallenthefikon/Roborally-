#include "HudFactory.h"

#include "EntitySelector.h"
#include "MainScreen_0.h"

Hud* HudFactory::createEntitySelector(MapEditorRescorces* reascorses, sf::Vector2f posOnScreen){
	return new EntitySelector(reascorses, posOnScreen);
}

Hud* HudFactory::createMainScreen_0(MenyRescourses* rescourses){
	return new MainScreen_0(rescourses);
}