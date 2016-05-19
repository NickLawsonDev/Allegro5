#include "SpriteSheetAnimation.h"
#include <iostream>


SpriteSheetAnimation::SpriteSheetAnimation(void)
{
	frameCounter = 0;
	switchFrame = 10;
}


SpriteSheetAnimation::~SpriteSheetAnimation(void)
{
}

void SpriteSheetAnimation::Update(Animation &a)
{
	if(a.IsActive())
	{
		frameCounter++;
		if(frameCounter >= switchFrame)
		{
			frameCounter = 0;
			a.CurrentFrame().first++;
			if(a.CurrentFrame().first * a.FrameDimensions().first >= al_get_bitmap_width(a.Image()))
				a.CurrentFrame().first = 0;
		}
	}
	else
	{
		frameCounter = 0;
		a.CurrentFrame().first = 1;
	}

	a.SourceRect() = al_create_sub_bitmap(a.Image(), a.CurrentFrame().first * a.FrameDimensions().first, a.CurrentFrame().second * a.FrameDimensions().second, a.FrameDimensions().first, a.FrameDimensions().second);
	std::cout << frameCounter << std::endl;
}