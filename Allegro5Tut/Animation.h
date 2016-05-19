#pragma once

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <string>
#include "GameScreen.h"

class Animation
{
public:
	Animation(void);
	~Animation(void);

	void LoadContent(ALLEGRO_BITMAP *image, std::string text, std::pair<float, float> position);
	void UnloadContent();
	virtual void Update(Animation &a);
	void Draw(ALLEGRO_DISPLAY *display);

	float &Alpha();
	bool &IsActive();

	std::pair<int, int> &AmountOfFrames();
	std::pair<int, int> &CurrentFrame();
	std::pair<int, int> FrameDimensions();
	std::pair<float, float> &Position();


	ALLEGRO_BITMAP*& SourceRect();
	ALLEGRO_BITMAP* Image();


private:
	ALLEGRO_BITMAP *image, *sourceRect;
	std::string text;
	ALLEGRO_FONT *font;
	float alpha;
	bool isActive;

	std::pair<float, float> position;
	std::pair<int, int> amountOfFrames;
	std::pair<int, int> currentFrame;
};

