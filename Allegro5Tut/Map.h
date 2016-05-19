#pragma once

#include "Layer.h"

class Map
{
private:
	

public:
	Map();
	~Map();

	void LoadContent(std::string mapID);
	void UnloadContent();
	void Update();
	void Draw(ALLEGRO_DISPLAY *display);

private:
	std::vector<Layer> layers;
	std::string mapID;
};

