#pragma once

#include "Hud.h"
#include "MenyRescourses.h"
#include "GraphicFunctions.h"
#include "variablesAndConstants.h"

#include <vector>

class MainScreen_0 : public Hud
{
public:
	MainScreen_0(MenyRescourses* rescourses);
	virtual ~MainScreen_0();

	virtual const sf::IntRect getRect();
	virtual void render(sf::RenderWindow& window);
	virtual void setPos(sf::Vector2f& pos);
	virtual bool updateTarget(sf::Vector2i mousePos);
	virtual int getClicked(sf::Vector2i mousePos);
	virtual void wheelMove(sf::Vector2i mousePos, int delta);

private:

	void loadSprites(MenyRescourses* mapeditorRescorces);

	void moveAllSprites(sf::Vector2f vector);
	int checkWhatIsClicked(sf::Vector2i mousePos);

	void clearmButtons();

	sf::Sprite mBackgroundHud;
	typedef std::vector<sf::Sprite*> Sprites;
	Sprites mButtons;

	sf::Vector2f mPosOnSceen;
};

