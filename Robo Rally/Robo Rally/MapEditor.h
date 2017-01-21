#pragma once

#include "GameState.h"
#include "Map.h"
#include "MapEditorRescorces.h"
#include "variablesAndConstants.h"
#include "Camera.h"
#include "World.h"
#include "AbstractGame.h"
#include "HudFactory.h"
#include "Hud.h"

class MapEditor : public GameState
{
public:
	MapEditor(Map* map);
	virtual ~MapEditor();
	
	virtual void update();
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);
	virtual void inputEvent(sf::Event& input, AbstractGame* roborally);

	const float hej = 2.0;

private:

	void loadHuds();

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);
	void mouseInput(sf::Event& input, AbstractGame* roborally);

	void moveHud();

	void updateHoverTarget(int x, int y);

	void writeMapToFile();

	void clearmHuds();

	MapEditorRescorces mMapEditorRescorces;
	std::vector<Hud*> mHuds;
	World mWorld;

	std::string mMapname;
	Map* mMap;

	Camera mCamera;

	sf::Sprite mBackground;

	Hud* mHudHoverTargeted;
	Entity* mEntityHoverTargeted;
	Entity* mEntityTargeted;

	bool mMouseButtonPressedLeft;
	bool mDraggingEntity;

};

