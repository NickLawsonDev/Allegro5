#pragma once

#include <allegro5\allegro.h>
#include <vector>
#include "Animation.h"
#include "FadeAnimation.h"
#include "ScreenManager.h"
#include "FileManager.h"
#include <sstream>

class MenuManager
{
private:
	std::vector<std::string> menuItems;
	std::vector<ALLEGRO_BITMAP*> menuImages;
	std::vector<std::string> menuLinks;

	std::vector<Animation*> animation;
	FadeAnimation fAnimation;

	int itemNumber;

	FileManager fileManager;

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	std::vector<std::string> animationTypes;

	std::pair<float, float> position;
	int axis;
	std::string align;
	ALLEGRO_FONT *font;

	void SetMenuItems();
	void SetAnimations();

	std::vector<Animation*> tempAnimation;
public:
	MenuManager();
	~MenuManager();

	void LoadContent(std::string id);
	void UnloadContent();
	void Update(InputManager &input, ALLEGRO_EVENT ev);
	void Draw(ALLEGRO_DISPLAY *display);
};

