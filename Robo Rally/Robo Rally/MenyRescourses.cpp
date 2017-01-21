#include "MenyRescourses.h"


MenyRescourses::MenyRescourses()
{
	loadImages();
	loadTextures();
}


MenyRescourses::~MenyRescourses()
{
	clearmTextures();
}

sf::Texture& MenyRescourses::getTextureScreen_0(int i){
	return *mTextures[i];
}

// Privates

void MenyRescourses::loadImages(){
	mMenyspritesheetIMG.loadFromFile("Resources/MainMeny Rescourses/Images/34742.jpg");
	mBackgroundIMG.loadFromFile("Resources/MainMeny Rescourses/Images/robo rally.jpg");
}

void MenyRescourses::loadTextures(){

	// Background
	mBackgroundTexture.loadFromImage(mBackgroundIMG);

	// Spritesheet
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(300, 0, 650, 980));
	
	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(0, 0, 185, 85));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(0, 85, 285, 65));

	mTextures.push_back(new sf::Texture);
	mTextures.back()->loadFromImage(mMenyspritesheetIMG, sf::IntRect(0, 150, 255, 73));
}

void MenyRescourses::clearmTextures(){
	while (!mTextures.empty()){
		delete mTextures.back();
		mTextures.pop_back();
	}
}