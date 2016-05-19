#pragma once

#include "GameScreen.h"
#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"
#include "GamePlayScreen.h"
#include <map>

//Allegro inits
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

#define ScreenWidth 800 
#define ScreenHeight 600

class ScreenManager
{
private:
	ScreenManager();
	ScreenManager(ScreenManager const&);
	void operator=(ScreenManager const&);

	GameScreen *currentScreen, *newScreen;

	ALLEGRO_BITMAP *transitionImage;

	Animation transition;
	FadeAnimation fade;

	void Transition();

	bool startTransition;

	std::map<std::string, GameScreen*> screenDirectory;

public:
	~ScreenManager();
	static ScreenManager &GetInstance();

	void AddScreen(std::string screenName);
	void Initialize();
	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

