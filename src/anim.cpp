#include "header/anim.h"

anim::anim(int anmtype)
{
    this->anmtype=anmtype;
    switch(anmtype)
    {
        case 1:
            plrw0.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(2, 60, 18, 30));
            plrw1.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(22, 60, 18, 30));
            plrw2.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(42, 60, 18, 30));
            pllw0.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(2, 90, 18, 30));
            pllw1.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(22, 90, 18, 30));
            pllw2.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(42, 90, 18, 30));
            pluw0.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(2, 0, 18, 30));
            pluw1.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(22, 0, 18, 30));
            pluw2.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(42, 0, 18, 30));
            pldw0.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(2, 30, 18, 30));
            pldw1.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(22, 30, 18, 30));
            pldw2.loadFromFile("assets/sprite/playersheet.png", sf::IntRect(42, 30, 18, 30));
    }
}

anim::~anim()
{
    //dtor
}

void anim::player(sf::Sprite& spr, int id, double speed){
    timevar = clock.getElapsedTime().asSeconds();
    speed=5/speed;
    switch(id){
        case 1:
            if(timevar>0.4*speed) clock.restart();
            if(timevar>=0.1*speed) spr.setTexture(plrw0);
            if(timevar>=0.2*speed) spr.setTexture(plrw1);
            if(timevar>=0.3*speed) spr.setTexture(plrw0);
            if(timevar>=0.4*speed) spr.setTexture(plrw2);
            break;
        case 2:
            if(timevar>0.4*speed) clock.restart();
            if(timevar>=0.1*speed) spr.setTexture(pllw0);
            if(timevar>=0.2*speed) spr.setTexture(pllw1);
            if(timevar>=0.3*speed) spr.setTexture(pllw0);
            if(timevar>=0.4*speed) spr.setTexture(pllw2);
            break;
        case 3:
            if(timevar>0.4*speed) clock.restart();
            if(timevar>=0.1*speed) spr.setTexture(pldw0);
            if(timevar>=0.2*speed) spr.setTexture(pldw1);
            if(timevar>=0.3*speed) spr.setTexture(pldw0);
            if(timevar>=0.4*speed) spr.setTexture(pldw2);
            break;
        case 4:
            if(timevar>0.4*speed) clock.restart();
            if(timevar>=0.1*speed) spr.setTexture(pluw0);
            if(timevar>=0.2*speed) spr.setTexture(pluw1);
            if(timevar>=0.3*speed) spr.setTexture(pluw0);
            if(timevar>=0.4*speed) spr.setTexture(pluw2);
            break;
    }
}
