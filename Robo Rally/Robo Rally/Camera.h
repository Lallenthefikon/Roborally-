#pragma once

#include "variablesAndConstants.h"
#include "GraphicFunctions.h"

class Camera
{
public:
	Camera();
	~Camera();

	void update();
	void setWindow(sf::RenderWindow* window);

	sf::Vector2f getViewPos()const;
	sf::Vector2f getViewSize()const;
	bool getViewNeedUpdate()const{ return mViewNeedUpdate; }

	void checkMouseViewMove(sf::Vector2i mousePos);
	void zoom(float delta);

private:

	bool mouseInBounds(sf::Vector2i mousePos);

	void OOB_Check(sf::Vector2i mousePos);

	void updateWindow();

	sf::RenderWindow* mWindow;
	sf::View mCurrentView;

	float mCameraSpeed;
	float mZoom;

	bool mMouseLeftOfWindow;
	bool mMouseRightOfWindow;
	bool mMouseTopOfWindow;
	bool mMouseBottomOfWindow;
	bool mViewNeedUpdate;
};

