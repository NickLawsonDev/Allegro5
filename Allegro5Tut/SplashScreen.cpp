#include "SplashScreen.h"

SplashScreen::SplashScreen(void)
{
}


SplashScreen::~SplashScreen(void)
{
}

void SplashScreen::LoadContent()
{
	imageNumber = 0;
	font = al_load_font("Fonts/Orbitron Black.ttf", 30, NULL);
	fileManager.LoadContent("SplashScreen/splash.cme", attributes, contents);

	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < attributes[i].size(); j++)
		{
			if(attributes[i][j] == "Image")
			{
				std::pair<float, float> position = std::pair<float, float>(0,0);
				images.push_back(al_load_bitmap(contents[i][j].c_str()));
				animation.push_back(new FadeAnimation);
				animation[animation.size()-1]->LoadContent(images[animation.size()-1], "", position);
				animation[animation.size()-1]->IsActive() = true;;
			}
		}
	}
}

void SplashScreen::UnloadContent()
{
	al_destroy_font(font);
	for(int i = 0; i < animation.size(); ++i)
	{
		al_destroy_bitmap(images[i]);
		delete animation[i];
	}
	animation.clear();

	GameScreen::UnloadContent();
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
		ScreenManager::GetInstance().AddScreen("TitleScreen");
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
	al_draw_text(font, al_map_rgb(0,0,255), 100, 100, NULL, "SplashScreen");

}