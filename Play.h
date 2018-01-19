#include <allegro5/allegro.h>

#ifndef PLAY_H
#define PLAY_H

extern void play(ALLEGRO_EVENT ev);
void play_update(ALLEGRO_EVENT ev);
void play_draw();
extern void play_destroy();

extern int player_x;
extern int player_y;

#endif
