#include <allegro5/allegro.h>
#include "System.h"
#include "game_loop.h"

int main(){
    Setup();
    game_loop();
    Destroy();
    return 0;
}
