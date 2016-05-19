#pragma once

#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include "MenuManager.h"

class TitleScreen : public GameScreen
{
private:
	ALLEGRO_FONT *font;

	MenuManager menu;
public:
	TitleScreen();
	~TitleScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);
};

