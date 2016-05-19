#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
	static ScreenManager instance;
	return instance;
}

ScreenManager::ScreenManager(void)
{
}


ScreenManager::~ScreenManager(void)
{
}

void ScreenManager::AddScreen(std::string screenName)
{
	transition.Alpha() = 0;
	fade.SetIncrease(true);
	startTransition = true;
	newScreen = screenDirectory[screenName];
	transition.IsActive() = true;
}

void ScreenManager::Initialize()
{
	screenDirectory["SplashScreen"] = new SplashScreen();
	screenDirectory["TitleScreen"] = new TitleScreen();
	screenDirectory["GamePlayScreen"] = new GamePlayScreen();

	currentScreen = screenDirectory["GamePlayScreen"];
}

void ScreenManager::LoadContent()
{
	currentScreen->LoadContent();
	transitionImage = al_load_bitmap("FadeAnimation\\transition.png");
	std::pair<float, float> position = std::pair<float, float>(0,0);
	transition.LoadContent(transitionImage, "", position);
	startTransition = false;
}

void ScreenManager::UnloadContent()
{
	al_destroy_bitmap(transitionImage);
	transition.UnloadContent();
	currentScreen->UnloadContent();

	std::map<std::string, GameScreen*>::iterator it; 

	for(it = screenDirectory.begin(); it != screenDirectory.end(); it++)
		delete it->second;

	screenDirectory.clear();
}

void ScreenManager::Update(ALLEGRO_EVENT ev)
{
	if(!startTransition)
		currentScreen->Update(ev);
	else
		Transition();
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
	currentScreen->Draw(display);
	if(startTransition)
		transition.Draw(display);
}

void ScreenManager::Transition()
{
	fade.Update(transition);
	if(transition.Alpha() >= 255)
	{
		transition.Alpha() = 255;
		currentScreen->UnloadContent();
		currentScreen = newScreen;
		currentScreen->LoadContent();
		al_rest(1.0f);
	}
	else if(transition.Alpha() <= 0)
	{
		startTransition = false;
		transition.IsActive() = false;
	}
}