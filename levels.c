#include <allegro5/allegro.h>
#include "System.h"
#include "shapes.h"
#include "Play.h"
#include "input.h"

//NOTHING = 0       //columns = x
//PLAYER = 1        //rows = y
//BLOCK = 2
//SQUARE = 3
//CIRCLE = 4
//TRIANGLE = 5
//HOLE = 6
//SHAPEMAKER = 7

int level[96];
/*
int level[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
               2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
               2, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 2,
               2, 0, 0, 0, 0, 7, 7, 5, 0, 0, 0, 2,
               2, 0, 0, 0, 3, 6, 0, 4, 0, 0, 0, 2,
               2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
               2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
               2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
*/

int columns = 12;
int rows = 8;
int current_level = 1;
int shape_is_left = 1;
int direction;
int pick_shape = 0;
int pick_array = 0;
int picking_shape_shape = 3;

void set_level(int level_chosen){
    if(level_chosen == 1){
      int level1[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                        2, 0, 0, 0, 1, 0, 0, 4, 0, 0, 0, 2,
                        2, 0, 0, 0, 0, 7, 7, 5, 0, 0, 0, 2,
                        2, 0, 0, 0, 3, 6, 0, 4, 0, 0, 0, 2,
                        2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                        2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};

                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level1[i];
                        }
    }
    else if(level_chosen == 2){
      int level2[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        2, 2, 2, 0, 0, 0, 5, 5, 0, 0, 0, 2,
                        2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2,
                        2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2,
                        1, 0, 0, 0, 5, 5, 4, 4, 0, 0, 0, 2,
                        2, 2, 2, 0, 0, 0, 2, 2, 0, 0, 0, 2,
                        2, 2, 2, 0, 0, 0, 2, 0, 0, 0, 0, 2,
                        2, 2, 2, 0, 0, 0, 5, 5, 0, 0, 0, 2};

                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level2[i];
                        }
    }
    else if(level_chosen == 3){
      int level3[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        2, 0, 0, 0, 0, 0, 5, 0, 1, 0, 0, 0,
                        2, 0, 2, 2, 0, 2, 2, 0, 2, 2, 5, 2,
                        2, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 5, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level3[i];
                        }
    }
    else if(level_chosen == 4){
      int level4[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        6, 0, 3, 0, 5, 0, 5, 0, 0, 0, 0, 2,
                        6, 0, 7, 0, 4, 0, 5, 0, 0, 0, 0, 2,
                        6, 0, 4, 0, 3, 1, 5, 0, 0, 0, 0, 2,
                        6, 0, 5, 0, 3, 0, 5, 0, 7, 0, 0, 2,
                        6, 0, 3, 0, 4, 0, 5, 0, 0, 0, 0, 2,
                        6, 0, 4, 0, 3, 0, 5, 0, 0, 0, 0, 2,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level4[i];
                        }
    }
    else if(level_chosen == 5){
      int level5[96] = {0, 6, 6, 0, 3, 6, 0, 0, 6, 0, 0, 0,
                        0, 6, 6, 0, 3, 3, 0, 0, 6, 0, 0, 5,
                        5, 6, 6, 0, 6, 6, 6, 0, 2, 5, 5, 5,
                        0, 6, 6, 0, 6, 3, 6, 0, 2, 5, 0, 5,
                        0, 6, 6, 0, 6, 1, 6, 4, 6, 0, 0, 0,
                        5, 6, 6, 0, 6, 6, 6, 0, 6, 0, 0, 0,
                        0, 6, 6, 0, 3, 0, 0, 0, 6, 0, 0, 0,
                        0, 6, 6, 0, 0, 4, 0, 0, 6, 4, 4, 0};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level5[i];
                        }
    }
    else if(level_chosen == 6){
      int level6[96] = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0,
                        5, 0, 0, 5, 0, 0, 0, 5, 5, 0, 0, 0,
                        0, 2, 2, 5, 2, 2, 2, 2, 2, 2, 2, 0,
                        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                        0, 2, 2, 2, 2, 0, 2, 2, 0, 2, 2, 2,
                        0, 7, 0, 0, 0, 0, 0, 0, 4, 3, 6, 0,
                        0, 0, 0, 2, 2, 2, 2, 0, 0, 2, 2, 2};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level6[i];
                        }
    }
    else if(level_chosen == 7){
      int level7[96] = {2, 2, 2, 2, 0, 0, 2, 2, 2, 2, 2, 2,
                        2, 2, 2, 6, 0, 0, 3, 6, 0, 2, 2, 2,
                        2, 2, 2, 2, 0, 2, 4, 2, 0, 2, 2, 2,
                        2, 2, 2, 5, 7, 7, 1, 3, 5, 6, 2, 2,
                        2, 2, 2, 2, 0, 2, 5, 2, 0, 0, 0, 2,
                        2, 2, 2, 2, 0, 0, 4, 0, 0, 2, 0, 2,
                        2, 2, 2, 2, 2, 2, 2, 0, 2, 2, 0, 2,
                        2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 2};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level7[i];
                        }
    }
    else if(level_chosen == 8){
      int level8[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                        0, 0, 7, 7, 7, 7, 7, 3, 7, 7, 0, 0,
                        0, 0, 7, 7, 7, 5, 7, 7, 4, 7, 0, 0,
                        1, 0, 7, 7, 7, 5, 7, 7, 3, 7, 0, 0,
                        0, 0, 7, 7, 3, 4, 7, 7, 7, 7, 0, 0,
                        0, 0, 7, 7, 4, 5, 7, 7, 7, 7, 0, 0,
                        0, 0, 7, 7, 5, 3, 7, 7, 7, 7, 0, 0,
                        2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level8[i];
                        }
    }
    else if(level_chosen == 9){
      int level9[96] = {0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0,
                        0, 7, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0,
                        0, 0, 0, 0, 5, 3, 3, 7, 0, 2, 2, 0,
                        0, 2, 0, 0, 5, 2, 0, 0, 0, 2, 2, 2,
                        0, 0, 0, 5, 5, 1, 2, 0, 0, 0, 0, 5,
                        0, 0, 0, 0, 5, 2, 0, 0, 2, 2, 2, 2,
                        0, 7, 2, 0, 5, 4, 4, 0, 0, 0, 7, 0,
                        0, 0, 0, 0, 3, 2, 0, 0, 0, 0, 0, 0};
                        int i;
                        for(i = 0; i < 96; i++){
                            level[i] = level9[i];
                        }
    }
    else if(level_chosen == 10){
      int level10[96] = {2, 2, 2, 2, 5, 2, 2, 2, 0, 0, 0, 0,
                         2, 2, 2, 2, 0, 2, 2, 2, 0, 0, 0, 1,
                         0, 0, 3, 0, 6, 6, 6, 0, 0, 0, 7, 0,
                         0, 7, 7, 0, 6, 6, 6, 0, 3, 7, 3, 0,
                         0, 7, 7, 0, 6, 6, 6, 0, 3, 7, 3, 0,
                         0, 0, 0, 0, 6, 6, 6, 0, 7, 0, 0, 0,
                         2, 2, 2, 2, 2, 0, 2, 2, 0, 0, 0, 0,
                         2, 2, 2, 2, 2, 5, 2, 2, 0, 0, 0, 0};
                         int i;
                         for(i = 0; i < 96; i++){
                            level[i] = level10[i];
                         }
    }
    else if(level_chosen == 11){
        int level11[96] = {2, 1, 2, 0, 2, 2, 6, 0, 0, 2, 2, 0,
                           2, 0, 0, 0, 4, 3, 6, 6, 0, 5, 5, 0,
                           2, 5, 2, 5, 0, 2, 6, 0, 0, 5, 5, 0,
                           2, 0, 0, 5, 0, 2, 0, 0, 0, 7, 7, 0,
                           2, 5, 2, 0, 0, 2, 0, 2, 0, 7, 7, 0,
                           0, 0, 0, 0, 0, 2, 0, 2, 2, 0, 2, 0,
                           0, 7, 3, 7, 0, 2, 0, 2, 0, 0, 0, 0,
                           0, 0, 0, 0, 5, 5, 5, 2, 2, 2, 2, 2};
                           int i;
                           for(i = 0; i < 96; i++){
                            level[i] = level11[i];
                           }
    }
    else if(level_chosen == 12){
        int level12[96] = {1, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2,
                           2, 5, 2, 5, 2, 5, 2, 2, 0, 0, 0, 2,
                           0, 0, 0, 0, 0, 0, 2, 0, 0, 2, 0, 2,
                           2, 5, 2, 5, 2, 5, 2, 0, 0, 0, 0, 2,
                           0, 0, 0, 0, 0, 0, 2, 2, 4, 4, 6, 2,
                           2, 5, 2, 5, 2, 5, 2, 2, 0, 5, 5, 2,
                           0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 2,
                           2, 0, 2, 2, 2, 2, 2, 2, 0, 0, 2, 2};
                           int i;
                           for(i = 0; i < 96; i++){
                            level[i] = level12[i];
                           }
    }
    else if(level_chosen == 13){
        int level13[96] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2,
                           0, 0, 3, 0, 5, 0, 4, 0, 3, 0, 0, 6,
                           0, 0, 5, 0, 4, 0, 5, 0, 3, 0, 0, 6,
                           1, 0, 7, 0, 3, 0, 4, 0, 3, 0, 0, 6,
                           0, 0, 4, 0, 3, 0, 5, 0, 3, 0, 0, 6,
                           0, 0, 3, 0, 5, 0, 4, 0, 3, 0, 0, 6,
                           0, 0, 7, 0, 7, 0, 5, 0, 3, 0, 0, 6,
                           2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
                           int i;
                           for(i = 0; i < 96; i++){
                            level[i] = level13[i];
                           }
    }
    else if(level_chosen == 14){
        int level14[96] = {2, 2, 2, 2, 2, 0, 0, 2, 0, 0, 2, 2,
                           2, 2, 0, 5, 0, 0, 3, 0, 0, 5, 0, 2,
                           2, 6, 0, 0, 4, 2, 0, 2, 2, 0, 0, 2,
                           2, 2, 2, 0, 0, 7, 4, 7, 0, 0, 2, 2,
                           2, 2, 0, 0, 2, 2, 0, 2, 4, 0, 0, 6,
                           2, 2, 0, 5, 0, 0, 3, 0, 0, 0, 1, 2,
                           2, 2, 0, 0, 2, 0, 0, 2, 2, 2, 2, 2,
                           2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2};
                           int i;
                           for(i = 0; i < 96; i++){
                            level[i] = level14[i];
                           }
    }
    else if(level_chosen == 15){
        int level15[96] = {0, 0, 0, 6, 0, 6, 0, 6, 0, 6, 0, 2,
                           0, 0, 0, 6, 0, 6, 0, 6, 0, 6, 0, 2,
                           0, 7, 3, 6, 0, 6, 0, 6, 0, 6, 0, 5,
                           0, 3, 0, 6, 0, 6, 3, 6, 0, 6, 0, 2,
                           0, 7, 0, 6, 0, 6, 0, 6, 0, 6, 0, 2,
                           1, 0, 0, 6, 3, 6, 0, 6, 0, 6, 0, 2,
                           0, 0, 3, 6, 0, 6, 0, 6, 3, 6, 0, 2,
                           0, 0, 3, 6, 0, 6, 0, 6, 0, 6, 0, 2};
                           int i;
                           for(i = 0; i < 96; i++){
                            level[i] = level15[i];
                           }
    }
}

void draw_level(){
    int i;
    for(i = 0; i < 96; i++){
        int y;
            if(i >= 0 && i < 12)       y = 0;
            else if(i >= 12 && i < 24) y = 1;
            else if(i >= 24 && i < 36) y = 2;
            else if(i >= 36 && i < 48) y = 3;
            else if(i >= 48 && i < 60) y = 4;
            else if(i >= 60 && i < 72) y = 5;
            else if(i >= 72 && i < 84) y = 6;
            else if(i >= 84 && i < 96) y = 7;

        if(level[i] == 1)   drawPlayer(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 2)   drawBlock(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 3)   drawRectangle(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 4)   drawCircle(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 5)   drawTriangle(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 6)   drawHole(grid_x[(i % columns)], grid_y[y]);
        if(level[i] == 7)   drawShapeMaker(grid_x[(i % columns)], grid_y[y]);
    }
}

void move_player(int direction){
    //1 = UP   2 = DOWN  3 = LEFT  4 = RIGHT
    int i;
    for(i = 0; i< 96; i++){
        if(direction == 1){
            if(level[i] == 1){
                if(i-12 >= 0){
                    if(level[i-12] == 0){
                        level[i-12] = 1;
                        level[i] = 0;
                        break;
                    }
                    else if(level[i-12] == 3 && i-24 >= 0){
                        if(level[i-24] == 0){
                            level[i-24] = 3;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 3){
                            level[i-24] = 0;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 6){
                            level[i-24] = 0;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 4 || level[i-24] == 5 || level[i-24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i-12] == 4 && i-24 >= 0){
                        if(level[i-24] == 0){
                            level[i-24] = 4;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 4){
                            level[i-24] = 0;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 6){
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 3 || level[i-24] == 5 || level[i-24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i-12] == 5 && i-24 >= 0){
                        if(level[i-24] == 0){
                            level[i-24] = 5;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 5){
                            level[i-24] = 2;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 6){
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 3 || level[i-24] == 4 || level[i-24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i-12] == 6){
                        level[i] = 0;
                        set_level(current_level);
                        break;
                    }
                    else if(level[i-12] == 7 && i-24 >= 0){
                        if(level[i-24] == 0){
                            level[i-24] = 7;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 7){
                            pick_array = i - 24;
                            pick_shape = 1;
                            level[pick_array] = picking_shape_shape;
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 6){
                            level[i-12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i-24] == 3 || level[i-24] == 4 || level[i-24] == 5){
                            set_level(current_level);
                        }
                    }
                }
            }
        }
    else if(direction == 2){
            if(level[i] == 1){
                if(i+12 < 96){
                    if(level[i+12] == 0){
                        level[i+12] = 1;
                        level[i] = 0;
                        break;
                    }
                    else if(level[i+12] == 3 && i+24 < 96){
                        if(level[i+24] == 0){
                            level[i+24] = 3;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 3){
                            level[i+24] = 0;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 6){
                            level[i+24] = 0;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 4 || level[i+24] == 5 || level[i+24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i+12] == 4 && i+24 < 96){
                        if(level[i+24] == 0){
                            level[i+24] = 4;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 4){
                            level[i+24] = 0;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 6){
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 3 || level[i+24] == 5 || level[i+24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i+12] == 5 && i+24 < 96){
                        if(level[i+24] == 0){
                            level[i+24] = 5;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 5){
                            level[i+24] = 2;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 6){
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 3 || level[i+24] == 4 || level[i+24] == 7){
                            set_level(current_level);
                        }
                    }
                    else if(level[i+12] == 6){
                        level[i] = 0;
                        set_level(current_level);
                        break;
                    }
                    else if(level[i+12] == 7 && i+24 < 96){
                        if(level[i+24] == 0){
                            level[i+24] = 7;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 7){
                            pick_array = i + 24;
                            pick_shape = 1;
                            level[pick_array] = picking_shape_shape;
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 6){
                            level[i+12] = 1;
                            level[i] = 0;
                            break;
                        }
                        else if(level[i+24] == 3 || level[i+24] == 4 || level[i+24] == 5){
                            set_level(current_level);
                        }
                    }
                }
            }
        }
        else if(direction == 3){
            if(level[i] == 1){
                if(can_go_left(i) == 1){
                    if(level[i-1] == 0){
                        level[i-1] = 1;
                        level[i] = 0;
                        break;
                    }
                    else if(level[i-1] == 3){
                        if(can_go_left(i-1) == 1){
                            if(level[i-2] == 0){
                                level[i-2] = 3;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 3){
                                level[i-2] = 0;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 6){
                                level[i-2] = 0;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 4 || level[i-2] == 5 || level[i-2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i-1] == 4){
                        if(can_go_left(i-1) == 1){
                            if(level[i-2] == 0){
                                level[i-2] = 4;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 4){
                                level[i-2] = 0;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 6){
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 3 || level[i-2] == 5 || level[i-2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i-1] == 5){
                        if(can_go_left(i-1) == 1){
                            if(level[i-2] == 0){
                                level[i-2] = 5;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 5){
                                level[i-2] = 2;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 6){
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 3 || level[i-2] == 4 || level[i-2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i-1] == 6){
                        if(can_go_left(i) == 1){
                            level[i] = 0;
                            set_level(current_level);
                            break;
                        }
                    }
                    else if(level[i-1] == 7){
                        if(can_go_left(i-1) == 1){
                            if(level[i-2] == 0){
                                level[i-2] = 7;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 7){
                                pick_array = i - 2;
                                pick_shape = 1;
                                level[pick_array] = picking_shape_shape;
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 6){
                                level[i-1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i-2] == 3 || level[i-2] == 4 || level[i-2] == 5){
                                set_level(current_level);
                            }
                        }
                    }
                }
            }
        }
        else if(direction == 4){
            if(level[i] == 1){
                if(can_go_right(i) == 1){
                    if(level[i+1] == 0){
                        level[i+1] = 1;
                        level[i] = 0;
                        break;
                    }
                    else if(level[i+1] == 3){
                        if(can_go_right(i+1) == 1){
                            if(level[i+2] == 0){
                                level[i+2] = 3;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 3){
                                level[i+2] = 0;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 6){
                                level[i+2] = 0;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 4 || level[i+2] == 5 || level[i+2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i+1] == 4){
                        if(can_go_right(i+1) == 1){
                            if(level[i+2] == 0){
                                level[i+2] = 4;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 4){
                                level[i+2] = 0;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 6){
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 3 || level[i+2] == 5 || level[i+2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i+1] == 5){
                        if(can_go_right(i+1) == 1){
                            if(level[i+2] == 0){
                                level[i+2] = 5;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 5){
                                level[i+2] = 2;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 6){
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 3 || level[i+2] == 4 || level[i+2] == 7){
                                set_level(current_level);
                            }
                        }
                    }
                    else if(level[i+1] == 6){
                        if(can_go_right(i) == 1){
                            level[i] = 0;
                            set_level(current_level);
                            break;
                        }
                    }
                    else if(level[i+1] == 7){
                        if(can_go_right(i+1) == 1){
                            if(level[i+2] == 0){
                                level[i+2] = 7;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 7){
                                pick_array = i + 2;
                                pick_shape = 1;
                                level[pick_array] = picking_shape_shape;
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 6){
                                level[i+1] = 1;
                                level[i] = 0;
                                break;
                            }
                            else if(level[i+2] == 3 || level[i+2] == 4 || level[i+2] == 5){
                                set_level(current_level);
                            }
                        }
                    }
                }
            }
        }
    }
}

void check_for_shape(){
    int i;
    for(i = 0; i < 96; i++){
        if(level[i] == 3 || level[i] == 4 || level[i] == 5 || level[i] == 7){
            shape_is_left = 1;
            break;
        }
        else
            shape_is_left = 0;
    }
    if(shape_is_left == 0){
        if(current_level == 15){
            current_level = 1;
            set_level(current_level);
        }
        else{
            current_level++;
            set_level(current_level);
        }
    }
}

int can_go_left(int i){
    int y;
    if(i >= 0 && i < 12)       y = 0;
    else if(i >= 12 && i < 24) y = 1;
    else if(i >= 24 && i < 36) y = 2;
    else if(i >= 36 && i < 48) y = 3;
    else if(i >= 48 && i < 60) y = 4;
    else if(i >= 60 && i < 72) y = 5;
    else if(i >= 72 && i < 84) y = 6;
    else if(i >= 84 && i < 96) y = 7;

    int left_of_i = i - 1;
    int left_of_i_y;

    if(left_of_i >= 0 && left_of_i < 12)       left_of_i_y = 0;
    else if(left_of_i >= 12 && left_of_i < 24) left_of_i_y = 1;
    else if(left_of_i >= 24 && left_of_i < 36) left_of_i_y = 2;
    else if(left_of_i >= 36 && left_of_i < 48) left_of_i_y = 3;
    else if(left_of_i >= 48 && left_of_i < 60) left_of_i_y = 4;
    else if(left_of_i >= 60 && left_of_i < 72) left_of_i_y = 5;
    else if(left_of_i >= 72 && left_of_i < 84) left_of_i_y = 6;
    else if(left_of_i >= 84 && left_of_i < 96) left_of_i_y = 7;

    int can_go_left;
    if(y == left_of_i_y)
        can_go_left = 1;
    else
        can_go_left = 0;

    return can_go_left;
}

int can_go_right(int i){
    int y;
    if(i >= 0 && i < 12)       y = 0;
    else if(i >= 12 && i < 24) y = 1;
    else if(i >= 24 && i < 36) y = 2;
    else if(i >= 36 && i < 48) y = 3;
    else if(i >= 48 && i < 60) y = 4;
    else if(i >= 60 && i < 72) y = 5;
    else if(i >= 72 && i < 84) y = 6;
    else if(i >= 84 && i < 96) y = 7;

    int right_of_i = i + 1;
    int right_of_i_y;

    if(right_of_i >= 0 && right_of_i < 12)       right_of_i_y = 0;
    else if(right_of_i >= 12 && right_of_i < 24) right_of_i_y = 1;
    else if(right_of_i >= 24 && right_of_i < 36) right_of_i_y = 2;
    else if(right_of_i >= 36 && right_of_i < 48) right_of_i_y = 3;
    else if(right_of_i >= 48 && right_of_i < 60) right_of_i_y = 4;
    else if(right_of_i >= 60 && right_of_i < 72) right_of_i_y = 5;
    else if(right_of_i >= 72 && right_of_i < 84) right_of_i_y = 6;
    else if(right_of_i >= 84 && right_of_i < 96) right_of_i_y = 7;

    int can_go_right;
    if(y == right_of_i_y)
        can_go_right = 1;
    else
        can_go_right = 0;

    return can_go_right;
}

