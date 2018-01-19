#include <allegro5/allegro.h>
#include "System.h"
#include "shapes.h"
#include "input.h"

int player_x, player_y;

void play_update(ALLEGRO_EVENT ev){
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN || ev.type == ALLEGRO_EVENT_KEY_UP){
        player_input(ev);
    }
    else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
        done = 1;
    }
    else if(ev.type == ALLEGRO_EVENT_TIMER){
        check_for_shape();
        render = 1;
    }
}

void play_draw(){
    if(render == 1 && al_is_event_queue_empty(event_queue)){
        render = 0;
        al_clear_to_color(al_map_rgb(255, 255, 255));
        draw_level();
        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));
    }
}

void play(ALLEGRO_EVENT ev){
    play_update(ev);
    play_draw();
}

void play_destroy(){

}
