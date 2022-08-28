#include "header/box.h"
#include "header/game.h"

box::box()
{
    //ctor
}

box::~box()
{
    //dtor
}

void box::main(int posX, int posY, int width, int height, sf::Color col, float charaposX){
    if(charaposX<300.f)posx=0.f; else posx=charaposX-300.f;
//    #ifdef devel
//    cout<<posx<<endl
//    #endif // devel
    rectbox.setFillColor(col); rectbox.setSize(sf::Vector2f(width, height));
    rectbox.setOrigin(sf::Vector2f(width/2, height/2));
    rectbox.setPosition(sf::Vector2f(posX-posx, posY));
}
