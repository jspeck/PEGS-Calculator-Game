#include <allegro5/allegro.h>
#include "System.h"
#include "Play.h"

void game_loop(){
    while(done == 0){
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        play(ev);
    }
}
