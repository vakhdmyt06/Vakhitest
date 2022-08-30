#include "header/game.h"
void game::make_box(int posX, int posY, int width, int height, sf::Color col, int behavior){
    if(plxpos<300.f)boxposx=0.f; else boxposx=plxpos-300.f;
    boxposy=plypos;
//    #ifdef devel
//    cout<<plbox.getPosition().x<<"  "<<boxposx<<endl;
//    #endif // devel
    rectbox.setFillColor(col); rectbox.setSize(sf::Vector2f(width, height));
    rectbox.setOrigin(sf::Vector2f(width/2, height/2));
    rectbox.setPosition(sf::Vector2f(posX-boxposx, posY-boxposy));
    collision(posX-boxposx, posY-boxposy, width, height, behavior);
    win.draw(rectbox);
}

void game::make_sprite(int posX, int posY, int width, int height, int behavior){
    if(plxpos<300.f)boxposx=0.f; else boxposx=plxpos-300.f;
    boxposy=plypos;
//    #ifdef devel
//    cout<<plbox.getPosition().x<<"  "<<boxposx<<endl;
//    #endif // devel
//    rectbox.setFillColor(col);
    image_test.loadFromFile("assets/sprite/test.png");
    sprbox.setScale(sf::Vector2f(width, height));
    sprbox.setOrigin(sf::Vector2f(width/2, height/2));
    sprbox.setPosition(sf::Vector2f(posX-boxposx, posY-boxposy));
    sprbox.setTexture(image_test);
    win.draw(sprbox);
}
