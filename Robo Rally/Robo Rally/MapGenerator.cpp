#include "MapGenerator.h"

#include <fstream>


MapGenerator::~MapGenerator(){
}

MapGenerator* MapGenerator::getInstance(){
	static MapGenerator mapgenerator;
	return &mapgenerator;
}

Map* MapGenerator::generateMap(std::string &filePath){
	Map* map(new Map);

	int typeIndex = 0;
	std::string line;
	std::ifstream textStream(filePath);

	if (textStream.is_open()){
		while (getline(textStream, line)){
			if (line.size() == 0)
				typeIndex++;

			switch (typeIndex){
				// Grid's
			case 0:
				MapGenerator::readGridRect(line, *map);
				break;

				// Entities
			case 1:

				break;

			default:
				break;
			}
		}
	}
	return map;
}

// Private

MapGenerator::MapGenerator(){
}

void MapGenerator::readGridRect(std::string& line, Map& map){
	sf::Vector2i startingPos;
	sf::Vector2i size;
	int sum = 0;
	int nI = 0;
	for (int i = 0; i < line.size(); i++){
		switch (line[i]){
		case '0':
			sum *= 10;
			break;
			
		case '1':
			sum *= 10;
			sum += 1;
			break;

		case '2':
			sum *= 10;
			sum += 2;
			break;

		case '3':
			sum *= 10;
			sum += 3;
			break;

		case '4':
			sum *= 10;
			sum += 4;
			break;

		case '5':
			sum *= 10;
			sum += 5;
			break;

		case '6':
			sum *= 10;
			sum += 6;
			break;

		case '7':
			sum *= 10;
			sum += 7;
			break;

		case '8':
			sum *= 10;
			sum += 8;
			break;

		case '9':
			sum *= 10;
			sum += 9;
			break;

		case ',':
			switch (nI){
			case 0:
				startingPos.x = sum;
				sum = 0;
				nI++;
				break;

			case 1:
				startingPos.y = sum;
				sum = 0;
				nI++;
				break;

			case 2:
				size.x = sum;
				sum = 0;
				nI++;
				break;
				
			default:
				break;
			}
		default:
			break;
		}
	}
	size.y = sum;
	map.addGridRect(startingPos, size);
}