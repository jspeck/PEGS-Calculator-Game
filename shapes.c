#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

int grid_x[] = {7, 60, 113, 166, 219, 272, 325, 378, 431, 485, 537, 590};
int grid_y[] = {5, 65, 125, 185, 245, 305, 365, 425};

void drawRectangle(int x, int y){
    al_draw_rectangle(x, y, x+43, y+50, al_map_rgb(0, 0, 0), 5);
}

void drawHole(int x, int y){
    al_draw_rectangle(x, y, x+43, y+50, al_map_rgb(0, 0, 0), 5);
    al_draw_filled_rectangle(x, y, x+43, y+50, al_map_rgb(0, 0, 0));
}

void drawCircle(int x, int y){
    x -=3;
    int circlex = x + 25;
    int circley = y + 25;
    int radius = 22;
    al_draw_circle(circlex, circley, radius, al_map_rgb(0, 0, 0), 5);
}

void drawTriangle(int x, int y){
    int x1 = x;
    int y1 = y;

    int x2= x1;
    int y2 = y1 + 50;

    int x3 = x1 + 43;
    int y3 = y2;

    al_draw_triangle(x1, y1, x2, y2, x3, y3, al_map_rgb(0, 0, 0), 5);
}

void drawBlock(int x, int y){
    drawRectangle(x, y);
    al_draw_line(x, y, x+43, y+50, al_map_rgb(0, 0, 0), 5);
    al_draw_line(x+43, y, x, y+50, al_map_rgb(0, 0, 0), 5);
    al_draw_filled_rectangle(x+14, y+20, x+29, y+32,al_map_rgb(0, 0, 0));
}

void drawShapeMaker(int x, int y){
    al_draw_line(x+22, y, x+22, y+50, al_map_rgb(0, 0, 0), 10);
    al_draw_line(x, y+25, x+43, y+25, al_map_rgb(0, 0, 0), 10);
}

void drawPlayer(int x, int y){
    int circlex = x + 25;
    int circley = y + 25;
    int radius = 15;
    al_draw_filled_circle(circlex, circley, radius, al_map_rgb(0, 0, 0));
    al_draw_filled_triangle(circlex, circley, circlex - 15, circley - 20, circlex + 15, circley - 20, al_map_rgb(0, 0, 0));
    al_draw_filled_triangle(circlex, circley, circlex - 20, circley - 15, circlex - 20, circley + 15, al_map_rgb(0, 0, 0));
    al_draw_filled_triangle(circlex, circley, circlex - 15, circley + 20, circlex + 15, circley + 20, al_map_rgb(0, 0, 0));
    al_draw_filled_triangle(circlex, circley, circlex + 20, circley - 15, circlex + 20, circley + 15, al_map_rgb(0, 0, 0));
}
