#include "header/game.h"

void game::room_setentry(int x, int y, int id){
    room_entries[id]=sf::Vector2i(x,y);
}

sf::Vector2i game::room_loadentry(int id){
    room_entrynum=id;
    return room_entries[id];
}
