#include "Game.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <algorithm>
#include <functional>

Game::Game() {}
void Game::init() {
	background = new Background("res/Fundo.png");
	player.init();

	for (int i = 0; i < 4; i++) {
		enemies.emplace_back(new Enemy(1));
		enemies.emplace_back(new Enemy(2));
		
	}
}
void Game::update() {
	background->update();
	player.update();

	for (auto& enemy : enemies) {
		enemy->update();
	}

	for (int i = 0; i < player.getBullets().size(); i++) {
		Bullet* bullet = player.getBullets()[i];
		float bx = bullet->getX();
		float by = bullet->getY();
		float br = bullet->getRadius();
		for (int j = 0; j < enemies.size(); j++) {
			Enemy* enemy = enemies[j];
			float ex = enemy->getX();
			float ey = enemy->getY();
			float er = enemy->getRadius();
			if (collide(bx, by, br, ex, ey, er)) {
				// Decrease enemy's life
				enemy->hit();
				// Remove the bullet
				bullet->kill();
			}
		}
	}


	// Remove dead enemies
	for (int i = enemies.size() - 1; i >= 0; i--) {
		Enemy* enemy = enemies[i];
		if (enemy->isDead()) {
			delete enemy;
			enemies.erase(enemies.begin() + i);
		}
	}
}


void Game::handleInput() {
	player.handleInput();
}

void Game::render() {
	background->render();
	player.render();

	for (auto& enemy : enemies) {
		enemy->render();
	}
}

void Game::dispose() {
	background->dispose();
	player.dispose();

	for (auto& enemy : enemies) {
		enemy->dispose();
		delete enemy;
	}
	enemies.clear();
}