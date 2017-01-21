#pragma once

#include "Hud.h"
#include "MapEditorRescorces.h"
#include "GraphicFunctions.h"

#include <vector>

class EntitySelector : public Hud
{
public:
	EntitySelector(MapEditorRescorces* mapeditorRescorces, sf::Vector2f posOnScreen);
	virtual ~EntitySelector();

	virtual const sf::IntRect getRect();
	virtual void render(sf::RenderWindow& window);
	virtual void setPos(sf::Vector2f& pos);
	virtual bool updateTarget(sf::Vector2i mousePos);
	virtual int getClicked(sf::Vector2i mousePos);
	virtual void wheelMove(sf::Vector2i mousePos, int delta);

private:

	void loadSprites(MapEditorRescorces* mapeditorRescorces);

	void moveAllSprites(sf::Vector2f vector);
	int checkWhatIsClicked(sf::Vector2i mousePos);

	void clearmSprites();

	sf::Sprite mBackgroundHud;
	typedef std::vector<sf::Sprite*> Sprites;
	Sprites mSprites;

	sf::Vector2f mPosOnSceen;
};

