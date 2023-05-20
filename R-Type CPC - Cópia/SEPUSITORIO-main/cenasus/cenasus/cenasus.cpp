// cenasus.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//

#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include "constants.h"
#include "Game.h"
#include "Bullet.h"

void update();
void render();
void handleInput(); 
void dispose(); 

ALLEGRO_DISPLAY* display = nullptr;
ALLEGRO_EVENT_QUEUE* event_queue = nullptr;
ALLEGRO_TIMER* timer = nullptr;

Game game;

int main()
{
        
        srand(time(0));

        if (!al_init()) return -1; // Print error message
        
        display = al_create_display(GAME_WIDTH, GAME_HEIGHT);
        event_queue = al_create_event_queue();
        timer = al_create_timer(1.0 / FPS);
        al_install_keyboard();
        al_init_image_addon();
        al_init_primitives_addon();

        al_register_event_source(event_queue, al_get_display_event_source(display));
        al_register_event_source(event_queue, al_get_timer_event_source(timer));
        al_register_event_source(event_queue, al_get_keyboard_event_source());

        bool running = true;
        bool redraw = true;

        game.init();

            // Game Loop
            al_start_timer(timer);
            while (running) {
                ALLEGRO_EVENT event;
                al_wait_for_event(event_queue, &event);
                switch (event.type) {
                 case ALLEGRO_EVENT_DISPLAY_CLOSE: 
                     running = false;
                     break;
                case ALLEGRO_EVENT_TIMER:
                    handleInput();
                    update();
                    redraw = true; 
                    break;
                }
                if (redraw && al_is_event_queue_empty(event_queue)) {
                redraw = false;
                render();
                }
            }
            dispose();

            return 0;
}

void update() {
    game.update();
}
void render() {
        // Clear screen
        al_clear_to_color(al_map_rgb_f(0, 0, 0)); 

        // Draw other game objects here
        game.render();

        // Flip the page 
        al_flip_display();
}
void handleInput() {
    game.handleInput();
}
void dispose() {

    game.dispose();

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);
}

