#include "MapEditor.h"

static const int NrOfTextures = 0;

MapEditor::MapEditor(Map* map) :
mMapEditorRescorces(),
mMap(map),
mMapname(),
mBackground(),
mCamera(),
mWorld(map->getRects(), &mMapEditorRescorces),
mMouseButtonPressedLeft(false),
mDraggingEntity(false)
{

}


MapEditor::~MapEditor(){
	delete mMap;
}

void MapEditor::update(){
	mCamera.update();
	if (mCamera.getViewNeedUpdate())
		moveHud();
}

void MapEditor::render(sf::RenderWindow& window){
	window.draw(mBackground);
	renderWorld(window);
	renderHud(window);
}

void MapEditor::initialize(sf::RenderWindow& window){
	mCamera.setWindow(&window);
	loadHuds();
}

void MapEditor::inputEvent(sf::Event& input, AbstractGame* roborally){
	mouseInput(input, roborally);
	
}

// Privates

void MapEditor::loadHuds(){
	mHuds.push_back(HudFactory::createEntitySelector(&mMapEditorRescorces, sf::Vector2f(0, 0)));
}

void MapEditor::renderWorld(sf::RenderWindow& window){
	mWorld.render(window);
}

void MapEditor::renderHud(sf::RenderWindow& window){
	for (int i = 0; i < mHuds.size(); i++){
		mHuds[i]->render(window);
	}
}

void MapEditor::mouseInput(sf::Event& input, AbstractGame* roborally){
	sf::Vector2i mousePos(input.mouseMove.x, input.mouseMove.y);
	sf::Vector2i gridHovered((mCamera.getViewPos().x + mousePos.x) / mMap->getTileSize(),
		(mCamera.getViewPos().y + mousePos.y) / mMap->getTileSize());
	switch (input.type){
	case sf::Event::MouseMoved:
		mCamera.checkMouseViewMove(mousePos);
		if (mMouseButtonPressedLeft){
			mMouseButtonPressedLeft = false;
			if (mEntityHoverTargeted != 0){
				mDraggingEntity = true;
				mEntityTargeted = mEntityHoverTargeted;
			}
		}
		if (mDraggingEntity){
			mEntityTargeted->dragSprite(mousePos);
		}

		updateHoverTarget(input.mouseMove.x, input.mouseMove.y);
		break;

	case sf::Event::MouseButtonPressed:
		if (input.mouseButton.button == sf::Event::MouseLeft)
			mMouseButtonPressedLeft = true;
		break;

	case sf::Event::MouseButtonReleased:
		if (input.mouseButton.button == sf::Event::MouseLeft){

			if (mDraggingEntity){
				mDraggingEntity = false;
				mEntityTargeted->setPos(gridHovered);
				mEntityTargeted->returnSprite();
			}
			else if (mHudHoverTargeted != 0 && mMouseButtonPressedLeft == true){
				mHudHoverTargeted->getClicked(mousePos);
			}
			else if (mEntityHoverTargeted != 0){
				mEntityTargeted = mEntityHoverTargeted;
			}
		}
		mMouseButtonPressedLeft = false;
		break;

	case sf::Event::MouseWheelScrolled:
		if (mHudHoverTargeted != 0)
			mHudHoverTargeted->wheelMove(mousePos, input.mouseWheelScroll.delta);
		else{
			mCamera.zoom(input.mouseWheelScroll.delta);
			//yee boiiiiii
		}
		break;
	default:
		break;
	}
}

void MapEditor::moveHud(){
	for (int i = 0; i < mHuds.size(); i++){
		mHuds[i]->setPos(mCamera.getViewPos());
	}
}

void MapEditor::updateHoverTarget(int x, int y){
	sf::Vector2i mousePos(x, y);
	if (mHudHoverTargeted != 0){
		if (!mHudHoverTargeted->updateTarget(mousePos)){
			mHudHoverTargeted = 0;
			updateHoverTarget(x, y);
		}
	}
	else{
		for (int i = 0; i < mHuds.size(); i++){
			if (mHuds[i]->updateTarget(mousePos))
				mHudHoverTargeted = mHuds[i];
		}

		if (mHudHoverTargeted == 0){
			sf::Vector2i tileIndex(mCamera.getViewPos().x + x * 0.01, mCamera.getViewPos().y + y * 0.01);
			mEntityHoverTargeted = mMap->getEntity(tileIndex);
		}
	}
}

void MapEditor::clearmHuds(){
	while (!mHuds.empty()){
		delete mHuds.back();
		mHuds.pop_back();
	}
}