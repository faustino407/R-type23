#pragma once
#include <allegro5/allegro.h>
#include <iostream>
class Background
{
public:
	Background(std::string filename);
	void update();
	void render();
	void dispose();	

private:
	int x; int y;
	ALLEGRO_BITMAP* backgroundImage;
};

