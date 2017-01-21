#pragma once
#include <vector>


#include "GameState.h"
#include "MenyRescourses.h"
#include "variablesAndConstants.h"
#include "GraphicFunctions.h"
#include "AbstractGame.h"
#include "Camera.h"
#include "Hud.h"
#include "HudFactory.h"

typedef std::vector<sf::Sprite*> Sprites;

class MainMeny : public GameState
{
public:
	
	MainMeny();
	~MainMeny();

	virtual void update();
	virtual void render(sf::RenderWindow& window);
	virtual void initialize(sf::RenderWindow& window);
	virtual void inputEvent(sf::Event& input, AbstractGame* roborally);

private:

	void renderWorld(sf::RenderWindow& window);
	void renderHud(sf::RenderWindow& window);

	void loadHuds();

	void moveHud();
	void checkMouse(AbstractGame* roborally);
	void mainMenyEvent(int i, AbstractGame* roborally);

	void clearmHuds();
	
	Camera mCamera;
	MenyRescourses mMenyRescourses;
	std::vector<Hud*> mHuds;
	Hud* mCurrentHud;

	sf::Sprite mBackground;
	int buttonHovered;

	std::string mMapFilename;

	bool mMouseButtonPressedLeft;

};