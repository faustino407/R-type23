#include "Bullet.h"
#include <cmath>
#include <allegro5/allegro_primitives.h>


Bullet::Bullet(float angle_, float x_, float y_) : angle(angle_), x(x_), y(y_) {
	init();
}

void Bullet::init() {
	radius = 4;
	speed = 20;
	dx = cos(angle) * speed;
	dy = sin(angle) * speed;
	alive = true;
}

void Bullet::update() {
	x += dx;
	y += dy;
}

void Bullet::render() {
	al_draw_filled_circle(x, y, radius, al_map_rgb_f(1, 1, 1));
	al_draw_circle(x, y, radius, al_map_rgb_f(1, 0, 0), 4);
}

