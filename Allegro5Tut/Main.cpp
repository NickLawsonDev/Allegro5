#include "ScreenManager.h"
#include "InputManager.h"

#include <iostream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_native_dialog.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_audio.h>
#include <allegro5\allegro_acodec.h>

int main()
{
	const float FPS = 60.0f;

	ALLEGRO_DISPLAY *display;

	if(!al_init())
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not initialize Allegro5", NULL, NULL);
		return -1;
	}

	display = al_create_display(ScreenWidth, ScreenHeight);

	if(!display)
	{
		al_show_native_message_box(NULL, NULL, NULL, "Could not create display", NULL, NULL);
		return -1;	
	}

	al_install_keyboard();
	al_install_mouse();

	al_init_font_addon(); 
	al_init_ttf_addon();
	al_init_image_addon();
	al_init_acodec_addon();

	ALLEGRO_TIMER *timer = al_create_timer(1.0f / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	ALLEGRO_KEYBOARD_STATE keyState;

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));

	bool done = false;

	InputManager input;
	ScreenManager::GetInstance().Initialize();
	ScreenManager::GetInstance().LoadContent();

	al_set_blender(ALLEGRO_ADD, ALLEGRO_ALPHA, ALLEGRO_INVERSE_ALPHA);

	al_start_timer(timer);

	while(!done)
	{
		ALLEGRO_EVENT ev;
		al_wait_for_event(event_queue, &ev);
		al_get_keyboard_state(&keyState);

		if(input.IsKeyPressed(ev, ALLEGRO_KEY_ESCAPE))
			done = true;

		if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
			done = true;

		ScreenManager::GetInstance().Update(ev);
		ScreenManager::GetInstance().Draw(display);

		al_flip_display();
		al_clear_to_color(al_map_rgb(0,0,0));
	}

	ScreenManager::GetInstance().UnloadContent();

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_event_queue(event_queue);

	return 0;
}