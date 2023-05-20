#pragma once
#include <allegro5/allegro5.h>
class Bullet
{
public:
	Bullet(float angle, float x, float y);
	void init();
	void update();
	void render();

	float toRadians(float angle) {
		return angle * 3.1415 / 180; 
	}

	float getX() { return x; } 
	float getY() { return y; }
	float getRadius() { return radius; }

	bool isAlive() { return alive; }
	void kill() { alive = false; }


	bool isActive() {
		return active;
	}

	void setActive(bool value) {
		active = value;
	}
	bool remove() {
		//return x > al_get_display_width(al_get_current_display()) || y > al_get_display_height(al_get_current_display()) || x < 0 || y < 0;
		float displayWidth = al_get_display_width(al_get_current_display());
		float displayHeight = al_get_display_height(al_get_current_display());

		return x > displayWidth || y > displayHeight || x < -radius || y < -radius || !alive;
	}

private:
	float angle;
	float x;
	float y;
	float radius;

	float dx; 
	float dy;
	float speed;
	
	bool active = true;
	bool alive;
};


