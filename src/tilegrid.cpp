#include "header/game.h"

void game::make_tile(int xtile, int yrow, sf::Color col, int behaviur, int id, int entry){
    tilecol.setSize(sf::Vector2f(gridsize, gridsize));
//    tilecol.setScale(sf::Vector2f(gridscale, gridscale));
    tilecol.setFillColor(col);
    tilecol.setPosition(sf::Vector2f(xtile*gridsize-boxposx, yrow*gridsize-boxposy));
    collision(xtile*gridsize-boxposx, yrow*gridsize-boxposy, gridsize, gridsize, behaviur, id, entry);
    win.draw(tilecol);
}

void game::make_tile(int xtile, int yrow, sf::Texture &texture, int behaviur, int id, int entry){
    tilespr.setSize(sf::Vector2f(gridsize, gridsize));
    tilespr.setTexture(&texture);
    tilespr.setPosition(sf::Vector2f(xtile*gridsize-boxposx, yrow*gridsize-boxposy));
    collision(xtile*gridsize-boxposx, yrow*gridsize-boxposy, gridsize, gridsize, behaviur, id, entry);
    win.draw(tilespr);
}

void game::make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Texture material, int behaviour, int id, int entry){
    for(int i=Xbegin; i<=repeatNumX; i++) for(int j=Ybegin; j<=repeatNumY; j++ ) make_tile(i, j, material, behaviour, id, entry);
}
void game::make_tile_extend(int Xbegin, int Ybegin, int repeatNumX, int repeatNumY, sf::Color material, int behaviour, int id, int entry){
    for(int i=Xbegin; i<=repeatNumX; i++) for(int j=Ybegin; j<=repeatNumY; j++ ) make_tile(i, j, material, behaviour, id, entry);
}

void game::load_textures(){
    tex_grass.loadFromFile("assets/sprite/grass.png");
    tex_playerload.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(2, 60, 18, 30));
    tex_bound.loadFromFile("assets/sprite/32bound.png");
    tex_test.loadFromFile("assets/sprite/test.png");
    tex_playerconfuse.loadFromFile("assets/sprite/playertest.png");
}
