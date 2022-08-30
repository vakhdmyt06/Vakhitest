#include "header/game.h"

void game::make_tile(int xtile, int yrow, sf::Color col, int behaviur){
    tilecol.setSize(sf::Vector2f(gridsize, gridsize));
    tilecol.setFillColor(col);
    tilecol.setPosition(sf::Vector2f(xtile*gridsize-boxposx, yrow*gridsize-boxposy));
    tilecol.setOrigin(sf::Vector2f(gridsize/2, gridsize/2));
    collision(xtile*gridsize-boxposx, yrow*gridsize-boxposy, gridsize, gridsize, behaviur);
    win.draw(tilecol);
}

void game::make_tile(int xtile, int yrow, string filename, int behaviur){
    if(!sprtiletex.loadFromFile("assets/sprite/"+filename+".png")) cout<<"TEXTURE for Tile '"<< xtile<<", "<<yrow<<"' called "<<"assets/sprite/"+filename+".png"<<"NOT FOUND!"<<endl;
    tilespr.setTexture(&sprtiletex);
    tilespr.setPosition(sf::Vector2f(xtile*gridsize, yrow*gridsize));
    tilespr.setOrigin(sf::Vector2f(gridsize/2, gridsize/2));
    collision(xtile*gridsize-boxposx, yrow*gridsize-boxposy, gridsize, gridsize, behaviur);
    win.draw(tilespr);
}
