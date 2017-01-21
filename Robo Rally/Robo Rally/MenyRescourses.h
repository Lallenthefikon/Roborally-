#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class MenyRescourses
{
public:
	MenyRescourses();
	~MenyRescourses();

	sf::Texture& getTextureScreen_0(int i);
	sf::Texture& getBackgroundTexture(){ return mBackgroundTexture; }
private:
	
	void loadImages();
	void loadTextures();

	void clearmTextures();

	sf::Image mMenyspritesheetIMG;
	sf::Image mBackgroundIMG;

	std::vector<sf::Texture*> mTextures;
	sf::Texture mBackgroundTexture;
};

