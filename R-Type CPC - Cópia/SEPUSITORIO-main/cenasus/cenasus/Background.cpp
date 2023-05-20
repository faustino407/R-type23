#include "Background.h"
#include "constants.h"
Background::Background(std::string filename) {
	backgroundImage = al_load_bitmap(filename.c_str());
	if (!backgroundImage) {
		std::cout << "Could not load the background image. Please check your image path correctly : " << filename << std::endl;
	}
}
void Background::update() {
	x -= 2;
	if (x < -GAME_WIDTH) x = 0;
}
void Background:: render(){
	al_draw_scaled_bitmap(backgroundImage, 0, 0, al_get_bitmap_width(backgroundImage),
		al_get_bitmap_height(backgroundImage), x, y, GAME_WIDTH, GAME_HEIGHT, 0);
	al_draw_scaled_bitmap(backgroundImage, 0, 0, al_get_bitmap_width(backgroundImage),
		al_get_bitmap_height(backgroundImage), GAME_WIDTH + x, y, GAME_WIDTH, GAME_HEIGHT, 0);

}
void Background::dispose() {

al_destroy_bitmap(backgroundImage);
}