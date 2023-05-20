#pragma once
#include <allegro5/allegro.h>


class Enemy
{
public:
	Enemy(int star_);
	void init();
	void update();
	void render();
	void dispose();

	float getX() { return x; }
	float getY() { return y; }
	float getRadius() { return radius; }
	/*void hit() { lives--; }
	bool isDead() { return lives <= 0; }*/

	float toRadians(float angle) {
		return angle * 3.1415 / 180;
	}

	void hit() { lives--; }
	bool isDead() { return lives <= 0; }

private:
	int star;
	float x;
	float y;
	float radius;

	float speed;
	float dx;
	float dy;
	float angle;

	int lives;

	//imagem
	//ALLEGRO_BITMAP* bitmap;
	
	
	ALLEGRO_COLOR color;
	bool isOnScreen;
};

