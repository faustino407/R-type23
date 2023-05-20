#include "player.h"
#include "constants.h"
#include <allegro5/allegro_primitives.h>

player::player() {}

void player::init() {
	x = 50;
	y = GAME_HEIGHT / 2;
	
	
	speed = 8;
	left = right = up = down = firing = false;
	lives = 3;

	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0/5);

	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	bitmap=al_load_bitmap("res/aviao.png");

}
void player::update() {
	if (left) {
		dx = -speed;
	}
	else if (right) {
		dx = speed;
	}
	else {
		dx = 0;
	}
	if (up) {
		dy = -speed;
	}
	else if (down) {
		dy = speed;
	}
	else {
		dy = 0;
	}
	x += dx;
	y += dy;
	if (x <= 0)x=0;
	if (y <= 0)y = 0;
	if (y >= GAME_HEIGHT-20)y = GAME_HEIGHT-20;
	if (x >= GAME_WIDTH-50)x =GAME_WIDTH-50;
	
	if (firing) {
		if (!al_get_timer_started(timer)) {
			al_start_timer(timer);
			fireBullet();
		}
		ALLEGRO_EVENT event;
		if (al_get_next_event(event_queue, &event))
			fireBullet();
	}
	else {
		al_stop_timer(timer);
	}
	
	for (auto& bullet : bullets) {
		bullet->update();
	}
	
	////////////////////////////////////
	for (auto& bullet : bullets) {
		bullet->update();

		if (bullet->remove()) {
			bullet->setActive(false);
		}
	}

	// Remove inactive bullets
	bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet* bullet) {
		return !bullet->isActive();
		}), bullets.end());

	// Remove dead bullets
	for (auto bullet = bullets.begin(); bullet != bullets.end(); ++bullet) {
		if ((*bullet)->remove()) {
			bullets.erase(bullet);
			bullet++;
		}
	}
}



void player::fireBullet()
{
	bullets.emplace_back(new Bullet(0, x, y));
}

	
void player::handleInput() {
		al_get_keyboard_state(&key_state);
		left = al_key_down(&key_state, ALLEGRO_KEY_LEFT); 
		right =al_key_down(&key_state, ALLEGRO_KEY_RIGHT); 
		up = al_key_down(&key_state, ALLEGRO_KEY_UP); 
		down = al_key_down(&key_state, ALLEGRO_KEY_DOWN);
		firing = al_key_down(&key_state, ALLEGRO_KEY_SPACE);

}
void player::render() {
	al_draw_bitmap(bitmap, x, y, 0);

	for (auto& bullet : bullets) {
		bullet->render();
	}

	for (int i = 0; i < lives; i++) {
		al_draw_filled_circle(30 + i * 30, 30, 9, al_map_rgb_f(0, 0, 1)); 
		al_draw_circle(30 + i * 30, 30, 9, al_map_rgb_f(1, 1, 1), 3);
	}

}
void player::dispose() {
	for (auto& bullet : bullets) {
		delete bullet;
	}
	bullets.clear();

	al_destroy_event_queue(event_queue); 
	al_destroy_timer(timer); 
}