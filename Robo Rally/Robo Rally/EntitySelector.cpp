#include "EntitySelector.h"


EntitySelector::EntitySelector(MapEditorRescorces* mapeditorRescorces, sf::Vector2f posOnScreen) :
mBackgroundHud(mapeditorRescorces->getEntitySelectorTexture(0)),
mSprites(),
mPosOnSceen(posOnScreen)
{
	loadSprites(mapeditorRescorces);
}


EntitySelector::~EntitySelector()
{
	clearmSprites();
}

const sf::IntRect EntitySelector::getRect(){
	return mBackgroundHud.getTextureRect();
}

void EntitySelector::render(sf::RenderWindow& window){
	window.draw(mBackgroundHud);
	for (int i = 0; i < mSprites.size(); i++){
		window.draw(*mSprites[i]);
	}
}

void EntitySelector::setPos(sf::Vector2f& pos){
	sf::Vector2f difference = (pos + mPosOnSceen) - mBackgroundHud.getPosition();
	mBackgroundHud.move(difference);
	moveAllSprites(difference);
}

bool EntitySelector::updateTarget(sf::Vector2i mousePos){
	if (GraphicFunctions::getInstance()->isSpriteClicked(&mBackgroundHud.getTextureRect(), mBackgroundHud.getPosition(), mousePos)){
		return true;
	}
	else{
		return false;
	}
}

int EntitySelector::getClicked(sf::Vector2i mousePos){
	switch (checkWhatIsClicked(mousePos)){
	case 0:
		break;
	case 1:
		break;
	case 2:
		break;
	default:
		break;
	}
	return 0;
}

void EntitySelector::wheelMove(sf::Vector2i mousePos, int delta){

}

// Privates

void EntitySelector::loadSprites(MapEditorRescorces* mapeditorRescorces){
	mSprites.push_back(new sf::Sprite(mapeditorRescorces->getEntitySelectorTexture(1)));
	mSprites.back()->setPosition(mBackgroundHud.getPosition().x + 200, mBackgroundHud.getPosition().x + 200);

	mSprites.push_back(new sf::Sprite(mapeditorRescorces->getEntitySelectorTexture(2)));
	mSprites.back()->setPosition(mBackgroundHud.getPosition().x + 1000, mBackgroundHud.getPosition().x + 200);
}

void EntitySelector::moveAllSprites(sf::Vector2f vector){
	for (int i = 0; i < mSprites.size(); i++){
		mSprites[i]->move(vector);
	}
}

int EntitySelector::checkWhatIsClicked(sf::Vector2i mousePos){
	int v = 0;
	for (int i = 0; i < mSprites.size(); i++){
		if (GraphicFunctions::getInstance()->isSpriteClicked(&mSprites[i]->getTextureRect(),
			mSprites[i]->getPosition(), mousePos))
			v = i;
	}
	return v;
}

void EntitySelector::clearmSprites(){
	while (!mSprites.empty()){
		delete mSprites.back();
		mSprites.pop_back();
	}
}