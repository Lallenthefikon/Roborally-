#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

class MapEditorRescorces
{
public:
	MapEditorRescorces();
	~MapEditorRescorces();

	sf::Texture& getEntitySelectorTexture(int i);
	sf::Texture& getBackgroundTexture(){ return mBackgroundTexture; }
	sf::Texture& getGridTexture(sf::IntRect& rect);


private:

	void loadImages();
	void loadTextures();

	void clearTextures();

	sf::Image mBackgroundIMG;
	sf::Image mSpritesheetIMG;
	sf::Image mGridIMG;

	std::vector<sf::Texture*> mTextures;
	sf::Texture mBackgroundTexture;
	std::vector<sf::Texture*> mGridTextures;
};

