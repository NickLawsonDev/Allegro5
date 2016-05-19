#pragma once

#include "ScreenManager.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

class SplashScreen : public GameScreen
{
private:
	ALLEGRO_FONT *font;

	std::vector<ALLEGRO_BITMAP*> images;
	std::vector<Animation*> animation;

	FadeAnimation fAnimation;

	int imageNumber;
public:
	SplashScreen();
	~SplashScreen();

	virtual void LoadContent();
	virtual void UnloadContent();
	virtual void Update(ALLEGRO_EVENT ev);
	virtual void Draw(ALLEGRO_DISPLAY *display);
};

