#pragma once

#include "GameScreen.h"
#include "Player.h"
#include "Map.h"

class GamePlayScreen : public GameScreen
{
private:
	Map map;
	Player player;

public:
	GamePlayScreen(void);
	~GamePlayScreen(void);

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

