#pragma once

#include "Animation.h"

class SpriteSheetAnimation : public Animation
{
private:
	int frameCounter, switchFrame;

public:
	SpriteSheetAnimation(void);
	~SpriteSheetAnimation(void);

	void Update(Animation &a);
};

