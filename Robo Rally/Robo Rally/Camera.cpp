#include "Camera.h"

static const int MOUSE_OOB_OFFSET = 15;
static const int ZOOM_SPEED_divider = 10;
static const float MAX_ZOOM = 0.5;
static const float MIN_ZOOM = 2;

Camera::Camera() :
mWindow(),
mCurrentView(),
mMouseLeftOfWindow(false),
mMouseRightOfWindow(false),
mMouseTopOfWindow(false),
mMouseBottomOfWindow(false),
mViewNeedUpdate(false),
mCameraSpeed(7.f),
mZoom(1)
{
}

Camera::~Camera()
{
}

void Camera::update(){
	if (mViewNeedUpdate){
		updateWindow();
	}
}


void Camera::setWindow(sf::RenderWindow* window){
	mWindow = window;
	mCurrentView = window->getView();
}

sf::Vector2f Camera::getViewPos()const{
	sf::Vector2f temp = mCurrentView.getCenter();
	temp.x -= mCurrentView.getSize().x / 2;
	temp.y -= mCurrentView.getSize().y / 2;
	return temp;
}

sf::Vector2f Camera::getViewSize()const{
	return mCurrentView.getSize();
}

void Camera::checkMouseViewMove(sf::Vector2i mousePos){
	if (mouseInBounds(mousePos)){
		mMouseLeftOfWindow = false;
		mMouseRightOfWindow = false;
		mMouseTopOfWindow = false;
		mMouseBottomOfWindow = false;
		mViewNeedUpdate = false;
	}
	else {
		OOB_Check(mousePos);
		mViewNeedUpdate = true;
	}
}

void Camera::zoom(float delta){
	if (delta < 0 && mZoom > MIN_ZOOM){
		float temp = (delta / ZOOM_SPEED_divider) +1;
		mZoom *= temp;
		mCurrentView.zoom(temp + 1);
		mWindow->setView(mCurrentView);
	}
	else if (mZoom < MAX_ZOOM){
		float temp = (delta / ZOOM_SPEED_divider) + 1;
		mZoom *= temp;
		mCurrentView.zoom(temp );
		mWindow->setView(mCurrentView);
	}
}

// Privates

bool Camera::mouseInBounds(sf::Vector2i mousePos){
	if (mousePos.y > MOUSE_OOB_OFFSET &&
		mousePos.y < mCurrentView.getSize().y - MOUSE_OOB_OFFSET &&
		mousePos.x > MOUSE_OOB_OFFSET &&
		mousePos.x < mCurrentView.getSize().x - MOUSE_OOB_OFFSET){
		return true;
	}
	else{
		return false;
	}
}

void Camera::OOB_Check(sf::Vector2i mousePos){
	if (mousePos.x <= MOUSE_OOB_OFFSET)
		mMouseLeftOfWindow = true;
	else if (mousePos.x >= mCurrentView.getSize().x - MOUSE_OOB_OFFSET)
		mMouseRightOfWindow = true;
	if (mousePos.y <= MOUSE_OOB_OFFSET)
		mMouseTopOfWindow = true;
	else if (mousePos.y >= mCurrentView.getSize().y - MOUSE_OOB_OFFSET)
		mMouseBottomOfWindow = true;
}

void Camera::updateWindow(){
	sf::Vector2f temp;
	if (mMouseLeftOfWindow)
		temp.x -= mCameraSpeed * mZoom;
	else if (mMouseRightOfWindow)
		temp.x += mCameraSpeed * mZoom;
	if (mMouseTopOfWindow)
		temp.y -= mCameraSpeed * mZoom;
	else if (mMouseBottomOfWindow)
		temp.y += mCameraSpeed * mZoom;
	mCurrentView.move(temp);

	mWindow->setView(mCurrentView);
}
