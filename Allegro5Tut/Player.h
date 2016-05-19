#pragma once

#include <allegro5\allegro.h>
#include "InputManager.h"
#include "FileManager.h"
#include <string>
#include <vector>
#include "SpriteSheetAnimation.h"
#include "Animation.h"

class Player
{
private:
	ALLEGRO_BITMAP *playerImage;
	std::pair<int, int> position;
	float moveSpeed;
	FileManager fileManager;

	std::vector<std::vector<std::string>> attributes;
	std::vector<std::vector<std::string>> contents;

	Animation pAnimation;
	SpriteSheetAnimation ssAnimation;

	enum Direction { Down, Left, Right, Up };

	Direction direction;

public:
	Player(void);
	~Player(void);

	void LoadContent();
	void UnloadContent();
	void Update(ALLEGRO_EVENT ev, InputManager input);
	void Draw(ALLEGRO_DISPLAY *display);
};

