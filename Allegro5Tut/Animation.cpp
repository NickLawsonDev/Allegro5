#include "Animation.h"

Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}

void Animation::LoadContent(ALLEGRO_BITMAP *image, std::string text, std::pair<float, float> position)
{
	this->image = image;
	this->text = text;
	this->position = std::pair<float, float>(0,0);

	alpha = 255;
	font = al_load_font("Fonts\\Orbitron Black.ttf", 30, NULL);
	sourceRect = image;
	isActive = false;
	amountOfFrames = std::pair<int, int>(3,4);
	currentFrame = std::pair<int, int>(1,0);
}

void Animation::UnloadContent()
{
	al_destroy_font(font);
	alpha = NULL;
	position = std::pair<float, float>(0,0);
}

void Animation::Update(Animation &a)
{
}

void Animation::Draw(ALLEGRO_DISPLAY *display)
{
	if(sourceRect != NULL) 
		al_draw_tinted_bitmap(sourceRect, al_map_rgba(255, 255, 255, alpha), position.first, position.second, NULL);

	if(text != "")
		al_draw_text(font, al_map_rgba(255, 255, 255, alpha), position.first, position.second, NULL, text.c_str());
}

float &Animation::Alpha()
{
	return alpha;
}

bool &Animation::IsActive()
{
	return isActive;
}

std::pair<float, float> &Animation::Position()
{
	return position;
}

std::pair<int, int> &Animation::AmountOfFrames()
{
	return amountOfFrames;
}

std::pair<int, int> &Animation::CurrentFrame()
{
	return currentFrame;
}

std::pair<int, int> Animation::FrameDimensions()
{
	std::pair<int, int> fd(al_get_bitmap_width(image) / amountOfFrames.first, al_get_bitmap_height(image) / amountOfFrames.second);

	return fd;
}

ALLEGRO_BITMAP*& Animation::SourceRect()
{
	return sourceRect;
}

ALLEGRO_BITMAP* Animation::Image()
{
	return image;
}

