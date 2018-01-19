#ifndef LEVELS_H
#define LEVELS_h

extern int level[96];
int columns;
int rows;
extern int current_level;
extern int shape_is_left;
extern int direction;
extern int pick_shape;
extern int pick_array;
extern int picking_shape_shape;

extern void set_level(int current_level);
extern void draw_level();
extern void move_player();

#endif
