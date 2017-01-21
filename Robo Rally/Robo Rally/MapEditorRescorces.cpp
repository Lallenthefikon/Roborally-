#include "MapEditorRescorces.h"


MapEditorRescorces::MapEditorRescorces()
{
	loadImages();
	loadTextures();
}


MapEditorRescorces::~MapEditorRescorces()
{
	clearTextures();
}

sf::Texture& MapEditorRescorces::getEntitySelectorTexture(int i){
	return *mTextures[i];
}

sf::Texture& MapEditorRescorces::getGridTexture(sf::IntRect& rect){
	mGridTextures.push_back(new sf::Texture);
	mGridTextures.back()->loadFromImage(mGridIMG, sf::IntRect(0, 0, rect.width, rect.height));
	return *mGridTextures.back();
}

// Privates

void MapEditorRescorces::loadImages(){
	mSpritesheetIMG.loadFromFile("Resources/MainMeny Rescourses/Images/34742.jpg");
	mBackgroundIMG.loadFromFile("Resources/MainMeny Rescourses/Images/robo rally.jpg");
	mGridIMG.loadFromFile("Resources/Images/World Images/testGrid.jpg");
}

void MapEditorRescorces::loadTextures(){

	// Background
	mBackgroundTexture.loadFromImage(mBackgroundIMG);

	// Spritesheet
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(0, 0, 300, 300));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(100, 0, 300, 300));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mSpritesheetIMG, sf::IntRect(0, 100, 300, 300));

}


void MapEditorRescorces::clearTextures(){
	while (!mTextures.empty()){
		delete mTextures.back();
		mTextures.pop_back();
	}
	while (!mGridTextures.empty()){
		delete mGridTextures.back();
		mGridTextures.pop_back();
	}
}
