#include "MenuManager.h"


MenuManager::MenuManager(void)
{
}


MenuManager::~MenuManager(void)
{
}

void MenuManager::SetMenuItems()
{
	for(int i = 0; i < menuItems.size(); i++)
	{
		if(menuImages.size() == i)
			menuImages.push_back(NULL);
	}

	for(int i = 0; i < menuImages.size(); i++)
		{
		if(menuItems.size() == i)
			menuItems.push_back("");
	}
}

void MenuManager::SetAnimations()
{
	for(int i = 0; i < menuItems.size(); i++)
	{
		animation.push_back(new Animation);
		animation[animation.size()-1]->LoadContent(menuImages[i], menuItems[i], position);

		if(axis == 2)
			position.second += 30;
		else if (axis == 1)
			position.first += al_get_text_width(font, menuItems[i].c_str());
	}
}

void MenuManager::LoadContent(std::string id)
{
	fileManager.LoadContent("Menus\\Menus.cme", attributes, contents, id);
	float position[2];

	for(int i = 0; i < attributes.size(); i++)
	{
		for(int j = 0; j < attributes[i].size(); j++)
		{
			if(attributes[i][j] == "Item")
				menuItems.push_back(contents[i][j]);
			else if(attributes[i][j] == "ItemLink")
				menuLinks.push_back(contents[i][j]);
			else if(attributes[i][j] == "Image")
				menuImages.push_back(al_load_bitmap(contents[i][j].c_str()));
			else if(attributes[i][j] == "Font")
				font = al_load_font(contents[i][j].c_str(), 30, NULL);
			else if(attributes[i][j] == "Align")
				align = contents[i][j];
			else if(attributes[i][j] == "Animation")
				animationTypes.push_back(contents[i][j]);
			else if(attributes[i][j] == "Axis")
				axis = atoi(contents[i][j].c_str());
			else if(attributes[i][j] == "Position")
			{
				std::stringstream str;
				str << contents[i][j];

				std::string value;

				int counter = 0;

				while(std::getline(str, value, ' '))
				{
					position[counter] = atof(value.c_str());
					counter++;
				}
			}
		}
	}
	this->position.first = position[0];
	this->position.second = position[1];
	SetMenuItems();
	SetAnimations();
}

void MenuManager::UnloadContent()
{
	al_destroy_font(font);
	for(int i = 0; i < menuImages.size(); i++)
		al_destroy_bitmap(menuImages[i]);

	for(int i = 0; i < animation.size(); i++)
	{
		delete animation[i];
	}
	animation.clear();
	menuItems.clear();
	animationTypes.clear();
	attributes.clear();
	contents.clear();

	for(int i = 0; i < menuImages.size(); i++)
		al_destroy_bitmap(menuImages[i]);
	menuImages.clear();
}

void MenuManager::Update(InputManager &input, ALLEGRO_EVENT ev)
{
	if(input.IsKeyPressed(ev, ALLEGRO_KEY_UP))
		itemNumber--;
	else if(input.IsKeyPressed(ev, ALLEGRO_KEY_DOWN))
		itemNumber++;

	if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
	{
		ScreenManager::GetInstance().AddScreen(menuLinks[itemNumber]);
	}

	if(itemNumber < 0)
		itemNumber = 0;
	else if (itemNumber > menuItems.size() - 1)
		itemNumber = menuItems.size() - 1;

	for(int i = 0; i < animation.size(); i++)
	{
		for(int j = 0; j < animationTypes.size(); j++)
		{
			if(itemNumber == i)
				animation[i]->IsActive() = true;
			else
				animation[i]->IsActive() = false;

			if(animationTypes[j] == "Fade")
				fAnimation.Update(*animation[i]);
		}
	}
}

void MenuManager::Draw(ALLEGRO_DISPLAY *display)
{
	for(int i = 0; i < animation.size(); i++)
	{
			animation[i]->Draw(display);
	}
}