#include <allegro5/allegro.h>

#ifndef SYSTEM_H
#define SYSTEM_H

extern void Setup();
extern void Destroy();
extern int FPS_COUNTER(void);

extern ALLEGRO_DISPLAY *display;
extern ALLEGRO_EVENT_QUEUE *event_queue;
extern ALLEGRO_TIMER *timer;

extern int screenWidth;
extern int screenHeight;
extern int fps;
extern int mouse_x;
extern int mouse_y;
double old_time;

//bools
extern int keys[];
extern int render;
extern int done;

//States
extern int game_state;

#endif
