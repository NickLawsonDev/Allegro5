#pragma once

#include <allegro5/allegro.h>
#include <iostream>
#include "Animation.h"

class Tile
{
public:
	Tile(void);
	~Tile(void);

	static enum State { Solid, Passive };

	void SetContent(ALLEGRO_BITMAP *tileImage, State state, std::pair<float, float> position);
	void UnloadContent();
	void Update();
	void Draw(ALLEGRO_DISPLAY *display);

private:
	Animation tileAnimation;
	State state;
	ALLEGRO_BITMAP *image;
};

