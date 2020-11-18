#pragma once
#ifndef MapLoader_H
#define MapLoader_H
#include <string>
#include "Map.h"

class MapLoader {
public:
	MapLoader();
	~MapLoader();
	Map loadmap(std::string file);
	bool getContinentCheck();

private:
	bool continentCheck;
	bool countryCheck;
	bool borderCheck;
	bool mapCheck;
};
#endif //!map