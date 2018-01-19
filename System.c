#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "levels.h"

ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT_QUEUE *event_queue;
ALLEGRO_TIMER *timer;

int screenWidth = 640;
int screenHeight = 480;
int fps = 0;
int mouse_x = 0;
int mouse_y = 0;
double old_time;

//bools
int keys[] = {0, 0, 0, 0, 0, 0, 0};
//UP, DOWN, LEFT, RIGHT, SPACE, Mouse1, Mouse2
int render = 0;
int done = 0;

//States
int game_state = 1;

void Setup(){
    const int maxFPS = 60;
    display = NULL;
    event_queue = NULL;
    timer = NULL;

    al_init();
    display = al_create_display(screenWidth, screenHeight);

    al_set_window_title(display, "PEGS Calculator Game");

    timer = al_create_timer(1.0 / maxFPS);

    event_queue = al_create_event_queue();

    al_install_keyboard();
    al_install_mouse();
    al_init_primitives_addon();
    //al_init_image_addon();
    al_init_font_addon();
    al_init_ttf_addon();

    al_register_event_source(event_queue, al_get_display_event_source(display));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_mouse_event_source());

    set_level(current_level);

    al_start_timer(timer);
}

void Destroy(){
    al_destroy_event_queue(event_queue);
    al_destroy_timer(timer);
    al_destroy_display(display);
}

int FPS_COUNTER(void){
    double new_time = al_get_time();
    double delta = new_time - old_time;
    double fps = 1/(delta);
    old_time = new_time;
    return fps;
}
