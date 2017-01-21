#include "GamestateFactory.h"
#include "MapEditor.h"
#include "Battlefield.h"
#include "MainMeny.h"

GameState* GamestateFactory::createMapEditor(Map* map){
	return new MapEditor(map);
}

GameState* GamestateFactory::createBattlefield(Map* map){
	return new Battlefield(map);
}

GameState* GamestateFactory::createMainMeny(){
	return new MainMeny();
}