#include "header/player.h"
#include "header/game.h"

player::player()
{
}

player::~player()
{
    //dtor

}
void player::main(int startX, int startY){
    input();
    xpos+=velocity;
    plbox();
}

void player::plbox(){

    box.setFillColor(sf::Color::Red); box.setSize(sf::Vector2f(40, 60)); box.setPosition(sf::Vector2f(startX+xpos, startY));
}

void player::input(){
    //hEEhEE
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){if(velocity>=0.f&&velocity<8.f) {velocity+=0.3f;} else velocity=8.f;} else if(velocity>0.f) velocity=0.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){if(velocity<=0.f&&velocity>-8.f) {velocity-=0.3f;} else velocity=-8.f;} else if(velocity<0.f) velocity=0.f;
    velprint.make(std::to_string(velocity),6, 30, 0);
}

void player::slep(int milliseconds, int mode){
    sf::Clock clock;clock.restart();timevar = 0;milliseconds--; while( timevar < milliseconds){ mode==1 ? timevar = clock.getElapsedTime().asSeconds() : timevar = clock.getElapsedTime().asMilliseconds(); }//cout << time << endl; }
}
