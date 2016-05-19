#include "Layer.h"


Layer::Layer(void)
{
}


Layer::~Layer(void)
{
}

std::pair<int, int> Layer::SetTiles(std::string tileString)
{
	std::pair<int, int> tile;
	tile.first = atoi(tileString.substr(0, tileString.find(',')).c_str());
	tile.second = atoi(tileString.substr(tileString.find(',') + 1).c_str());
	return tile;
}

void Layer::LoadContent(std::string layerID, std::string mapID)
{
	std::string fileName = "Maps/"+mapID+".txt";
	fileManager.LoadContent(fileName.c_str(), attributes, contents, layerID);
	int indexY = 0;

	std::cout << attributes.size() << std::endl << std::endl;
	std::cout << contents.size() << std::endl << std::endl;

	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < contents[i].size(); j++)
		{
			std::cout << attributes[i][j] << std::endl << std::endl;
			if(attributes[i][j] == "SolidTiles")
				solidTiles.push_back(SetTiles(contents[i][j]));
			else if(attributes[i][j] == "TileSheet")
				tileSheet = al_load_bitmap(contents[i][j].c_str());
			else if(attributes[i][j] == "StartLayer")
			{
				for(int k = 0; k < contents[i].size(); k++)
				{
					if(contents[i][k] != "---")
					{
						std::cout << contents[i][k] << std::endl << std::endl;

						ALLEGRO_BITMAP *tileImage;
						Tile::State tempState = Tile::State::Passive;
						std::pair<int, int> tile = SetTiles(contents[i][k]);

						if(std::find(solidTiles.begin(), solidTiles.end(), tile)  != solidTiles.end())
						{
							tempState = Tile::State::Solid;
						}

						tileImage = al_create_sub_bitmap(tileSheet, tile.first * 32, tile.second * 32, 32, 32);

						std::pair<float, float> position(k * 32, indexY * 32);

						Tile tileInstance;
						tiles.push_back(tileInstance);
						tiles[tiles.size()-1].SetContent(tileImage, tempState, position);
					}
				}
				indexY++;
			}
		}
	}
}

void Layer::UnloadContent()
{
	for(int i = 0; i < tiles.size(); i++)
		tiles[i].UnloadContent();

	al_destroy_bitmap(tileSheet);
}

void Layer::Update()
{
}

void Layer::Draw(ALLEGRO_DISPLAY *display)
{
	for(int i = 0; i < tiles.size(); i++)
		tiles[i].Draw(display);
}
