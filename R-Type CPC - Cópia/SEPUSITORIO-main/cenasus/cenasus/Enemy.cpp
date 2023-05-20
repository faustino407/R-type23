#include "Enemy.h"
#include "constants.h"
#include <cmath>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

Enemy::Enemy(int star_) : star(star_) {
	init();
}

void Enemy::init() {

	switch (star){

	case 1:
		speed = 3;
		lives = 1;
		color = al_map_rgb_f(2, 0, 27);
		break;

	case 2:
		speed = 4;
		lives = 2;
		color = al_map_rgb_f(2, 59, 48);
		break;

	case 3:
		speed = 4;
		lives = 3;
		color = al_map_rgb_f(2, 4, 0);
		break;

	case 4:
		speed = 5;
		lives = 4;
		color = al_map_rgb_f(2, 3, 5);
		break;

	case 5:
		speed = 6;
		lives = 5;
		color = al_map_rgb_f(2, 7, 54);
		break;
	}
	radius = 10;
	x = GAME_WIDTH - radius;
	y = GAME_HEIGHT / 2;
	angle = (90 + rand() % 181);
	dx = -(abs(cos(toRadians(angle)) * speed));
	dy = sin(toRadians(angle)) * speed;
	isOnScreen = false;

	//bitmap = al_load_bitmap("res/asteroide.png");

}

void Enemy::update() {
	x += dx;
	y += dy;

	if (x < GAME_WIDTH) isOnScreen = true;

	//Bounds Checking

	if (isOnScreen) {
		if (x < radius) dx = -dx;
		if (y < radius) dy = -dy;
		if (x + radius > GAME_WIDTH) dx = -dx;
		if (y + radius > GAME_HEIGHT) dy = -dy;
	}
}

void Enemy::render() {
	//al_draw_bitmap(bitmap, x, y, 0);
	al_draw_filled_circle(x, y, radius, color);

}

void Enemy::dispose(){}