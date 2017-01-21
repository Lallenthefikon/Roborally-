#include "MainMeny.h"



MainMeny::MainMeny() :
mMenyRescourses(),
mBackground(mMenyRescourses.getBackgroundTexture()),
mCamera(),
mMouseButtonPressedLeft(false)
{
}


MainMeny::~MainMeny(){
	clearmHuds();
}

void MainMeny::update(){
		
}

void MainMeny::render(sf::RenderWindow& window){
	renderWorld(window);
	renderHud(window);
}

void MainMeny::initialize(sf::RenderWindow& window){
	mCamera.setWindow(&window);
	loadHuds();
	
}

void MainMeny::inputEvent(sf::Event& input, AbstractGame* roborally){
	sf::Vector2i mousePos(input.mouseButton.x, input.mouseButton.y);
	switch (input.type){
	case sf::Event::MouseMoved:
		mCurrentHud->updateTarget(mousePos);
		break;

	case sf::Event::MouseButtonPressed:
		mMouseButtonPressedLeft = true;
		break;

	case sf::Event::MouseButtonReleased:
		if (mCurrentHud->updateTarget(mousePos))
			mainMenyEvent(mCurrentHud->getClicked(mousePos), roborally);
		break;
	default:
		break;
	}
}

// Privates

void MainMeny::renderWorld(sf::RenderWindow& window){
	window.draw(mBackground);
}

void MainMeny::renderHud(sf::RenderWindow& window){
	mCurrentHud->render(window);
}

void MainMeny::loadHuds(){
	mHuds.push_back(HudFactory::createMainScreen_0(&mMenyRescourses));
	mCurrentHud = mHuds[0];
}


void MainMeny::moveHud(){
}

void MainMeny::mainMenyEvent(int i, AbstractGame* roborally){
	switch (i){
	case 0:
		roborally->exitGame();
		break;

	case 1:
		mMapFilename = "Resources/Maps/Prebuilt maps/Test Map_0.txt";
		roborally->changeGamestate(AbstractGame::BATTLEFIELD, mMapFilename);
		break;

	case 2:
		mMapFilename = "Resources/Maps/Prebuilt maps/Test Map_0.txt";
		roborally->changeGamestate(AbstractGame::MAPEDITOR, mMapFilename);
		break;

	default:
		break;
	}
}


void MainMeny::clearmHuds(){
	while (!mHuds.empty()){
		delete mHuds.back();
		mHuds.pop_back();
	}
}

