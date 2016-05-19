#include "Map.h"


Map::Map(void)
{
}


Map::~Map(void)
{
}

void Map::LoadContent(std::string mapID)
{
	this->mapID = mapID;
	Layer layerInstance;
	layers.push_back(layerInstance);
	layers[0].LoadContent("Layer1", this->mapID);
}

void Map::UnloadContent()
{
	layers[0].UnloadContent();
}

void Map::Update()
{
	layers[0].Update();
}

void Map::Draw(ALLEGRO_DISPLAY *display)
{
	layers[0].Draw(display);
}