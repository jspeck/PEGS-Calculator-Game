#include <allegro5/allegro.h>
#include "System.h"
#include "Play.h"
#include "levels.h"

void player_input(ALLEGRO_EVENT ev){
    if(ev.type == ALLEGRO_EVENT_KEY_DOWN){
        switch(ev.keyboard.keycode){
            case ALLEGRO_KEY_ESCAPE:
                done = 1;
                break;
            case ALLEGRO_KEY_UP:
                if(pick_shape == 1){
                    picking_shape_shape--;
                    if(picking_shape_shape == 2) picking_shape_shape = 7;
                    else if(picking_shape_shape == 3);
                    else if(picking_shape_shape == 4);
                    else if(picking_shape_shape == 5);
                    else if(picking_shape_shape == 6) picking_shape_shape = 5;
                    else if(picking_shape_shape == 7);

                    level[pick_array] = picking_shape_shape;
                }
                else if(pick_shape == 0) move_player(1);
                break;
            case ALLEGRO_KEY_DOWN:
                if(pick_shape == 1){
                    picking_shape_shape++;
                    if(picking_shape_shape == 3);
                    else if(picking_shape_shape == 4);
                    else if(picking_shape_shape == 5);
                    else if(picking_shape_shape == 6) picking_shape_shape = 7;
                    else if(picking_shape_shape == 7);
                    else if(picking_shape_shape == 8) picking_shape_shape = 3;

                    level[pick_array] = picking_shape_shape;
                }
                else if(pick_shape == 0) move_player(2);
                break;
            case ALLEGRO_KEY_LEFT:
                if(pick_shape == 0) move_player(3);
                break;
            case ALLEGRO_KEY_RIGHT:
                if(pick_shape == 0) move_player(4);
                break;
            case ALLEGRO_KEY_ENTER:
                if(pick_shape == 1){
                    pick_shape = 0;
                    picking_shape_shape = 3;
                }
                break;
            case ALLEGRO_KEY_R:
                set_level(current_level);
                break;
            case ALLEGRO_KEY_O:
                if(current_level > 1){
                    current_level--;
                    set_level(current_level);
                }
                break;
            case ALLEGRO_KEY_P:
                if(current_level < 15){
                    current_level++;
                    set_level(current_level);
                }
                break;
        }
    }
    else if(ev.type == ALLEGRO_EVENT_KEY_UP){

    }
}
