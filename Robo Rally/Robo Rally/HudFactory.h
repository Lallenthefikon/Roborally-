#pragma once

#include <SFML\System.hpp>

class Hud;
class MapEditorRescorces;
class MenyRescourses;

struct HudFactory{
	static Hud* createEntitySelector(MapEditorRescorces* reascorses, sf::Vector2f posOnScreen);
	static Hud* createMainScreen_0(MenyRescourses* rescourses);
};
