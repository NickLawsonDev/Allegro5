#pragma once

#include "Animation.h"


class FadeAnimation : public Animation
{
private:
	float fadeSpeed;
	bool increase;

public:
	FadeAnimation(void);
	~FadeAnimation(void);

	void Update(Animation &a);
	void SetIncrease(bool value);
};

