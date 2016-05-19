#include "FadeAnimation.h"


FadeAnimation::FadeAnimation(void)
{
	fadeSpeed = 6.5f;
	increase = false;
}


FadeAnimation::~FadeAnimation(void)
{
}

void FadeAnimation::Update(Animation &a)
{
	if(a.IsActive())
	{
		if(!increase)
			a.Alpha() -= fadeSpeed;
		else
			a.Alpha() += fadeSpeed;

		if(a.Alpha() <=0)
		{
			a.Alpha() = 0;
			increase = true;
		}
		else if(a.Alpha() >=255)
		{
			a.Alpha() = 255;
			increase = false;
		}
	}
	else
		a.Alpha() = 255;
}

void FadeAnimation::SetIncrease(bool value)
{
	increase = value;
}