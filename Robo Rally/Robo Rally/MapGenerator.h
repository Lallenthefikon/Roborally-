#pragma once

#include "Map.h"

#include <string>


class MapGenerator
{
public:
	static MapGenerator* getInstance();
	~MapGenerator();
	Map* generateMap(std::string &filePath);

private:
	MapGenerator();

	void readGridRect(std::string& line, Map& map);
};

