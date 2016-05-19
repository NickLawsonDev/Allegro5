#include "GamePlayScreen.h"


GamePlayScreen::GamePlayScreen(void)
{
}


GamePlayScreen::~GamePlayScreen(void)
{
}

void GamePlayScreen::LoadContent()
{
	map.LoadContent("map1");
	player.LoadContent();
}

void GamePlayScreen::UnloadContent()
{
	GameScreen::UnloadContent();
	player.UnloadContent();
	map.UnloadContent();
}

void GamePlayScreen::Update(ALLEGRO_EVENT ev)
{
	player.Update(ev, input);
	map.Update();
}

void GamePlayScreen::Draw(ALLEGRO_DISPLAY *display)
{
	map.Draw(display);
	player.Draw(display);
}