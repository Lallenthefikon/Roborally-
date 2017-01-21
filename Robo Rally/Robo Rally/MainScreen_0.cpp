#include "MainScreen_0.h"


MainScreen_0::MainScreen_0(MenyRescourses* rescourses): 
mBackgroundHud(rescourses->getTextureScreen_0(0)),
mButtons(),
mPosOnSceen()
{
	mPosOnSceen = (sf::Vector2f(variablesAndConstants::getInstance()->windowSize) / 2.0f)
		- sf::Vector2f(mBackgroundHud.getTextureRect().width / 2, mBackgroundHud.getTextureRect().height / 2);
	loadSprites(rescourses);
}


MainScreen_0::~MainScreen_0()
{
	clearmButtons();
}

const sf::IntRect MainScreen_0::getRect(){
	return mBackgroundHud.getTextureRect();
}

void MainScreen_0::render(sf::RenderWindow& window){
	window.draw(mBackgroundHud);
	for (int i = 0; i < mButtons.size(); i++){
		window.draw(*mButtons[i]);
	}
}

void MainScreen_0::setPos(sf::Vector2f& pos){
	sf::Vector2f difference = (pos + mPosOnSceen) - mBackgroundHud.getPosition();
	mBackgroundHud.move(difference);
	moveAllSprites(difference);
}

bool MainScreen_0::updateTarget(sf::Vector2i mousePos){
	if (GraphicFunctions::getInstance()->isSpriteClicked(&mBackgroundHud.getTextureRect(), mBackgroundHud.getPosition(), mousePos)){
		return true;
	}
	else{
		return false;
	}
}

int MainScreen_0::getClicked(sf::Vector2i mousePos){
	return checkWhatIsClicked(mousePos);
}

void MainScreen_0::wheelMove(sf::Vector2i mousePos, int delta){

}

// Privates

void MainScreen_0::loadSprites(MenyRescourses* rescourses){

	mBackgroundHud.setPosition(mPosOnSceen);

	mButtons.push_back(new sf::Sprite(rescourses->getTextureScreen_0(1)));
	mButtons.back()->setPosition(mBackgroundHud.getPosition().x + 150, mBackgroundHud.getPosition().y + 50);

	mButtons.push_back(new sf::Sprite(rescourses->getTextureScreen_0(2)));
	mButtons.back()->setPosition(mBackgroundHud.getPosition().x + 150, mBackgroundHud.getPosition().y + 250);

	mButtons.push_back(new sf::Sprite(rescourses->getTextureScreen_0(3)));
	mButtons.back()->setPosition(mBackgroundHud.getPosition().x + 150, mBackgroundHud.getPosition().y + 450);
}

void MainScreen_0::moveAllSprites(sf::Vector2f vector){
	for (int i = 0; i < mButtons.size(); i++){
		mButtons[i]->move(vector);
	}
}

int MainScreen_0::checkWhatIsClicked(sf::Vector2i mousePos){
	int v = -1;
	for (int i = 0; i < mButtons.size(); i++){
		if (GraphicFunctions::getInstance()->isSpriteClicked(&mButtons[i]->getTextureRect(),
			mButtons[i]->getPosition(), mousePos))
			v = i;
	}
	return v;
}

void MainScreen_0::clearmButtons(){
	while (!mButtons.empty()){
		delete mButtons.back();
		mButtons.pop_back();
	}
}