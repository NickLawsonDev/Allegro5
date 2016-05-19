#include "Player.h"


Player::Player(void)
{
}


Player::~Player(void)
{
}

void Player::LoadContent()
{
	fileManager.LoadContent("Player\\Player.cme", attributes, contents);

	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < attributes[i].size(); j++)
		{
			if(attributes[i][j] == "Image")
				playerImage = al_load_bitmap(contents[i][j].c_str());
			else if (attributes[i][j] == "Position")
			{
				std::stringstream str;
				float position[2];
				str << contents[i][j];

				std::string value;

				int counter = 0;

				while(std::getline(str, value, ','))
				{
					position[counter] = atof(value.c_str());
					counter++;
				}

				this->position.first = position[0];
				this->position.second = position[1];
			}
		}
	}

	moveSpeed = 2;
	pAnimation.LoadContent(playerImage, "", position);
	pAnimation.IsActive() = true;
	direction = Direction::Down;
}

void Player::UnloadContent()
{
	attributes.clear();
	contents.clear();
	al_destroy_bitmap(playerImage);
	pAnimation.UnloadContent();
}

void Player::Update(ALLEGRO_EVENT ev, InputManager input)
{
	input.Update();
	pAnimation.IsActive() = true;

	if(input.IsKeyDown(ALLEGRO_KEY_DOWN))
	{
		direction = Direction::Down;
		position.second += moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_UP))
	{
		direction = Direction::Up;
		position.second -= moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_LEFT))
	{
		direction = Direction::Left;
		position.first -= moveSpeed;
	}
	else if(input.IsKeyDown(ALLEGRO_KEY_RIGHT))
	{
		direction = Direction::Right;
		position.first += moveSpeed;
	}
	else
		pAnimation.IsActive() = false;

	pAnimation.CurrentFrame().second = direction;
	pAnimation.Position() = position;
	ssAnimation.Update(pAnimation);
}

void Player::Draw(ALLEGRO_DISPLAY *display)
{
	pAnimation.Draw(display);
}
