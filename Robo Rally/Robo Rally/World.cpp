#include "World.h"


World::World(std::vector<sf::IntRect> rects, MapEditorRescorces* reascoursces):
mGridSprites(),
mReascorses(reascoursces)
{
	loadSprites(rects);
}


World::~World()
{
}

void World::render(sf::RenderWindow& window){
	for (int i = 0; i < mGridSprites.size(); i++){
		window.draw(*mGridSprites[i]);
	}
}

void World::loadSprites(Rects rects){

	for (int i = 0; i < rects.size(); i++){
		mGridSprites.push_back(new sf::Sprite);
		mGridSprites.back()->setPosition(rects[i].left, rects[i].top);
		mGridSprites.back()->setTextureRect(sf::IntRect(0,0,rects[i].width, rects[i].height));
		mGridSprites.back()->setTexture(mReascorses->getGridTexture(rects[i]));
	}
}