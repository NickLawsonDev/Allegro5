#pragma once

#include "Tile.h"
#include "FileManager.h"
#include <string>
#include <vector>
#include <algorithm>

class Layer
{
public:
	Layer(void);
	~Layer(void);

	void LoadContent(std::string layerID, std::string mapID);
	void UnloadContent();
	void Update();
	void Draw(ALLEGRO_DISPLAY *display);

private:
	FileManager fileManager;

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;
	std::vector<std::pair<int, int>> solidTiles;
	std::vector<Tile> tiles;

	std::pair<int, int> SetTiles(std::string tileString);

	ALLEGRO_BITMAP *tileSheet;
	std::string nullTile;
};

