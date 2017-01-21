#include "RoboRally.h"



RoboRally::RoboRally() :
mGamestate(AbstractGame::Gamestate::MAINMENY),
mCurrentGamestate(GamestateFactory::createMainMeny()),
mExitGame(false),
mGamestateChanged(false)
{
}


RoboRally::~RoboRally()
{
}

void RoboRally::runGame(){
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Robbo Rally");
	window.setFramerateLimit(60);
	mCurrentGamestate->initialize(window);

	while (window.isOpen()){

		checkEvents(window);

		window.clear();
		mCurrentGamestate->update();
		mCurrentGamestate->render(window);
		window.display();

		if (mGamestateChanged){
			changeGameStateEXE();
			mCurrentGamestate->initialize(window);
		}
		if (mExitGame)
			window.close();
	}
}

void RoboRally::changeGamestate(AbstractGame::Gamestate gamestate){
	mGamestate = gamestate;
	mGamestateChanged = true;
}

void RoboRally::changeGamestate(AbstractGame::Gamestate gamestate, std::string filename){
	mGamestate = gamestate;
	mGamestateChanged = true;
	mMapFilename = filename;
}

void RoboRally::exitGame(){
	mExitGame = true;
}

// Privates

void RoboRally::changeGameStateEXE(){
	delete mCurrentGamestate;
	switch (mGamestate){
	case AbstractGame::MAINMENY:
		mCurrentGamestate = GamestateFactory::createMainMeny();
		break;
	case AbstractGame::BATTLEFIELD:
		mCurrentGamestate = GamestateFactory::createBattlefield(MapGenerator::getInstance()->generateMap(mMapFilename));
		break;
	case AbstractGame::MAPEDITOR:
		mCurrentGamestate = GamestateFactory::createMapEditor(MapGenerator::getInstance()->generateMap(mMapFilename));
	default:
		break;
	}
	mGamestateChanged = false;
}

void RoboRally::checkEvents(sf::RenderWindow& window){
	sf::Event event;
	while (window.pollEvent(event))
	{
		switch (event.type)
		{


		case sf::Event::Closed:
			window.close();
			break;

		case sf::Event::MouseMoved:
		case sf::Event::MouseButtonPressed:
		case sf::Event::MouseButtonReleased:
		case sf::Event::MouseWheelMoved:
			mCurrentGamestate->inputEvent(event, this);
			break;
		default:
			break;
		}
	}
}
