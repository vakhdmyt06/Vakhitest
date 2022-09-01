#include "header/game.h"
void game::make_box(int posX, int posY, int width, int height, sf::Color col, int behavior){
//    #ifdef devel
//    cout<<plbox.getPosition().x<<"  "<<boxposx<<endl;
//    #endif // devel
    rectbox.setFillColor(col); rectbox.setSize(sf::Vector2f(width, height));
    rectbox.setPosition(sf::Vector2f(posX-boxposx, posY-boxposy));
    collision(posX-boxposx, posY-boxposy, width, height, behavior);
    win.draw(rectbox);
}

void game::make_sprite(int posX, int posY, int width, int height, sf::Texture &texture, int behavior){
//    #ifdef devel
//    cout<<plbox.getPosition().x<<"  "<<boxposx<<endl;
//    #endif // devel
//    rectbox.setFillColor(col);
    sprbox.setScale(sf::Vector2f(width, height));
    sprbox.setPosition(sf::Vector2f(posX-boxposx-8*width, posY-boxposy-8*height));
    sprbox.setTexture(texture);
    win.draw(sprbox);
    collision(posX-boxposx-sprbox.getGlobalBounds().width/2, posY-boxposy-sprbox.getGlobalBounds().height/2, sprbox.getGlobalBounds().width, sprbox.getGlobalBounds().height, 1);
}
